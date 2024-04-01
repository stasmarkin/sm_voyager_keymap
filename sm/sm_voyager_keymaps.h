#pragma once
#include QMK_KEYBOARD_H
#include "sm_voyager_keycodes.h"
#include "sm_cyr_layer/sm_cyr_keycodes.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_voyager(
    XXXXXXX,   XXXXXXX,      KC_W,      KC_E,      KC_R,      KC_T,             KC_Y,      KC_U,      KC_I,      KC_O,   XXXXXXX,   XXXXXXX,
    XXXXXXX,     CKC_A,     CKC_S,     CKC_D,     CKC_F,     CKC_G,            CKC_H,     CKC_J,     CKC_K,     CKC_L,     CKC_Z,   XXXXXXX,
    XXXXXXX,   M_OLD_Z,      KC_X,      KC_C,      KC_V,      KC_B,             KC_N,      KC_M,      KC_P,      KC_Q,     M_QUE,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_RU] = LAYOUT_voyager(
    XXXXXXX,   XXXXXXX, SM_CYR_CC,  SM_CYR_U,  SM_CYR_K,  SM_CYR_E,         SM_CYR_N,  SM_CYR_G, SM_CYR_SH,SM_CYR_SCH,   XXXXXXX,   XXXXXXX,
  SM_CYR_YY,  SM_CYR_F, SM_CYR_YI,  SM_CYR_V,  SM_CYR_A,  SM_CYR_P,         SM_CYR_R,  SM_CYR_O,  SM_CYR_L,  SM_CYR_D, SM_CYR_ZH,  SM_CYR_Z,
SM_CYR_SOLID,SM_CYR_YA, SM_CYR_CH,  SM_CYR_S,  SM_CYR_M,  SM_CYR_I,         SM_CYR_T,SM_CYR_SOFT, SM_CYR_B, SM_CYR_YU, SM_CYR_EE,  SM_CYR_H,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_NUM] = LAYOUT_voyager(
    XXXXXXX,   XXXXXXX,      KC_7,      KC_8,      KC_9,   KC_PERC,          XXXXXXX,   KC_HASH,  CKC_CURR,  KC_GRAVE,   XXXXXXX,   XXXXXXX,
    XXXXXXX,  CKC_NDOT,     CKC_4,     CKC_5,     CKC_6,  CKC_CIRC,          KC_RCMD,    CKC_AT,  CKC_DOLL,   KC_ROPT,   KC_RCMD,   XXXXXXX,
    XXXXXXX,      KC_0,      KC_1,      KC_2,      KC_3,   XXXXXXX,          XXXXXXX,   KC_AMPR,   KC_PIPE,   KC_TILD,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB

  ),
  [L_FN] = LAYOUT_voyager(
    XXXXXXX,   XXXXXXX,     KC_F7,      KC_F8,    KC_F9,    KC_F10,          XXXXXXX,   KC_MPRV,   KC_MPLY,   KC_MNXT,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   KC_LGUI,    CKC_F4,     CKC_F5,   CKC_F6,   CKC_F11,         CKC_LEFT,  CKC_DOWN,    CKC_UP, CKC_RIGHT,  CKC_VOLU,   XXXXXXX,
    XXXXXXX,    M_SCRN,     KC_F1,      KC_F2,    KC_F3,    KC_F12,          KC_HOME, KC_PGDOWN,   KC_PGUP,    KC_END,   KC_VOLD,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
};
