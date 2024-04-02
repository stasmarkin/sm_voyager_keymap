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


#define CASE_SMTD_TOM_SM_LAYOUTS(macro_key, mod)                     \
        case macro_key: {                                     \
            switch (action) {                                 \
                case SMTD_ACTION_TOUCH:                       \
                    break;                                    \
                case SMTD_ACTION_TAP:                         \
                    process_sm_layouts_tap(macro_key);                   \
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
        CASE_SMTD_TOM(CKC_F, KC_F, KC_LSHIFT, 2)
        CASE_SMTD_TOM(CKC_G, KC_G, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_H, KC_H, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_J, KC_J, KC_RSHIFT, 2)
        CASE_SMTD_TOM(CKC_K, KC_K, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM(CKC_L, KC_L, KC_RIGHT_ALT, 2)
        CASE_SMTD_TOM(CKC_Z, KC_Z, KC_RCMD, 2)

        CASE_SMTD_TOM_SM_LAYOUTS(CYR_F, KC_LEFT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_YI, KC_LEFT_ALT)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_V, KC_LEFT_CTRL)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_A, KC_LEFT_SHIFT)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_P, KC_LEFT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_R, KC_RIGHT_GUI)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_O, KC_RIGHT_SHIFT)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_L, KC_RIGHT_CTRL)
        CASE_SMTD_TOM_SM_LAYOUTS(CYR_D, KC_RIGHT_ALT)

        CASE_SMTD_TOM(CKC_4, KC_4, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM(CKC_5, KC_5, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM(CKC_6, KC_6, KC_LEFT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_CIRC, KC_CIRC, KC_LCMD, 2)
        CASE_SMTD_TOM(CKC_AT, KC_AT, KC_RIGHT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_DOLL, KC_DOLLAR, KC_RIGHT_CTRL, 2)

        CASE_SMTD_TOM(CKC_F4, KC_F4, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM(CKC_F5, KC_F5, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM(CKC_F6, KC_F6, KC_LEFT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_F11, KC_F11, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM(CKC_LEFT, KC_LEFT, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM(CKC_DOWN, KC_DOWN, KC_RIGHT_SHIFT, 2)
        CASE_SMTD_TOM(CKC_UP, KC_UP, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM(CKC_RIGHT, KC_RIGHT, KC_RIGHT_ALT, 2)
        CASE_SMTD_TOM(CKC_VOLU, KC_VOLU, KC_RIGHT_GUI, 2)


        case CKC_DF_COMBO: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    break;
                case SMTD_ACTION_TAP:
                    tap_code16(KC_BSPC);
                    break;
                case SMTD_ACTION_HOLD:
                    if (tap_count < 2) {
                        register_mods(get_mods() | MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL));
                    } else {
                        register_code16(KC_BSPC);
                    }
                    break;
                case SMTD_ACTION_RELEASE:
                    if (tap_count < 2) {
                        unregister_mods(MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL));
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
                            tap_code16(KC_BSPACE);
                            tap_code16(KC_COLN);
                            break;
                        case 2:
                            tap_code16(KC_BSPACE);
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
                        register_mods(get_mods() | MOD_BIT(KC_LCMD));
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

        case CKC_CURR: {
            switch (action) {
                case SMTD_ACTION_TOUCH:
                    switch (tap_count) {
                        case 0:
                            register_unicode(0x20BD);
                            break;
                        default:
                            tap_code16(KC_BSPACE);
                            if (tap_count % 2 == 0) {
                                register_unicode(0x20BD);
                            } else {
                                register_unicode(0x20AC);
                            }
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
    SMTD(CKC_DF_COMBO),

    SMTD(CKC_A),
    SMTD(CKC_S),
    SMTD(CKC_D),
    SMTD(CKC_F),
    SMTD(CKC_G),
    SMTD(CKC_H),
    SMTD(CKC_J),
    SMTD(CKC_K),
    SMTD(CKC_L),
    SMTD(CKC_Z),

    SMTD(CYR_F),
    SMTD(CYR_YI),
    SMTD(CYR_V),
    SMTD(CYR_A),
    SMTD(CYR_P),
    SMTD(CYR_R),
    SMTD(CYR_O),
    SMTD(CYR_L),
    SMTD(CYR_D),

    SMTD(CKC_NDOT),
    SMTD(CKC_4),
    SMTD(CKC_5),
    SMTD(CKC_6),
    SMTD(CKC_CIRC),
    SMTD(CKC_AT),
    SMTD(CKC_DOLL),

    SMTD(CKC_F4),
    SMTD(CKC_F5),
    SMTD(CKC_F6),
    SMTD(CKC_F11),
    SMTD(CKC_LEFT),
    SMTD(CKC_DOWN),
    SMTD(CKC_UP),
    SMTD(CKC_RIGHT),
    SMTD(CKC_VOLU),

    SMTD(CKC_CURR),

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
        case CKC_Z:
        case CYR_F:
        case CYR_YI:
        case CYR_V:
        case CYR_A:
        case CYR_P:
        case CYR_R:
        case CYR_O:
        case CYR_L:
        case CYR_D:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            break;

        case CKC_NDOT:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
            break;

        case CKC_DF_COMBO:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
            break;
    }

    return get_smtd_timeout_default(timeout);
}
