#pragma once

#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_td.h"
#include "sm_utils.h"

#define CASE_SMTD_TOM_SM_LAYOUTS(macro_key, uc_key, mod)      \
        case macro_key: {                                     \
            switch (action) {                                 \
                case SMTD_ACTION_TOUCH:                       \
                    break;                                    \
                case SMTD_ACTION_TAP:                         \
                    process_sm_layouts_tap(uc_key);           \
                    break;                                    \
                case SMTD_ACTION_HOLD:                        \
                    register_mods(MOD_BIT(mod));              \
                    break;                                    \
                case SMTD_ACTION_RELEASE:                     \
                    unregister_mods(MOD_BIT(mod));            \
                    break;                                    \
            }                                                 \
            break;                                            \
        }

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        case CKC_SPACE: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    if (is_caps_word_on()) {
                        switch (tap_count) {
                            case 0:
                                tap_code16(KC_UNDS);
                                return;
                            default:
                                caps_word_off();
                                tap_code16(KC_BSPC);
                                tap_code16(KC_SPACE);
                                return;
                        }
                    }

                    tap_code16(KC_SPACE);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) { LAYER_PUSH(L_NUM); }
                    else { SMTD_REGISTER_16(true, KC_SPACE); }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) { LAYER_RESTORE(); }
                    SMTD_UNREGISTER_16(true, KC_SPACE);
                    break;
            }
            break;
        }
        SMTD_LT(CKC_ESC, KC_ESC, L_NUM, 2)
        SMTD_LT(CKC_ENTER, KC_ENTER, L_FN, 2)
        SMTD_LT(CKC_TAB, KC_TAB, L_FN, 2)

        SMTD_MTE(CKC_A, KC_A, KC_LEFT_GUI, 2)
        SMTD_MTE(CKC_S, KC_S, KC_LEFT_ALT, 2)
        SMTD_MTE(CKC_D, KC_D, KC_LEFT_CTRL, 2)
        SMTD_MTE(CKC_F, KC_F, KC_LSFT, 2)
        SMTD_MTE(CKC_G, KC_G, KC_RIGHT_GUI, 2)
        SMTD_MTE(CKC_H, KC_H, KC_RIGHT_GUI, 2)
        SMTD_MTE(CKC_J, KC_J, KC_RSFT, 2)
        SMTD_MTE(CKC_K, KC_K, KC_RIGHT_CTRL, 2)
        SMTD_MTE(CKC_L, KC_L, KC_RIGHT_ALT, 2)

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

        SMTD_MT(CKC_4, KC_4, KC_LEFT_ALT, 2, false)
        SMTD_MT(CKC_5, KC_5, KC_LEFT_CTRL, 2, false)
        SMTD_MT(CKC_6, KC_6, KC_LEFT_SHIFT, 2, false)
        SMTD_MT(CKC_CIRC, KC_CIRC, KC_LCMD, 2, false)
        SMTD_MT(CKC_AT, KC_AT, KC_RIGHT_SHIFT, 2, false)
        SMTD_MT(CKC_HASH, KC_HASH, KC_RIGHT_CTRL, 2, false)

        SMTD_MT(CKC_F4, KC_F4, KC_LEFT_ALT, 2, false)
        SMTD_MT(CKC_F5, KC_F5, KC_LEFT_CTRL, 2, false)
        SMTD_MT(CKC_F6, KC_F6, KC_LEFT_SHIFT, 2, false)
        SMTD_MT(CKC_F11, KC_F11, KC_LEFT_GUI, 2, false)
        SMTD_MT(CKC_LEFT, KC_LEFT, KC_RIGHT_GUI, 2, false)
        SMTD_MT(CKC_DOWN, KC_DOWN, KC_RIGHT_SHIFT, 2, false)
        SMTD_MT(CKC_UP, KC_UP, KC_RIGHT_CTRL, 2, false)
        SMTD_MT(CKC_RIGHT, KC_RIGHT, KC_RIGHT_ALT, 2, false)
        SMTD_MT(CKC_VOLU, KC_VOLU, KC_RIGHT_GUI, 2, false)

        case CKC_DF_COMBO: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code16(KC_BSPC);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
                    } else {
                        register_code16(KC_BSPC);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
                    }
                    unregister_code16(KC_BSPC);
                    break;
            }
            break;
        }


        case CKC_NDOT: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
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
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        register_mods(MOD_BIT(KC_LCMD));
                    } else {
                        register_code16(KC_DOT);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        unregister_mods(MOD_BIT(KC_LCMD));
                    }
                    unregister_code16(KC_DOT);
                    break;
            }
            break;
        }
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        case CKC_F:
        case CKC_G:
        case CKC_H:
        case CKC_J:
        case CKC_CYR_A:
        case CKC_CYR_P:
        case CKC_CYR_R:
        case CKC_CYR_O:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 30;
            break;

        case CKC_D:
        case CKC_K:
        case CKC_CYR_V:
        case CKC_CYR_L:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_L:
        case CKC_S:
        case CKC_CYR_YI:
        case CKC_CYR_D:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_A:
        case CKC_CYR_F:
        case CKC_NDOT:
        case CKC_CYR_ZH:
        case CKC_DF_COMBO:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_SPACE:
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 200;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 70;
            break;
    }

    return get_smtd_timeout_default(timeout);
}

#ifdef SMTD_DEBUG_ENABLED
char* keycode_to_string_user(uint16_t keycode) {
    switch (keycode) {
    case M_SCRN: return "M_SCRN";
    case M_QUE: return "M_QUE";
    case M_EURO: return "M_EURO";
    case M_RUB: return "M_RUB";
    case SMTD_KEYCODES_BEGIN: return "SMTD_KEYCODES_BEGIN";
    case CKC_DF_COMBO: return "CKC_DF_COMBO";
    case CKC_SPACE: return "CKC_SPACE";
    case CKC_ENTER: return "CKC_ENTER";
    case CKC_ESC: return "CKC_ESC";
    case CKC_TAB: return "CKC_TAB";
    case CKC_A: return "CKC_A";
    case CKC_S: return "CKC_S";
    case CKC_D: return "CKC_D";
    case CKC_F: return "CKC_F";
    case CKC_G: return "CKC_G";
    case CKC_H: return "CKC_H";
    case CKC_J: return "CKC_J";
    case CKC_K: return "CKC_K";
    case CKC_L: return "CKC_L";
    case CKC_CYR_F: return "CKC_CYR_F";
    case CKC_CYR_YI: return "CKC_CYR_YI";
    case CKC_CYR_V: return "CKC_CYR_V";
    case CKC_CYR_A: return "CKC_CYR_A";
    case CKC_CYR_P: return "CKC_CYR_P";
    case CKC_CYR_R: return "CKC_CYR_R";
    case CKC_CYR_O: return "CKC_CYR_O";
    case CKC_CYR_L: return "CKC_CYR_L";
    case CKC_CYR_D: return "CKC_CYR_D";
    case CKC_CYR_ZH: return "CKC_CYR_ZH";
    case CKC_NDOT: return "CKC_NDOT";
    case CKC_4: return "CKC_4";
    case CKC_5: return "CKC_5";
    case CKC_6: return "CKC_6";
    case CKC_CIRC: return "CKC_CIRC";
    case CKC_AT: return "CKC_AT";
    case CKC_HASH: return "CKC_HASH";
    case CKC_F4: return "CKC_F4";
    case CKC_F5: return "CKC_F5";
    case CKC_F6: return "CKC_F6";
    case CKC_F11: return "CKC_F11";
    case CKC_LEFT: return "CKC_LEFT";
    case CKC_DOWN: return "CKC_DOWN";
    case CKC_UP: return "CKC_UP";
    case CKC_RIGHT: return "CKC_RIGHT";
    case CKC_VOLU: return "CKC_VOLU";
    case SMTD_KEYCODES_END: return "SMTD_KEYCODES_END";
    case M_EMPTY1: return "M_EMPTY1";
    case M_EMPTY2: return "M_EMPTY2";
    case CYR_YY: return "CYR_YY";
    case CYR_CC: return "CYR_CC";
    case CYR_U: return "CYR_U";
    case CYR_K: return "CYR_K";
    case CYR_E: return "CYR_E";
    case CYR_F: return "CYR_F";
    case CYR_YI: return "CYR_YI";
    case CYR_V: return "CYR_V";
    case CYR_A: return "CYR_A";
    case CYR_P: return "CYR_P";
    case CYR_YA: return "CYR_YA";
    case CYR_CH: return "CYR_CH";
    case CYR_SS: return "CYR_SS";
    case CYR_M: return "CYR_M";
    case CYR_I: return "CYR_I";
    case CYR_N: return "CYR_N";
    case CYR_G: return "CYR_G";
    case CYR_SH: return "CYR_SH";
    case CYR_SCH: return "CYR_SCH";
    case CYR_ZZ: return "CYR_ZZ";
    case CYR_H: return "CYR_H";
    case CYR_R: return "CYR_R";
    case CYR_O: return "CYR_O";
    case CYR_YO: return "CYR_YO";
    case CYR_L: return "CYR_L";
    case CYR_D: return "CYR_D";
    case CYR_YE: return "CYR_YE";
    case CYR_T: return "CYR_T";
    case CYR_SFT: return "CYR_SFT";
    case CYR_B: return "CYR_B";
    case CYR_YU: return "CYR_YU";
    case CYR_ZH: return "CYR_ZH";
    case CYR_SLD: return "CYR_SLD";
    }

    return NULL;
}
#endif
