#pragma once

#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_td.h"
#include "sm_utils.h"

#define CASE_SMTD_TOM(macro_key, tap_key, mod, threshold)         \
        case macro_key: {                                         \
            switch (action) {                                     \
                case SMTD_ACTION_TOUCH:                           \
                    break;                                        \
                case SMTD_ACTION_TAP:                             \
                    tap_code16(tap_key);                          \
                    break;                                        \
                case SMTD_ACTION_HOLD:                            \
                    if (tap_count < threshold) {                  \
                        register_mods(get_mods() | MOD_BIT(mod)); \
                    } else {                                      \
                        register_code16(tap_key);                 \
                    }                                             \
                    break;                                        \
                case SMTD_ACTION_RELEASE:                         \
                    if (tap_count < threshold) {                  \
                        unregister_mods(MOD_BIT(mod));            \
                    }                                             \
                    unregister_code16(tap_key);                   \
                    break;                                        \
            }                                                     \
            break;                                                \
        }


#define CASE_SMTD_TOM_CYR(macro_key, mod)                     \
        case macro_key: {                                     \
            switch (action) {                                 \
                case SMTD_ACTION_TOUCH:                       \
                    break;                                    \
                case SMTD_ACTION_TAP:                         \
                    press_smcyr(macro_key);                   \
                    break;                                    \
                case SMTD_ACTION_HOLD:                        \
                    register_mods(get_mods() | MOD_BIT(mod)); \
                    break;                                    \
                case SMTD_ACTION_RELEASE:                     \
                    unregister_mods(MOD_BIT(mod));            \
                    break;                                    \
            }                                                 \
            break;                                            \
        }


#define CASE_SMTD_TOL(macro_key, tap_key, layer, threshold) \
        case macro_key: {                                   \
            switch (action) {                               \
                case SMTD_ACTION_TOUCH:                     \
                    break;                                  \
                case SMTD_ACTION_TAP:                       \
                    tap_code(tap_key);                      \
                    break;                                  \
                case SMTD_ACTION_HOLD:                      \
                    if (tap_count < threshold) {            \
                        LAYER_PUSH(layer);                  \
                    } else {                                \
                        register_code(tap_key);             \
                    }                                       \
                    break;                                  \
                case SMTD_ACTION_RELEASE:                   \
                    if (tap_count < threshold) {            \
                        LAYER_RESTORE();                    \
                    }                                       \
                    unregister_code(tap_key);               \
                    break;                                  \
            }                                               \
            break;                                          \
        }

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        CASE_SMTD_TOL(CKC_SPACE, KC_SPACE, L_NUM, 2)
        CASE_SMTD_TOL(CKC_ESC, KC_ESC, L_NUM, 2)
        CASE_SMTD_TOL(CKC_ENTER, KC_ENTER, L_FN, 2)
        CASE_SMTD_TOL(CKC_TAB, KC_TAB, L_FN, 2)

        CASE_SMTD_TOM(CKC_A, KC_A, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_S, KC_S, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM(CKC_D, KC_D, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM(CKC_G, KC_G, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_H, KC_H, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_K, KC_K, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM(CKC_L, KC_L, KC_RIGHT_ALT, 2)
        CASE_SMTD_TOM(CKC_KP_DOT, KC_KP_DOT, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_KP_4, KC_KP_4, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM(CKC_KP_5, KC_KP_5, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM(CKC_KP_6, KC_KP_6, KC_LEFT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_LPRN_L, KC_LPRN, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_LABK, KC_LABK, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_LCBR, KC_LCBR, KC_RIGHT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_LPRN_R, KC_LPRN, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM(CKC_LBRACKET, KC_LBRACKET, KC_RIGHT_ALT, 2)
        CASE_SMTD_TOM(CKC_DQUO, KC_DQUO, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_F4, KC_F4, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM(CKC_F5, KC_F5, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM(CKC_F6, KC_F6, KC_LEFT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_F11, KC_F11, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_LEFT, KC_LEFT, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_DOWN, KC_DOWN, KC_RIGHT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_UP, KC_UP, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM(CKC_RIGHT, KC_RIGHT, KC_RIGHT_ALT, 2)
        CASE_SMTD_TOM(CKC_MEDIA_PREV_TRACK, KC_MEDIA_PREV_TRACK, KC_RIGHT_GUI, 2)

        CASE_SMTD_TOM_CYR(SM_CYR_F, KC_LEFT_GUI)
        CASE_SMTD_TOM_CYR(SM_CYR_YI, KC_LEFT_ALT)
        CASE_SMTD_TOM_CYR(SM_CYR_V, KC_LEFT_CTRL)
        CASE_SMTD_TOM_CYR(SM_CYR_A, KC_LEFT_SHIFT)
        CASE_SMTD_TOM_CYR(SM_CYR_P, KC_LEFT_GUI)
        CASE_SMTD_TOM_CYR(SM_CYR_R, KC_RIGHT_GUI)
        CASE_SMTD_TOM_CYR(SM_CYR_O, KC_RIGHT_SHIFT)
        CASE_SMTD_TOM_CYR(SM_CYR_L, KC_RIGHT_CTRL)
        CASE_SMTD_TOM_CYR(SM_CYR_D, KC_RIGHT_ALT)
        CASE_SMTD_TOM_CYR(SM_CYR_DOT, KC_RIGHT_GUI)

        case CKC_LANG: {
            if (action == SMTD_ACTION_TOUCH) {
                if (tap_count == 0) {
                    layer_move(L_QWE_L);
                }
                if (tap_count == 1) {
                    layer_move(L_CYR);
                }
            }
            break;
        }

        case CKC_F: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code16(KC_F);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        register_mods(get_mods() | MOD_BIT(KC_LEFT_SHIFT));
                        LAYER_PUSH(L_QWE_U);
                    } else {
                        register_code16(KC_F);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        unregister_mods(MOD_BIT(KC_LEFT_SHIFT));
                        LAYER_RESTORE();
                    }
                    unregister_code16(KC_F);
                    break;
            }
            break;
        }

        case CKC_J: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code16(KC_J);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        register_mods(get_mods() | MOD_BIT(KC_RIGHT_SHIFT));
                        LAYER_PUSH(L_QWE_U);
                    } else {
                        register_code16(KC_J);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        unregister_mods(MOD_BIT(KC_RIGHT_SHIFT));
                        LAYER_RESTORE();
                    }
                    unregister_code16(KC_J);
                    break;
            }
            break;
        }

        case CKC_SEMICOLON: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    if (get_mods() & MOD_MASK_SHIFT) {
                        SM_PRESS_NO_MODS(KC_COMMA);
                    } else {
                        SM_PRESS_NO_MODS(KC_DOT);
                    }
                    break;
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_GUI));
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_GUI));
                    break;
            }
            break;
        }

        case MACRO_SLSH_OR_COLON: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    switch (tap_count) {
                        case 0:
                            tap_code16(KC_KP_SLASH);
                            break;
                        case 1:
                            tap_code16(KC_BSPACE);
                            tap_code16(KC_COLN);
                            break;
                        case 2:
                            tap_code16(KC_BSPACE);
                            tap_code16(KC_KP_SLASH);
                            tap_code16(KC_KP_SLASH);
                            tap_code16(KC_KP_SLASH);
                            break;
                        default:
                            tap_code16(KC_KP_SLASH);
                            break;
                    }
                    break;
                case SMTD_ACTION_TAP:
                case SMTD_ACTION_HOLD:
                case SMTD_ACTION_RELEASE:
                    break;
            }
            break;
        }

    }
}

smtd_state smtd_states[] = {
    SMTD(CKC_SPACE),
    SMTD(CKC_ESC),
    SMTD(CKC_ENTER),
    SMTD(CKC_TAB),
    SMTD(CKC_LANG),
    SMTD(MACRO_SLSH_OR_COLON),

    SMTD(CKC_A),
    SMTD(CKC_S),
    SMTD(CKC_D),
    SMTD(CKC_F),
    SMTD(CKC_G),

    SMTD(CKC_H),
    SMTD(CKC_J),
    SMTD(CKC_K),
    SMTD(CKC_L),
    SMTD(CKC_SEMICOLON),

    SMTD(SM_CYR_F),
    SMTD(SM_CYR_YI),
    SMTD(SM_CYR_V),
    SMTD(SM_CYR_A),
    SMTD(SM_CYR_P),

    SMTD(SM_CYR_R),
    SMTD(SM_CYR_O),
    SMTD(SM_CYR_L),
    SMTD(SM_CYR_D),
    SMTD(SM_CYR_DOT),

    SMTD(CKC_KP_DOT),
    SMTD(CKC_KP_4),
    SMTD(CKC_KP_5),
    SMTD(CKC_KP_6),
    SMTD(CKC_LPRN_L),
    SMTD(CKC_LABK),
    SMTD(CKC_LCBR),
    SMTD(CKC_LPRN_R),
    SMTD(CKC_LBRACKET),
    SMTD(CKC_DQUO),

    SMTD(CKC_F4),
    SMTD(CKC_F5),
    SMTD(CKC_F6),
    SMTD(CKC_F11),
    SMTD(CKC_LEFT),
    SMTD(CKC_DOWN),
    SMTD(CKC_UP),
    SMTD(CKC_RIGHT),
    SMTD(CKC_MEDIA_PREV_TRACK),
};
size_t smtd_states_size = sizeof(smtd_states) / sizeof(smtd_states[0]);

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        case CKC_A:
        case CKC_S:
        case CKC_D:
        case CKC_F:
        case CKC_G:
        case CKC_H:
        case CKC_J:
        case CKC_K:
        case CKC_L:
        case CKC_SEMICOLON:
        case SM_CYR_F:
        case SM_CYR_YI:
        case SM_CYR_V:
        case SM_CYR_A:
        case SM_CYR_P:
        case SM_CYR_R:
        case SM_CYR_O:
        case SM_CYR_L:
        case SM_CYR_D:
        case SM_CYR_DOT:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
    }

    return get_smtd_timeout_default(timeout);
}
