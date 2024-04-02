#pragma once

#include QMK_KEYBOARD_H
#include "sm_layers_keycodes.h"

#define NOT_INIT MATRIX_ROWS + MATRIX_COLS
#define NOT_FOUND NOT_INIT + 1

static uint16_t sm_layers_keycode_to_shortcut_row[SM_LAYERS_SIZE] = { NOT_INIT };
static uint16_t sm_layers_keycode_to_shortcut_col[SM_LAYERS_SIZE] = { NOT_INIT };


#define CASE_LOWER_UPPER_UNICODE(key, uc_l, uc_u)           \
        case key:                                           \
            if (get_oneshot_mods() != 0) {                  \
                sm_layers_keycode_to_shortcut_tap(keycode);  \
            } else if (get_mods() == MOD_BIT(KC_LSHIFT) ||  \
                    get_mods() == MOD_BIT(KC_RSHIFT)) {     \
                register_unicode(uc_u);                     \
            } else if (get_mods() == 0) {                   \
                register_unicode(uc_l);                     \
            } else {                                        \
                sm_layers_keycode_to_shortcut_tap(keycode);  \
            }                                               \
            return false;                                   \

void sm_layers_make_shortcut_tap(uint8_t row, uint8_t col) {
    uint8_t return_layer = get_highest_layer(layer_state);
    layer_move(SM_LAYERS_SHORTCUT_LAYER);
    keyevent_t  event  = MAKE_KEYEVENT(row, col, true);
    keyrecord_t record = {.event = event};
    process_record(&record);
    event.pressed = false;
    record.event = event;
    process_record(&record);
    layer_move(return_layer);
 }

void sm_layers_keycode_to_shortcut_tap(uint16_t sm_layers_keycode) {
    uint8_t idx = sm_layers_keycode % SM_LAYERS_SIZE;
    uint16_t row = sm_layers_keycode_to_shortcut_row[idx];
    uint16_t col = sm_layers_keycode_to_shortcut_col[idx];

    if (row != NOT_INIT || col != NOT_INIT) {
        sm_layers_make_shortcut_tap(row, col);
        return;
    }

    if (sm_layers_keycode <= SM_LAYERS_BEGIN || sm_layers_keycode >= SM_LAYERS_END) {
        return;
    }

    int layers = sizeof(keymaps) / sizeof(keymaps[0]);
    for(int layer = 0; layer < layers; layer++) {
        for(int row = 0; row < MATRIX_ROWS; row++) {
            for(int col = 0; col < MATRIX_COLS; col++) {
                 if (keymaps[layer][row][col] == sm_layers_keycode) {
                      sm_layers_keycode_to_shortcut_row[idx] = row;
                      sm_layers_keycode_to_shortcut_col[idx] = col;
                      sm_layers_make_shortcut_tap(row, col);
                      return;
                 }
            }
        }
    }

    sm_layers_keycode_to_shortcut_row[idx] = NOT_FOUND;
    sm_layers_keycode_to_shortcut_col[idx] = NOT_FOUND;
}


bool process_sm_layers_tap(uint16_t keycode) {
    switch (keycode) {
        CASE_LOWER_UPPER_UNICODE(CYR_YY, 0x0439, 0x0419);
        CASE_LOWER_UPPER_UNICODE(CYR_CC, 0x0446, 0x0426);
        CASE_LOWER_UPPER_UNICODE(CYR_U, 0x0443, 0x0423);
        CASE_LOWER_UPPER_UNICODE(CYR_K, 0x043A, 0x041A);
        CASE_LOWER_UPPER_UNICODE(CYR_E, 0x0435, 0x0415);
        CASE_LOWER_UPPER_UNICODE(CYR_F, 0x0444, 0x0424);
        CASE_LOWER_UPPER_UNICODE(CYR_YI, 0x044B, 0x042B);
        CASE_LOWER_UPPER_UNICODE(CYR_V, 0x0432, 0x0412);
        CASE_LOWER_UPPER_UNICODE(CYR_A, 0x0430, 0x0410);
        CASE_LOWER_UPPER_UNICODE(CYR_P, 0x043F, 0x041F);
        CASE_LOWER_UPPER_UNICODE(CYR_YA, 0x044F, 0x042F);
        CASE_LOWER_UPPER_UNICODE(CYR_CH, 0x0447, 0x0427);
        CASE_LOWER_UPPER_UNICODE(CYR_SS, 0x0441, 0x0421);
        CASE_LOWER_UPPER_UNICODE(CYR_M, 0x043C, 0x041C);
        CASE_LOWER_UPPER_UNICODE(CYR_I, 0x0438, 0x0418);
        CASE_LOWER_UPPER_UNICODE(CYR_N, 0x043D, 0x041D);
        CASE_LOWER_UPPER_UNICODE(CYR_G, 0x0433, 0x0413);
        CASE_LOWER_UPPER_UNICODE(CYR_SH, 0x0448, 0x0428);
        CASE_LOWER_UPPER_UNICODE(CYR_SCH, 0x0449, 0x0429);
        CASE_LOWER_UPPER_UNICODE(CYR_ZZ, 0x0437, 0x0417);
        CASE_LOWER_UPPER_UNICODE(CYR_H, 0x0445, 0x0425);
        CASE_LOWER_UPPER_UNICODE(CYR_R, 0x0440, 0x0420);
        CASE_LOWER_UPPER_UNICODE(CYR_O, 0x043E, 0x041E);
        CASE_LOWER_UPPER_UNICODE(CYR_YO, 0x0451, 0x0401);
        CASE_LOWER_UPPER_UNICODE(CYR_L, 0x043B, 0x041B);
        CASE_LOWER_UPPER_UNICODE(CYR_D, 0x0434, 0x0414);
        CASE_LOWER_UPPER_UNICODE(CYR_YE, 0x044D, 0x042D);
        CASE_LOWER_UPPER_UNICODE(CYR_T, 0x0442, 0x0422);
        CASE_LOWER_UPPER_UNICODE(CYR_SFT, 0x044C, 0x042C);
        CASE_LOWER_UPPER_UNICODE(CYR_B, 0x0431, 0x0411);
        CASE_LOWER_UPPER_UNICODE(CYR_YU, 0x044E, 0x042E);
        CASE_LOWER_UPPER_UNICODE(CYR_ZH, 0x0436, 0x0416);
        CASE_LOWER_UPPER_UNICODE(CYR_SLD, 0x044A, 0x042A);

        default:
            return true;
    }

    return false;
}

bool process_sm_layers(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    return process_sm_layers_tap(keycode);
}



