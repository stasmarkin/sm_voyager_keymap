#pragma once

#include QMK_KEYBOARD_H

#define RETURN_LAYER_NOT_SET 15

static uint8_t return_layer     = RETURN_LAYER_NOT_SET;
static uint8_t return_layer_cnt = 0;

#define SM_UNICODE_NO_R(string)                           \
    const uint8_t mods = get_mods();                      \
    unregister_mods(mods);                                \
    register_mods(MOD_MASK_SA); \
    SEND_STRING(string);                                  \
    unregister_mods(MOD_MASK_SA);                         \
    register_mods(mods);

#define SM_UNICODE(string)  \
    SM_UNICODE_NO_R(string) \
    return false;

#define SM_PRESS_NO_MODS(key)        \
    const uint8_t mods = get_mods(); \
    unregister_mods(mods);           \
    tap_code16(key);                 \
    register_mods(mods);

void press_no_mods(uint16_t keycode) {
    SM_PRESS_NO_MODS(keycode);
}

#define LAYER_MOVE(layer)                              \
    return_layer_cnt++;                                \
    if (return_layer == RETURN_LAYER_NOT_SET) {        \
        return_layer = get_highest_layer(layer_state); \
    }                                                  \
    layer_move(layer);

#define LAYER_RESTORE()                          \
    if (return_layer_cnt > 0) {                  \
        return_layer_cnt--;                      \
        if (return_layer_cnt == 0) {             \
            layer_move(return_layer);            \
            return_layer = RETURN_LAYER_NOT_SET; \
        }                                        \
    }
