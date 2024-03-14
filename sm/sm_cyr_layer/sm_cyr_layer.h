#pragma once

#include QMK_KEYBOARD_H
#include <sm_utils.h>

#define SMCYR_SHORTCUT_LAYER L_QWE_L //fixme
#define SMCYR_SIZE 33 //fixme
#define SMCYR_FIRST_IDX SM_CYR_YY //fixme
#define SMCYR_LAST_IDX SM_CYR_SOLID //fixme
#define NOT_INIT 48556
#define NOT_FOUND 48555


static uint16_t smcyr_to_shorcut[SMCYR_SIZE] = {
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
    NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT, NOT_INIT,
};

#define CASE_CYR(key, uc_l, uc_u)                                                       \
        case key:                                                                       \
            if (get_mods() == MOD_BIT(KC_LSHIFT) || get_mods() == MOD_BIT(KC_RSHIFT)) { \
                register_unicode(uc_u);                                                 \
            } else if (get_mods() == 0) {                                               \
                register_unicode(uc_l);                                                 \
            } else {                                                                    \
                tap_code16(smcyr_get_shortcut(keycode));                                \
            }                                                                           \
            break;                  \

uint16_t smcyr_get_shortcut(uint16_t cyr_keycode) {
    uint8_t idx = cyr_keycode % SMCYR_SIZE;
    uint16_t result = smcyr_to_shorcut[idx];
    if (result != NOT_INIT) {
        return result;
    }

//    if (cyr_keycode < SMCYR_FIRST_IDX || cyr_keycode > SMCYR_LAST_IDX) {
//        return NOT_INIT;
//    }
//fixme

    int layers = sizeof(keymaps) / sizeof(keymaps[0]);
    for(int layer = 0; layer < layers; layer++) {
        for(int row = 0; row < MATRIX_ROWS; row++) {
            for(int col = 0; col < MATRIX_COLS; col++) {
                 if (keymaps[layer][row][col] == cyr_keycode) {
                      smcyr_to_shorcut[idx] = keymaps[SMCYR_SHORTCUT_LAYER][row][col];
                      return smcyr_to_shorcut[idx];
                 }
            }
        }
    }

    smcyr_to_shorcut[idx] = NOT_FOUND;
    return smcyr_to_shorcut[idx];
}


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



