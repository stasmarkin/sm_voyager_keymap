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



#define CASE_SMTD_TOM_W_CAPS(macro_key, tap_key, mod, threshold)         \
        case macro_key: {                                         \
            switch (action) {                                     \
                case SMTD_ACTION_TOUCH:                           \
                    break;                                        \
                case SMTD_ACTION_TAP:                             \
                    tap_code16(is_caps_word_on() ? LSFT(tap_key) : tap_key);     \
                    break;                                        \
                case SMTD_ACTION_HOLD:                            \
                    if (tap_count < threshold) {                  \
                        register_mods(get_mods() | MOD_BIT(mod)); \
                    } else {                                      \
                        tap_code16(is_caps_word_on() ? LSFT(tap_key) : tap_key); \
                    }                                             \
                    break;                                        \
                case SMTD_ACTION_RELEASE:                         \
                    if (tap_count < threshold) {                  \
                        unregister_mods(MOD_BIT(mod));            \
                    }                                             \
                    unregister_code16(is_caps_word_on() ? LSFT(tap_key) : tap_key);  \
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

        CASE_SMTD_TOM_W_CAPS(CKC_S, KC_S, KC_LEFT_ALT, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_A, KC_A, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_D, KC_D, KC_LEFT_CTRL, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_F, KC_F, KC_LSFT, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_G, KC_G, KC_LEFT_GUI, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_H, KC_H, KC_RIGHT_GUI, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_J, KC_J, KC_RSFT, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_K, KC_K, KC_RIGHT_CTRL, 2)
        CASE_SMTD_TOM_W_CAPS(CKC_L, KC_L, KC_RIGHT_ALT, 2)

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
        CASE_SMTD_TOM(CKC_HASH, KC_HASH, KC_RIGHT_CTRL, 2)

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
                        register_mods(get_mods() | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
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
    }
}

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
