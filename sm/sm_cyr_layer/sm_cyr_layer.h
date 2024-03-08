#pragma once

#include QMK_KEYBOARD_H
#include <sm_utils.h>

#define SMCYR_SHORTCUT_LAYER 0 //fixme

//fixme switch to shortcut layer on mods

#define UC_L_OR_U(uc_l, uc_u) \
    if (get_mods() == MOD_BIT(KC_LSHIFT) || get_mods() == MOD_BIT(KC_RSHIFT)) { \
        register_unicode(uc_u); \
    } else if (get_mods() == 0) { \
        register_unicode(uc_l); \
    }

#define CASE_CYR(key, uc_l, uc_u)   \
        case key:                   \
            UC_L_OR_U(uc_l, uc_u);  \
            break;                  \

//void press_shortcut(keyrecord_t *record) {
//    uint16_t shortcut_key = keymaps[SMCYR_SHORTCUT_LAYER][record->event.key.row][record->event.key.col];
//    state->freeze            = true;
//    keyevent_t  event_press  = MAKE_KEYEVENT(record->event.key.row, state->following_key.col, true);
//    keyrecord_t record_press = {.event = event_press};
//    process_record(&record_press);
//    if (release) {
//        keyevent_t  event_release  = MAKE_KEYEVENT(state->following_key.row, state->following_key.col, false);
//        keyrecord_t record_release = {.event = event_release};
//        SMTD_SIMULTANEOUS_PRESSES_DELAY;
//        process_record(&record_release);
//    }
//    state->freeze = false;
//}


bool press_smcyr(uint16_t keycode) {
    switch (keycode) {
        CASE_CYR(SM_CYR_YY, 0x0439, 0x0419);
        CASE_CYR(SM_CYR_CC, 0x0446, 0x0426);
        CASE_CYR(SM_CYR_U, 0x0443, 0x0423);
        CASE_CYR(SM_CYR_K, 0x043A, 0x041A);
        CASE_CYR(SM_CYR_E, 0x0435, 0x0415);
        CASE_CYR(SM_CYR_F, 0x0444, 0x0424);
        CASE_CYR(SM_CYR_YI, 0x044B, 0x042B);
        CASE_CYR(SM_CYR_V, 0x0432, 0x0412);
        CASE_CYR(SM_CYR_A, 0x0430, 0x0410);
        CASE_CYR(SM_CYR_P, 0x043F, 0x041F);
        CASE_CYR(SM_CYR_YA, 0x044F, 0x042F);
        CASE_CYR(SM_CYR_CH, 0x0447, 0x0427);
        CASE_CYR(SM_CYR_S, 0x0441, 0x0421);
        CASE_CYR(SM_CYR_M, 0x043C, 0x041C);
        CASE_CYR(SM_CYR_I, 0x0438, 0x0418);
        CASE_CYR(SM_CYR_N, 0x043D, 0x041D);
        CASE_CYR(SM_CYR_G, 0x0433, 0x0413);
        CASE_CYR(SM_CYR_SH, 0x0448, 0x0428);
        CASE_CYR(SM_CYR_SCH, 0x0449, 0x0429);
        CASE_CYR(SM_CYR_Z, 0x0437, 0x0417);
        CASE_CYR(SM_CYR_H, 0x0445, 0x0425);
        CASE_CYR(SM_CYR_R, 0x0440, 0x0420);
        CASE_CYR(SM_CYR_O, 0x043E, 0x041E);
        CASE_CYR(SM_CYR_L, 0x043B, 0x041B);
        CASE_CYR(SM_CYR_D, 0x0434, 0x0414);
        CASE_CYR(SM_CYR_EE, 0x044D, 0x042D);
        CASE_CYR(SM_CYR_T, 0x0442, 0x0422);
        CASE_CYR(SM_CYR_SOFT, 0x044C, 0x042C);
        CASE_CYR(SM_CYR_B, 0x0431, 0x0411);
        CASE_CYR(SM_CYR_YU, 0x044E, 0x042E);
        CASE_CYR(SM_CYR_ZH, 0x0436, 0x0416);
        CASE_CYR(SM_CYR_SOLID, 0x044A, 0x042A);

        case SM_CYR_DOT:
            if (get_mods() == MOD_BIT(KC_LSHIFT) || get_mods() == MOD_BIT(KC_RSHIFT)) {
                SM_PRESS_NO_MODS(KC_COMMA);
            } else if (get_mods() == 0) {
                tap_code16(KC_DOT);
            }
            break;

        default:
            return true;
    }

    return false;
}

bool process_smcyr(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    return press_smcyr(keycode);
}
