#pragma once

#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_layouts.h"
#include "sm_utils.h"
#include "sm_td.h"

// --- Hyper+F one-shot to L_EN ---------------------------------------------
// Type a single Latin char from the Russian layer, then return. Triggered from
// the CKC_CYR_A (F position) tap while Hyper is held; see on_smtd_action below.
// The window closes on the first key after the trigger (that key types on L_EN)
// or after 5s, whichever comes first.
static bool           en_osl_active    = false;
static bool           en_osl_finalized = false;
static uint8_t        en_osl_saved     = 0;
static keypos_t       en_osl_key;
static deferred_token en_osl_token     = INVALID_DEFERRED_TOKEN;

static uint32_t en_osl_timeout(uint32_t trigger_time, void *arg) {
    if (en_osl_active) {
        layer_move(en_osl_saved);
        en_osl_active = false;
    }
    return 0;
}

static void en_osl_start(void) {
    uint8_t cur = get_highest_layer(layer_state);
    if (cur == L_EN) return; // already English — nothing to do
    if (en_osl_active) {
        cancel_deferred_exec(en_osl_token); // re-trigger: keep saved layer, refresh window
    } else {
        en_osl_saved = cur;
    }
    layer_move(L_EN);
    en_osl_active    = true;
    en_osl_finalized = false;
    en_osl_token     = defer_exec(5000, en_osl_timeout, NULL);
}

// Call from pre_process_record_user for every physical key.
static void en_osl_pre_process(keyrecord_t *record) {
    if (!en_osl_active) return;
    if (record->event.pressed) {
        if (!en_osl_finalized) {
            en_osl_finalized = true;
            en_osl_key       = record->event.key;
        }
    } else if (en_osl_finalized &&
               record->event.key.row == en_osl_key.row &&
               record->event.key.col == en_osl_key.col) {
        cancel_deferred_exec(en_osl_token);
        layer_move(en_osl_saved);
        en_osl_active = false;
    }
}

// tap=uc_key, hold=mod
#define CASE_SMTD_TOM_SM_LAYOUTS(macro_key, uc_key, mod_key) CASE_SMTD_TOMB_SM_LAYOUTS(macro_key, uc_key, MOD_BIT(mod_key))
#define CASE_SMTD_TOMB_SM_LAYOUTS(macro_key, uc_key, mods) \
    case macro_key: {                                      \
        switch (action) {                                  \
            case SMTD_ACTION_TOUCH:                        \
                return SMTD_RESOLUTION_UNCERTAIN;          \
            case SMTD_ACTION_TAP:                          \
                process_sm_layouts_tap(uc_key);            \
                return SMTD_RESOLUTION_DETERMINED;         \
            case SMTD_ACTION_HOLD:                         \
                register_mods(mods);                       \
                return SMTD_RESOLUTION_DETERMINED;         \
            case SMTD_ACTION_RELEASE:                      \
                unregister_mods(mods);                     \
                return SMTD_RESOLUTION_DETERMINED;         \
        }                                                  \
        break;                                             \
    }

// tap=uc_key1, dtap=bksp+uc_key2, triple=bksp+uc_key1, ... (alternating)
// hold=uc_key1 repeat, tap-hold=uc_key2 repeat
#define CASE_SMTD_DUAL_SM_LAYOUTS(macro_key, uc_key1, uc_key2) \
    case macro_key: {                                          \
        switch (action) {                                      \
            case SMTD_ACTION_TOUCH:                            \
                return SMTD_RESOLUTION_UNCERTAIN;              \
            case SMTD_ACTION_TAP:                              \
                if (tap_count > 0) {                           \
                    tap_code16(KC_BSPC);                       \
                }                                              \
                if (tap_count % 2 == 0) {                      \
                    process_sm_layouts_tap(uc_key1);           \
                } else {                                       \
                    process_sm_layouts_tap(uc_key2);           \
                }                                              \
                return SMTD_RESOLUTION_DETERMINED;             \
            case SMTD_ACTION_HOLD:                             \
                if (tap_count % 2 == 0) {                      \
                    process_sm_layouts_tap(uc_key1);           \
                } else {                                       \
                    process_sm_layouts_tap(uc_key2);           \
                }                                              \
                return SMTD_RESOLUTION_DETERMINED;             \
            case SMTD_ACTION_RELEASE:                          \
                return SMTD_RESOLUTION_DETERMINED;             \
        }                                                      \
        break;                                                 \
    }

// tap=uc_key1, dtap=bksp+uc_key2, triple=bksp+uc_key1, ... (alternating)
// hold=mod
#define CASE_SMTD_DUAL_MOD_SM_LAYOUTS(macro_key, uc_key1, uc_key2, mods) \
    case macro_key: {                                                    \
        switch (action) {                                                \
            case SMTD_ACTION_TOUCH:                                      \
                return SMTD_RESOLUTION_UNCERTAIN;                        \
            case SMTD_ACTION_TAP:                                        \
                if (tap_count > 0) {                                     \
                    tap_code16(KC_BSPC);                                 \
                }                                                        \
                if (tap_count % 2 == 0) {                                \
                    process_sm_layouts_tap(uc_key1);                     \
                } else {                                                 \
                    process_sm_layouts_tap(uc_key2);                     \
                }                                                        \
                return SMTD_RESOLUTION_DETERMINED;                       \
            case SMTD_ACTION_HOLD:                                       \
                register_mods(mods);                                     \
                return SMTD_RESOLUTION_DETERMINED;                       \
            case SMTD_ACTION_RELEASE:                                    \
                unregister_mods(mods);                                   \
                return SMTD_RESOLUTION_DETERMINED;                       \
        }                                                                \
        break;                                                           \
    }

// tap=uc_key1, hold=uc_key2 (single output, not repeat)
#define CASE_SMTD_TAP_HOLD_SM_LAYOUTS(macro_key, uc_key_tap, uc_key_hold) \
    case macro_key: {                                                     \
        switch (action) {                                                 \
            case SMTD_ACTION_TOUCH:                                       \
                return SMTD_RESOLUTION_UNCERTAIN;                         \
            case SMTD_ACTION_TAP:                                         \
                process_sm_layouts_tap(uc_key_tap);                       \
                return SMTD_RESOLUTION_DETERMINED;                        \
            case SMTD_ACTION_HOLD:                                        \
                process_sm_layouts_tap(uc_key_hold);                      \
                return SMTD_RESOLUTION_DETERMINED;                        \
            case SMTD_ACTION_RELEASE:                                     \
                return SMTD_RESOLUTION_DETERMINED;                        \
        }                                                                 \
        break;                                                            \
    }

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    // Keep QMK's repeat key tracking in sync with SMTD-resolved taps
    if (action == SMTD_ACTION_TAP && keycode != QK_REP) {
        set_last_keycode(keycode);
        set_last_mods(0);
    }

    switch (keycode) {
        case QK_REP: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP: {
                    uint16_t last = get_last_keycode();
                    if (last != KC_NO && last != QK_REP) {
                        on_smtd_action(last, SMTD_ACTION_TAP, 0);
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                }
                case SMTD_ACTION_HOLD:
                    // QK_REP took over the thumb key that used to be KC_ESC, so it
                    // inherits its L_NUM hold. L_FN stays on KC_TAB and KC_ENTER.
                    if (tap_count < 2) {
                        layer_on(L_NUM);
                    } else {
                        uint16_t last = get_last_keycode();
                        if (last != KC_NO && last != QK_REP) {
                            SMTD_REGISTER_16(true, last);
                        }
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        layer_off(L_NUM);
                    }
                    SMTD_UNREGISTER_16(true, get_last_keycode());
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }

        case KC_SPACE: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP:
                    if (is_caps_word_on()) {
                        switch (tap_count) {
                            case 0:
                                tap_code16(KC_UNDS);
                                return SMTD_RESOLUTION_DETERMINED;
                            default:
                                caps_word_off();
                                tap_code16(KC_BSPC);
                                tap_code16(KC_SPACE);
                                return SMTD_RESOLUTION_DETERMINED;
                        }
                    }

                    tap_code16(KC_SPACE);
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        layer_on(L_NUM);
                    } else {
                        SMTD_REGISTER_16(true, KC_SPACE);
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        layer_off(L_NUM);
                    }
                    SMTD_UNREGISTER_16(true, KC_SPACE);
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }

        case M_SPFY_NEXT: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP:
                    // The first tap seeks immediately instead of waiting to see
                    // whether a second one follows: a second tap skips the whole
                    // track, which supersedes the seek, so there is nothing to undo.
                    tap_code16(tap_count == 0 ? SPFY_SEEK : SPFY_NEXT);
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_HOLD:
                case SMTD_ACTION_RELEASE:
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }

            SMTD_LT(KC_ENTER, L_FN, 2)
            SMTD_LT(KC_TAB, L_FN, 2)

            SMTD_MBTE5_ON_MKEY(M_EMPTY3, KC_NO, MOD_HYPR, 1, true)
            SMTD_MT(KC_Z, KC_RCMD, 2)
            SMTD_MT(KC_A, KC_LEFT_GUI, 2)
            SMTD_MT(KC_S, KC_LEFT_ALT, 2)
            SMTD_MT(KC_D, KC_LEFT_CTRL, 2)
            SMTD_MT(KC_F, KC_LSFT, 2)
            SMTD_MT(KC_G, KC_RIGHT_GUI, 2)
            SMTD_MT(KC_H, KC_RIGHT_GUI, 2)
            SMTD_MT(KC_J, KC_RSFT, 2)
            SMTD_MT(KC_K, KC_RIGHT_CTRL, 2)
            SMTD_MT(KC_L, KC_RIGHT_ALT, 2)

            CASE_SMTD_TOMB_SM_LAYOUTS(CYR_ZH, CYR_ZH, MOD_HYPR)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_F, CYR_F, KC_LEFT_GUI)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_YI, CYR_YI, KC_LEFT_ALT)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_V, CYR_V, KC_LEFT_CTRL)
        case CKC_CYR_A: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP:
                    // Always emit the tap: on L_RU this sends the KC_F scancode, so
                    // with Hyper held the OS still receives the Hyper+F hotkey.
                    process_sm_layouts_tap(CYR_A);
                    // If it was Hyper+F on the Russian layer, also flip the board to
                    // L_EN for one keystroke so it follows the OS layout switch.
                    if ((get_mods() & MOD_HYPR) == MOD_HYPR) {
                        en_osl_start();
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_HOLD:
                    register_mods(MOD_BIT(KC_LEFT_SHIFT));
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_SHIFT));
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_P, CYR_P, KC_RIGHT_GUI)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_R, CYR_R, KC_RIGHT_GUI)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_O, CYR_O, KC_RIGHT_SHIFT)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_L, CYR_L, KC_RIGHT_CTRL)
            CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_D, CYR_D, KC_RIGHT_ALT)
            CASE_SMTD_DUAL_MOD_SM_LAYOUTS(CKC_CYR_YA_YE, CYR_YA, CYR_YE, MOD_BIT(KC_RIGHT_GUI))
            CASE_SMTD_TAP_HOLD_SM_LAYOUTS(CKC_CYR_E_YO, CYR_E, CYR_YO)
            CASE_SMTD_DUAL_SM_LAYOUTS(CKC_CYR_SFT_SLD, CYR_SFT, CYR_SLD)

            SMTD_MT(KC_4, KC_LEFT_ALT, 2, false)
            SMTD_MT(KC_5, KC_LEFT_CTRL, 2, false)
            SMTD_MT(KC_6, KC_LEFT_SHIFT, 2, false)
            SMTD_MT(KC_CIRC, KC_LCMD, 2, false)
            SMTD_MT(KC_AT, KC_RIGHT_SHIFT, 2, false)
            SMTD_MT(KC_HASH, KC_RIGHT_CTRL, 2, false)

            SMTD_MT(KC_F4, KC_LEFT_ALT, 2, false)
            SMTD_MT(KC_F5, KC_LEFT_CTRL, 2, false)
            SMTD_MT(KC_F6, KC_LEFT_SHIFT, 2, false)
            SMTD_MT(KC_F11, KC_LEFT_GUI, 2, false)
            SMTD_MT(KC_LEFT, KC_RIGHT_GUI, 2, false)
            SMTD_MT(KC_DOWN, KC_RIGHT_SHIFT, 2, false)
            SMTD_MT(KC_UP, KC_RIGHT_CTRL, 2, false)
            SMTD_MT(KC_RIGHT, KC_RIGHT_ALT, 2, false)
            SMTD_MT(KC_VOLU, KC_RIGHT_GUI, 2, false)

        case CKC_DF_COMBO: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP:
                    tap_code16(KC_BSPC);
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
                    } else {
                        register_code16(KC_BSPC);
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
                    }
                    unregister_code16(KC_BSPC);
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }

        case KC_DOT: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    return SMTD_RESOLUTION_UNCERTAIN;
                case SMTD_ACTION_TAP:
                    switch (tap_count) {
                        case 0:
                            tap_code16(KC_DOT);
                            break;
                        case 1:
                            tap_code16(KC_BSPC);
                            tap_code16(KC_COLN);
                            break;
                        case 2:
                            tap_code16(KC_BSPC);
                            tap_code16(KC_DOT);
                            tap_code16(KC_DOT);
                            tap_code16(KC_DOT);
                            break;
                        default:
                            tap_code16(KC_DOT);
                            break;
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        register_mods(MOD_BIT(KC_LCMD));
                    } else {
                        register_code16(KC_DOT);
                    }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        unregister_mods(MOD_BIT(KC_LCMD));
                    }
                    unregister_code16(KC_DOT);
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }
    }

    return SMTD_RESOLUTION_UNHANDLED;
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        // Double-tap window for seek/next. The default (TAPPING_TERM / 2 = 100ms)
        // is too tight to hit reliably on a layer key you press deliberately.
        case M_SPFY_NEXT:
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 300;
            break;

        case KC_F:
        case KC_G:
        case KC_H:
        case KC_J:
        case CKC_CYR_A:
        case CKC_CYR_P:
        case CKC_CYR_R:
        case CKC_CYR_O:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 30;
            break;

        case KC_D:
        case KC_K:
        case CKC_CYR_V:
        case CKC_CYR_L:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case KC_L:
        case KC_S:
        case CKC_CYR_YI:
        case CKC_CYR_D:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case KC_Z:
        case CYR_ZH:
        case KC_A:
        case KC_DOT:
        case CKC_CYR_F:
        case CKC_CYR_YA_YE:
        case CKC_DF_COMBO:
        case M_EMPTY3:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_CYR_E_YO:
        case CKC_CYR_SFT_SLD:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case KC_SPACE:
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 200;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 70;
            break;
    }

    return get_smtd_timeout_default(timeout);
}

#ifdef SMTD_DEBUG_ENABLED
char *smtd_keycode_to_str_user(uint16_t keycode) {
    switch (keycode) {
        case CKC_CYR_A:
            return "CKC_CYR_A";
        case CYR_ZH:
            return "CYR_ZH";
        case CKC_CYR_D:
            return "CKC_CYR_D";
        case CKC_CYR_E_YO:
            return "CKC_CYR_E_YO";
        case CKC_CYR_F:
            return "CKC_CYR_F";

        case CKC_CYR_L:
            return "CKC_CYR_L";
        case CKC_CYR_O:
            return "CKC_CYR_O";
        case CKC_CYR_P:
            return "CKC_CYR_P";
        case CKC_CYR_R:
            return "CKC_CYR_R";
        case CKC_CYR_SFT_SLD:
            return "CKC_CYR_SFT_SLD";
        case CKC_CYR_V:
            return "CKC_CYR_V";
        case CKC_CYR_YA_YE:
            return "CKC_CYR_YA_YE";
        case CKC_CYR_YI:
            return "CKC_CYR_YI";

        case CYR_A:
            return "CYR_A";
        case CYR_B:
            return "CYR_B";
        case CYR_CC:
            return "CYR_CC";
        case CYR_CH:
            return "CYR_CH";
        case CYR_D:
            return "CYR_D";
        case CYR_E:
            return "CYR_E";
        case CYR_F:
            return "CYR_F";
        case CYR_G:
            return "CYR_G";
        case CYR_H:
            return "CYR_H";
        case CYR_I:
            return "CYR_I";
        case CYR_K:
            return "CYR_K";
        case CYR_L:
            return "CYR_L";
        case CYR_M:
            return "CYR_M";
        case CYR_N:
            return "CYR_N";
        case CYR_O:
            return "CYR_O";
        case CYR_P:
            return "CYR_P";
        case CYR_R:
            return "CYR_R";
        case CYR_SCH:
            return "CYR_SCH";
        case CYR_SFT:
            return "CYR_SFT";
        case CYR_SH:
            return "CYR_SH";
        case CYR_SLD:
            return "CYR_SLD";
        case CYR_SS:
            return "CYR_SS";
        case CYR_T:
            return "CYR_T";
        case CYR_U:
            return "CYR_U";
        case CYR_V:
            return "CYR_V";
        case CYR_YA:
            return "CYR_YA";
        case CYR_YE:
            return "CYR_YE";
        case CYR_YI:
            return "CYR_YI";
        case CYR_YU:
            return "CYR_YU";
        case CYR_YY:
            return "CYR_YY";
        case CYR_ZH:
            return "CYR_ZH";
        case CYR_ZZ:
            return "CYR_ZZ";
        case KC_0:
            return "KC_0";
        case KC_1:
            return "KC_1";
        case KC_2:
            return "KC_2";
        case KC_3:
            return "KC_3";
        case KC_4:
            return "KC_4";
        case KC_5:
            return "KC_5";
        case KC_6:
            return "KC_6";
        case KC_7:
            return "KC_7";
        case KC_8:
            return "KC_8";
        case KC_9:
            return "KC_9";
        case KC_A:
            return "KC_A";
        case KC_AMPR:
            return "KC_AMPR";
        case KC_AT:
            return "KC_AT";
        case KC_B:
            return "KC_B";
        case KC_C:
            return "KC_C";
        case KC_CIRC:
            return "KC_CIRC";
        case KC_D:
            return "KC_D";
        case KC_DLR:
            return "KC_DLR";
        case KC_DOT:
            return "KC_DOT";
        case KC_DOWN:
            return "KC_DOWN";
        case KC_E:
            return "KC_E";
        case KC_END:
            return "KC_END";
        case KC_ENTER:
            return "KC_ENTER";
        case KC_ESC:
            return "KC_ESC";
        case KC_F:
            return "KC_F";
        case KC_F1:
            return "KC_F1";
        case KC_F10:
            return "KC_F10";
        case KC_F11:
            return "KC_F11";
        case KC_F12:
            return "KC_F12";
        case KC_F2:
            return "KC_F2";
        case KC_F3:
            return "KC_F3";
        case KC_F4:
            return "KC_F4";
        case KC_F5:
            return "KC_F5";
        case KC_F6:
            return "KC_F6";
        case KC_F7:
            return "KC_F7";
        case KC_F8:
            return "KC_F8";
        case KC_F9:
            return "KC_F9";
        case KC_G:
            return "KC_G";
        case KC_H:
            return "KC_H";
        case KC_HASH:
            return "KC_HASH";
        case KC_HOME:
            return "KC_HOME";
        case KC_I:
            return "KC_I";
        case KC_J:
            return "KC_J";
        case KC_K:
            return "KC_K";
        case KC_L:
            return "KC_L";
        case KC_LCTL:
            return "KC_LCTL";
        case KC_LEFT:
            return "KC_LEFT";
        case KC_LGUI:
            return "KC_LGUI";
        case KC_LOPT:
            return "KC_LOPT";
        case KC_LSFT:
            return "KC_LSFT";
        case KC_M:
            return "KC_M";
        case KC_MNXT:
            return "KC_MNXT";
        case KC_MPLY:
            return "KC_MPLY";
        case KC_MPRV:
            return "KC_MPRV";
        case KC_N:
            return "KC_N";
        case KC_O:
            return "KC_O";
        case KC_P:
            return "KC_P";
        case KC_PERC:
            return "KC_PERC";
        case KC_PGDN:
            return "KC_PGDN";
        case KC_PGUP:
            return "KC_PGUP";
        case KC_PIPE:
            return "KC_PIPE";
        case KC_Q:
            return "KC_Q";
        case KC_R:
            return "KC_R";
        case KC_RCMD:
            return "KC_RCMD";
        case KC_RIGHT:
            return "KC_RIGHT";
        case KC_ROPT:
            return "KC_ROPT";
        case KC_S:
            return "KC_S";
        case KC_SPACE:
            return "KC_SPACE";
        case KC_T:
            return "KC_T";
        case KC_TAB:
            return "KC_TAB";
        case QK_REP:
            return "QK_REP";
        case KC_TILD:
            return "KC_TILD";
        case KC_U:
            return "KC_U";
        case KC_UP:
            return "KC_UP";
        case KC_V:
            return "KC_V";
        case KC_VOLD:
            return "KC_VOLD";
        case KC_VOLU:
            return "KC_VOLU";
        case KC_W:
            return "KC_W";
        case KC_X:
            return "KC_X";
        case KC_Y:
            return "KC_Y";
        case KC_Z:
            return "KC_Z";
        case M_EMPTY1:
            return "M_EMPTY1";
        case M_EMPTY2:
            return "M_EMPTY2";
        case M_EMPTY3:
            return "M_EMPTY3";
        case M_SPFY_NEXT:
            return "M_SPFY_NEXT";
        case M_EURO:
            return "M_EURO";
        case M_QUE:
            return "M_QUE";
        case M_RUB:
            return "M_RUB";
        case M_SCRN:
            return "M_SCRN";
    }

    // fixme
    // cyrillic layer hotkeys stuck (sometimes doesnt press, sometimes not release)

    return "KC_???";
}
#endif
