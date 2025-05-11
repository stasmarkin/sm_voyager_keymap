#pragma once

#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_utils.h"
#include "sm_td.h"

#define CASE_SMTD_TOM_SM_LAYOUTS(macro_key, uc_key, mod)      \
        case macro_key: {                                     \
            switch (action) {                                 \
                case SMTD_ACTION_TOUCH:                       \
                    return SMTD_RESOLUTION_UNCERTAIN;         \
                case SMTD_ACTION_TAP:                         \
                    process_sm_layouts_tap(uc_key);           \
                    return SMTD_RESOLUTION_DETERMINED;        \
                case SMTD_ACTION_HOLD:                        \
                    register_mods(MOD_BIT(mod));              \
                    return SMTD_RESOLUTION_DETERMINED;        \
                case SMTD_ACTION_RELEASE:                     \
                    unregister_mods(MOD_BIT(mod));            \
                    return SMTD_RESOLUTION_DETERMINED;        \
            }                                                 \
            break;                                            \
        }

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
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
                    if (tap_count < 2) { LAYER_PUSH(L_NUM); }
                    else { SMTD_REGISTER_16(true, KC_SPACE); }
                    return SMTD_RESOLUTION_DETERMINED;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) { LAYER_RESTORE(); }
                    SMTD_UNREGISTER_16(true, KC_SPACE);
                    return SMTD_RESOLUTION_DETERMINED;
            }
            break;
        }

        SMTD_LT(KC_ESC, L_NUM, 2)
        SMTD_LT(KC_ENTER, L_FN, 2)
        SMTD_LT(KC_TAB, L_FN, 2)

        SMTD_MTE(KC_A, KC_LEFT_GUI, 2)
        SMTD_MTE(KC_S, KC_LEFT_ALT, 2)
        SMTD_MTE(KC_D, KC_LEFT_CTRL, 2)
        SMTD_MTE(KC_F, KC_LSFT, 2)
        SMTD_MTE(KC_G, KC_RIGHT_GUI, 2)
        SMTD_MTE(KC_H, KC_RIGHT_GUI, 2)
        SMTD_MTE(KC_J, KC_RSFT, 2)
        SMTD_MTE(KC_K, KC_RIGHT_CTRL, 2)
        SMTD_MTE(KC_L, KC_RIGHT_ALT, 2)

        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_F, CYR_F, KC_LEFT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_YI, CYR_YI, KC_LEFT_ALT)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_V, CYR_V, KC_LEFT_CTRL)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_A, CYR_A, KC_LEFT_SHIFT)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_P, CYR_P, KC_RIGHT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_R, CYR_R, KC_RIGHT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_O, CYR_O, KC_RIGHT_SHIFT)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_L, CYR_L, KC_RIGHT_CTRL)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_D, CYR_D, KC_RIGHT_ALT)
        CASE_SMTD_TOM_SM_LAYOUTS(CKC_CYR_ZH, CYR_ZH, KC_RIGHT_GUI)

        SMTD_MTE(KC_4, KC_LEFT_ALT, 2, false)
        SMTD_MTE(KC_5, KC_LEFT_CTRL, 2, false)
        SMTD_MTE(KC_6, KC_LEFT_SHIFT, 2, false)
        SMTD_MTE(KC_CIRC, KC_LCMD, 2, false)
        SMTD_MTE(KC_AT, KC_RIGHT_SHIFT, 2, false)
        SMTD_MTE(KC_HASH, KC_RIGHT_CTRL, 2, false)

        SMTD_MTE(KC_F4, KC_LEFT_ALT, 2, false)
        SMTD_MTE(KC_F5, KC_LEFT_CTRL, 2, false)
        SMTD_MTE(KC_F6, KC_LEFT_SHIFT, 2, false)
        SMTD_MTE(KC_F11, KC_LEFT_GUI, 2, false)
        SMTD_MTE(KC_LEFT, KC_RIGHT_GUI, 2, false)
        SMTD_MTE(KC_DOWN, KC_RIGHT_SHIFT, 2, false)
        SMTD_MTE(KC_UP, KC_RIGHT_CTRL, 2, false)
        SMTD_MTE(KC_RIGHT, KC_RIGHT_ALT, 2, false)
        SMTD_MTE(KC_VOLU, KC_RIGHT_GUI, 2, false)

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

        case KC_A:
        case KC_DOT:
        case CKC_CYR_F:
        case CKC_CYR_ZH:
        case CKC_DF_COMBO:
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
char* smtd_keycode_to_str_user(uint16_t keycode) {
    switch (keycode) {
        case CKC_CYR_A: return "CKC_CYR_A";
        case CKC_CYR_D: return "CKC_CYR_D";
        case CKC_CYR_F: return "CKC_CYR_F";
        case CKC_CYR_L: return "CKC_CYR_L";
        case CKC_CYR_O: return "CKC_CYR_O";
        case CKC_CYR_P: return "CKC_CYR_P";
        case CKC_CYR_R: return "CKC_CYR_R";
        case CKC_CYR_V: return "CKC_CYR_V";
        case CKC_CYR_YI: return "CKC_CYR_YI";
        case CKC_CYR_ZH: return "CKC_CYR_ZH";
        case CYR_A: return "CYR_A";
        case CYR_B: return "CYR_B";
        case CYR_CC: return "CYR_CC";
        case CYR_CH: return "CYR_CH";
        case CYR_D: return "CYR_D";
        case CYR_E: return "CYR_E";
        case CYR_F: return "CYR_F";
        case CYR_G: return "CYR_G";
        case CYR_H: return "CYR_H";
        case CYR_I: return "CYR_I";
        case CYR_K: return "CYR_K";
        case CYR_L: return "CYR_L";
        case CYR_M: return "CYR_M";
        case CYR_N: return "CYR_N";
        case CYR_O: return "CYR_O";
        case CYR_P: return "CYR_P";
        case CYR_R: return "CYR_R";
        case CYR_SCH: return "CYR_SCH";
        case CYR_SFT: return "CYR_SFT";
        case CYR_SH: return "CYR_SH";
        case CYR_SLD: return "CYR_SLD";
        case CYR_SS: return "CYR_SS";
        case CYR_T: return "CYR_T";
        case CYR_U: return "CYR_U";
        case CYR_V: return "CYR_V";
        case CYR_YA: return "CYR_YA";
        case CYR_YE: return "CYR_YE";
        case CYR_YI: return "CYR_YI";
        case CYR_YU: return "CYR_YU";
        case CYR_YY: return "CYR_YY";
        case CYR_ZH: return "CYR_ZH";
        case CYR_ZZ: return "CYR_ZZ";
        case KC_0: return "KC_0";
        case KC_1: return "KC_1";
        case KC_2: return "KC_2";
        case KC_3: return "KC_3";
        case KC_4: return "KC_4";
        case KC_5: return "KC_5";
        case KC_6: return "KC_6";
        case KC_7: return "KC_7";
        case KC_8: return "KC_8";
        case KC_9: return "KC_9";
        case KC_A: return "KC_A";
        case KC_AMPR: return "KC_AMPR";
        case KC_AT: return "KC_AT";
        case KC_B: return "KC_B";
        case KC_C: return "KC_C";
        case KC_CIRC: return "KC_CIRC";
        case KC_D: return "KC_D";
        case KC_DLR: return "KC_DLR";
        case KC_DOT: return "KC_DOT";
        case KC_DOWN: return "KC_DOWN";
        case KC_E: return "KC_E";
        case KC_END: return "KC_END";
        case KC_ENTER: return "KC_ENTER";
        case KC_ESC: return "KC_ESC";
        case KC_F: return "KC_F";
        case KC_F1: return "KC_F1";
        case KC_F10: return "KC_F10";
        case KC_F11: return "KC_F11";
        case KC_F12: return "KC_F12";
        case KC_F2: return "KC_F2";
        case KC_F3: return "KC_F3";
        case KC_F4: return "KC_F4";
        case KC_F5: return "KC_F5";
        case KC_F6: return "KC_F6";
        case KC_F7: return "KC_F7";
        case KC_F8: return "KC_F8";
        case KC_F9: return "KC_F9";
        case KC_G: return "KC_G";
        case KC_H: return "KC_H";
        case KC_HASH: return "KC_HASH";
        case KC_HOME: return "KC_HOME";
        case KC_I: return "KC_I";
        case KC_J: return "KC_J";
        case KC_K: return "KC_K";
        case KC_L: return "KC_L";
        case KC_LCTL: return "KC_LCTL";
        case KC_LEFT: return "KC_LEFT";
        case KC_LGUI: return "KC_LGUI";
        case KC_LOPT: return "KC_LOPT";
        case KC_LSFT: return "KC_LSFT";
        case KC_M: return "KC_M";
        case KC_MNXT: return "KC_MNXT";
        case KC_MPLY: return "KC_MPLY";
        case KC_MPRV: return "KC_MPRV";
        case KC_N: return "KC_N";
        case KC_O: return "KC_O";
        case KC_P: return "KC_P";
        case KC_PERC: return "KC_PERC";
        case KC_PGDN: return "KC_PGDN";
        case KC_PGUP: return "KC_PGUP";
        case KC_PIPE: return "KC_PIPE";
        case KC_Q: return "KC_Q";
        case KC_R: return "KC_R";
        case KC_RCMD: return "KC_RCMD";
        case KC_RIGHT: return "KC_RIGHT";
        case KC_ROPT: return "KC_ROPT";
        case KC_S: return "KC_S";
        case KC_SPACE: return "KC_SPACE";
        case KC_T: return "KC_T";
        case KC_TAB: return "KC_TAB";
        case KC_TILD: return "KC_TILD";
        case KC_U: return "KC_U";
        case KC_UP: return "KC_UP";
        case KC_V: return "KC_V";
        case KC_VOLD: return "KC_VOLD";
        case KC_VOLU: return "KC_VOLU";
        case KC_W: return "KC_W";
        case KC_X: return "KC_X";
        case KC_Y: return "KC_Y";
        case KC_Z: return "KC_Z";
        case M_EMPTY1: return "M_EMPTY1";
        case M_EMPTY2: return "M_EMPTY2";
        case M_EURO: return "M_EURO";
        case M_QUE: return "M_QUE";
        case M_RUB: return "M_RUB";
        case M_SCRN: return "M_SCRN";
    }

    // fixme
    // cyrillic layer hotkeys stuck (sometimes doesnt press, sometimes not release)

    return "KC_???";
}
#endif
