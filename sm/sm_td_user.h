#pragma once

#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_td.h"
#include "sm_utils.h"

#define CASE_SMTD_TOM(macro_key, tap_key, mod)                \
    case macro_key:                                           \
        switch (action) {                                     \
            case SMTD_ACTION_TOUCH:                           \
                break;                                        \
            case SMTD_ACTION_TAP:                             \
                tap_code16(tap_key);                          \
                break;                                        \
            case SMTD_ACTION_HOLD:                            \
                if (tap_count == 0 || tap_count == 1) {       \
                    register_mods(get_mods() | MOD_BIT(mod)); \
                } else {                                      \
                    register_code16(tap_key);                 \
                }                                             \
                break;                                        \
            case SMTD_ACTION_RELEASE:                         \
                if (tap_count == 0 || tap_count == 1) {       \
                    unregister_mods(MOD_BIT(mod));            \
                }                                             \
                unregister_code16(tap_key);                   \
                break;                                        \
        }                                                     \
        break;

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        case CKC_LANG: {
            if (action == SMTD_ACTION_TOUCH) {
                if (tap_count == 0) {
                    layer_move(0);
                }
                if (tap_count == 1) {
                    layer_move(2);
                }
            }
            break;
        }

        case CKC_SPACE: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_SPACE);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_MOVE(4);
                    } else {
                        register_code(KC_SPACE);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_SPACE);
                    break;
            }
            break;
        }

        case CKC_ESC: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_ESC);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_MOVE(4);
                    } else {
                        register_code(KC_ESC);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_ESC);
                    break;
            }
            break;
        }

        case CKC_ENTER: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_ENTER);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_MOVE(5);
                    } else {
                        register_code(KC_ENTER);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_ENTER);
                    break;
            }
            break;
        }

        case CKC_TAB: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_TAB);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_MOVE(5);
                    } else {
                        register_code(KC_TAB);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_TAB);
                    break;
            }
            break;
        }
        case CKC_F: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_F);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        register_mods(get_mods() | MOD_BIT(KC_LEFT_SHIFT));
                        LAYER_MOVE(1);
                    } else {
                        register_code(KC_F);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        unregister_mods(MOD_BIT(KC_LEFT_SHIFT));
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_F);
                    break;
            }
            break;
        }

        case CKC_J: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code(KC_J);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count == 0 || tap_count == 1) {
                        register_mods(get_mods() | MOD_BIT(KC_RIGHT_SHIFT));
                        LAYER_MOVE(1);
                    } else {
                        register_code(KC_J);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count == 0 || tap_count == 1) {
                        unregister_mods(MOD_BIT(KC_RIGHT_SHIFT));
                        LAYER_RESTORE();
                    }
                    unregister_code(KC_J);
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

        case CKC_RU_A: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_4));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_S: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_B));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_ALT));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_ALT));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_D: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_2));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_CTRL));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_CTRL));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_F: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_0));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_SHIFT));
                    LAYER_MOVE(3);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_SHIFT));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_G: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_F));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_H: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_0));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_J: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_E));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_SHIFT));
                    LAYER_MOVE(3);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_SHIFT));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_K: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_B));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_CTRL));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_CTRL));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_L: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_4));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_ALT));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_ALT));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_SEMICOLON: {
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
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_A: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_4));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_S: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_B));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_ALT));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_ALT));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_D: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_2));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_CTRL));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_CTRL));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_F: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_0));
                    break;
                }
                case SMTD_ACTION_HOLD: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_0));
                    break;
                }
                case SMTD_ACTION_RELEASE:
                    break;
            }
            break;
        }

        case CKC_RU_U_G: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_F));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_LEFT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_LEFT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_H: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_0));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_GUI));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_GUI));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_J: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_E));
                    break;
                }
                case SMTD_ACTION_HOLD: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_E));
                    break;
                }
                case SMTD_ACTION_RELEASE:
                    break;
            }
            break;
        }

        case CKC_RU_U_K: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_B));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_CTRL));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_CTRL));
                    LAYER_RESTORE();
                    break;
            }
            break;
        }

        case CKC_RU_U_L: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP: {
                    SM_UNICODE_NO_R(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_4));
                    break;
                }
                case SMTD_ACTION_HOLD:
                    register_mods(get_mods() | MOD_BIT(KC_RIGHT_ALT));
                    LAYER_MOVE(0);
                    break;
                case SMTD_ACTION_RELEASE:
                    unregister_mods(MOD_BIT(KC_RIGHT_ALT));
                    LAYER_RESTORE();
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

            CASE_SMTD_TOM(CKC_A, KC_A, KC_LEFT_GUI)
            CASE_SMTD_TOM(CKC_S, KC_S, KC_LEFT_ALT)
            CASE_SMTD_TOM(CKC_D, KC_D, KC_LEFT_CTRL)
            CASE_SMTD_TOM(CKC_G, KC_G, KC_LEFT_GUI)
            CASE_SMTD_TOM(CKC_H, KC_H, KC_RIGHT_GUI)
            CASE_SMTD_TOM(CKC_K, KC_K, KC_RIGHT_CTRL)
            CASE_SMTD_TOM(CKC_L, KC_L, KC_RIGHT_ALT)
            CASE_SMTD_TOM(CKC_KP_DOT, KC_KP_DOT, KC_LEFT_GUI)
            CASE_SMTD_TOM(CKC_KP_4, KC_KP_4, KC_LEFT_ALT)
            CASE_SMTD_TOM(CKC_KP_5, KC_KP_5, KC_LEFT_CTRL)
            CASE_SMTD_TOM(CKC_KP_6, KC_KP_6, KC_LEFT_SHIFT)
            CASE_SMTD_TOM(CKC_LPRN_L, KC_LPRN, KC_LEFT_GUI)
            CASE_SMTD_TOM(CKC_LABK, KC_LABK, KC_RIGHT_GUI)
            CASE_SMTD_TOM(CKC_LCBR, KC_LCBR, KC_RIGHT_SHIFT)
            CASE_SMTD_TOM(CKC_LPRN_R, KC_LPRN, KC_RIGHT_CTRL)
            CASE_SMTD_TOM(CKC_LBRACKET, KC_LBRACKET, KC_RIGHT_ALT)
            CASE_SMTD_TOM(CKC_DQUO, KC_DQUO, KC_RIGHT_GUI)
            CASE_SMTD_TOM(CKC_F4, KC_F4, KC_LEFT_ALT)
            CASE_SMTD_TOM(CKC_F5, KC_F5, KC_LEFT_CTRL)
            CASE_SMTD_TOM(CKC_F6, KC_F6, KC_LEFT_SHIFT)
            CASE_SMTD_TOM(CKC_F11, KC_F11, KC_LEFT_GUI)
            CASE_SMTD_TOM(CKC_LEFT, KC_LEFT, KC_RIGHT_GUI)
            CASE_SMTD_TOM(CKC_DOWN, KC_DOWN, KC_RIGHT_SHIFT)
            CASE_SMTD_TOM(CKC_UP, KC_UP, KC_RIGHT_CTRL)
            CASE_SMTD_TOM(CKC_RIGHT, KC_RIGHT, KC_RIGHT_ALT)
            CASE_SMTD_TOM(CKC_MEDIA_PREV_TRACK, KC_MEDIA_PREV_TRACK, KC_RIGHT_GUI)
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

    SMTD(CKC_RU_A),
    SMTD(CKC_RU_S),
    SMTD(CKC_RU_D),
    SMTD(CKC_RU_F),
    SMTD(CKC_RU_G),

    SMTD(CKC_RU_H),
    SMTD(CKC_RU_J),
    SMTD(CKC_RU_K),
    SMTD(CKC_RU_L),
    SMTD(CKC_RU_SEMICOLON),

    SMTD(CKC_RU_U_A),
    SMTD(CKC_RU_U_S),
    SMTD(CKC_RU_U_D),
    SMTD(CKC_RU_U_F),
    SMTD(CKC_RU_U_G),

    SMTD(CKC_RU_U_H),
    SMTD(CKC_RU_U_J),
    SMTD(CKC_RU_U_K),
    SMTD(CKC_RU_U_L),

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
        case CKC_RU_A:
        case CKC_RU_S:
        case CKC_RU_D:
        case CKC_RU_F:
        case CKC_RU_G:
        case CKC_RU_H:
        case CKC_RU_J:
        case CKC_RU_K:
        case CKC_RU_L:
        case CKC_RU_SEMICOLON:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
    }

    return get_smtd_timeout_default(timeout);
}
