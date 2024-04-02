#pragma once
#include QMK_KEYBOARD_H
#include "sm_layers_keycodes.h"

#define IIIIIII KC_NO


enum custom_keycodes {

  CKC_DF_COMBO = ML_SAFE_RANGE,
  CKC_SPACE,
  CKC_ENTER,
  CKC_ESC,
  CKC_TAB,

  CKC_A,
  CKC_S,
  CKC_D,
  CKC_F,
  CKC_G,
  CKC_H,
  CKC_J,
  CKC_K,
  CKC_L,
  CKC_Z,

  CKC_NDOT,
  CKC_4,
  CKC_5,
  CKC_6,
  CKC_CIRC,
  CKC_AT,
  CKC_DOLL,

  CKC_F4,
  CKC_F5,
  CKC_F6,
  CKC_F11,
  CKC_LEFT,
  CKC_DOWN,
  CKC_UP,
  CKC_RIGHT,
  CKC_VOLU,

  M_SCRN,
  M_QUE,
  M_OLD_Z,
  CKC_CURR,

  SM_LAYERS_KEYCODES,
};

enum layers {
  L_EN = 0,
  L_RU,
  L_NUM,
  L_FN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_voyager(
    IIIIIII,   IIIIIII,      KC_W,      KC_E,      KC_R,      KC_T,             KC_Y,      KC_U,      KC_I,      KC_O,   IIIIIII,   IIIIIII,
    IIIIIII,     CKC_A,     CKC_S,     CKC_D,     CKC_F,     CKC_G,            CKC_H,     CKC_J,     CKC_K,     CKC_L,     CKC_Z,   IIIIIII,
    IIIIIII,   M_OLD_Z,      KC_X,      KC_C,      KC_V,      KC_B,             KC_N,      KC_M,      KC_P,      KC_Q,     M_QUE,   IIIIIII,
    IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_RU] = LAYOUT_voyager(
    IIIIIII,   IIIIIII,    CYR_CC,     CYR_U,     CYR_K,     CYR_E,            CYR_N,     CYR_G,    CYR_SH,   CYR_SCH,   IIIIIII,   IIIIIII,
     CYR_YY,     CYR_F,    CYR_YI,     CYR_V,     CYR_A,     CYR_P,            CYR_R,     CYR_O,     CYR_L,     CYR_D,    CYR_ZH,    CYR_ZZ,
    CYR_SLD,    CYR_YA,    CYR_CH,    CYR_SS,     CYR_M,     CYR_I,            CYR_T,   CYR_SFT,     CYR_B,    CYR_YU,    CYR_YE,     CYR_H,
    IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_NUM] = LAYOUT_voyager(
    IIIIIII,   IIIIIII,      KC_7,      KC_8,      KC_9,   KC_PERC,          IIIIIII,   KC_HASH,  CKC_CURR,  KC_GRAVE,   IIIIIII,   IIIIIII,
    IIIIIII,  CKC_NDOT,     CKC_4,     CKC_5,     CKC_6,  CKC_CIRC,          KC_RCMD,    CKC_AT,  CKC_DOLL,   KC_ROPT,   KC_RCMD,   IIIIIII,
    IIIIIII,      KC_0,      KC_1,      KC_2,      KC_3,   IIIIIII,          IIIIIII,   KC_AMPR,   KC_PIPE,   KC_TILD,   IIIIIII,   IIIIIII,
    IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB

  ),
  [L_FN] = LAYOUT_voyager(
    IIIIIII,   IIIIIII,     KC_F7,      KC_F8,    KC_F9,    KC_F10,          IIIIIII,   KC_MPRV,   KC_MPLY,   KC_MNXT,   IIIIIII,   IIIIIII,
    IIIIIII,   KC_LGUI,    CKC_F4,     CKC_F5,   CKC_F6,   CKC_F11,         CKC_LEFT,  CKC_DOWN,    CKC_UP, CKC_RIGHT,  CKC_VOLU,   IIIIIII,
    IIIIIII,    M_SCRN,     KC_F1,      KC_F2,    KC_F3,    KC_F12,          KC_HOME, KC_PGDOWN,   KC_PGUP,    KC_END,   KC_VOLD,   IIIIIII,
    IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
};
