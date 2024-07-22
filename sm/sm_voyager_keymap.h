#pragma once
#include QMK_KEYBOARD_H
#include "sm_layouts_keycodes.h"

#define IIIIIII KC_NO
#define   ___   KC_NO // no switches on a board


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

  M_EMPTY1,
  M_EMPTY2,

  SM_LAYOUTS_KEYCODES,
};

enum layers {
  L_EN = 0,
  L_RU,
  L_GAMING,
  L_NUM,
  L_FN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_EN] = LAYOUT_voyager(
      ___  ,     ___  ,      KC_W,      KC_E,      KC_R,      KC_T,             KC_Y,      KC_U,      KC_I,      KC_O,     ___  ,     ___  ,
    IIIIIII,     CKC_A,     CKC_S,     CKC_D,     CKC_F,     CKC_G,            CKC_H,     CKC_J,     CKC_K,     CKC_L,     CKC_Z,   IIIIIII,
    IIIIIII,   M_OLD_Z,      KC_X,      KC_C,      KC_V,      KC_B,             KC_N,      KC_M,      KC_P,      KC_Q,     M_QUE,   IIIIIII,
      ___  ,     ___  ,     ___  ,     ___  ,     ___  ,    KC_TAB,          IIIIIII,     ___  ,     ___  ,     ___  ,     ___  ,     ___  ,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_RU] = LAYOUT_voyager(
      ___  ,     ___  ,    CYR_CC,     CYR_U,     CYR_K,     CYR_E,            CYR_N,     CYR_G,    CYR_SH,   CYR_SCH,     ___  ,     ___  ,
     CYR_YY,     CYR_F,    CYR_YI,     CYR_V,     CYR_A,     CYR_P,            CYR_R,     CYR_O,     CYR_L,     CYR_D,    CYR_ZH,    CYR_YE,
    CYR_SLD,    CYR_YA,    CYR_CH,    CYR_SS,     CYR_M,     CYR_I,            CYR_T,   CYR_SFT,     CYR_B,    CYR_YU,    CYR_ZZ,     CYR_H,
      ___  ,     ___  ,     ___  ,     ___  ,     ___  ,    KC_TAB,          IIIIIII,     ___  ,     ___  ,     ___  ,     ___  ,     ___  ,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_GAMING] = LAYOUT_voyager(
      ___  ,     ___  ,      KC_Q,      KC_W,      KC_E,      KC_R,          IIIIIII,  M_EMPTY1,  M_EMPTY2,   IIIIIII,     ___  ,     ___  ,
    KC_LCMD,   KC_LSFT,      KC_A,      KC_S,      KC_D,      KC_F,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
    KC_LOPT,   KC_LCTL,      KC_Z,      KC_X,      KC_C,      KC_V,          IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,   IIIIIII,
      ___  ,     ___  ,     ___  ,     ___  ,     ___  ,    KC_TAB,          IIIIIII,     ___  ,     ___  ,     ___  ,     ___  ,     ___  ,
                                               KC_SPACE,  KC_ENTER,          CKC_ESC,   CKC_TAB
  ),
  [L_NUM] = LAYOUT_voyager(
      ___  ,     ___  ,      KC_7,      KC_8,      KC_9,   KC_PERC,          IIIIIII,   KC_HASH,  CKC_CURR,   IIIIIII,     ___  ,     ___  ,
    IIIIIII,  CKC_NDOT,     CKC_4,     CKC_5,     CKC_6,  CKC_CIRC,          KC_RCMD,    CKC_AT,  CKC_DOLL,   KC_ROPT,   KC_RCMD,   IIIIIII,
    IIIIIII,      KC_0,      KC_1,      KC_2,      KC_3,   IIIIIII,          IIIIIII,   KC_AMPR,   KC_PIPE,   KC_TILD,   IIIIIII,   IIIIIII,
      ___  ,     ___  ,     ___  ,     ___  ,     ___  ,    KC_TAB,          IIIIIII,     ___  ,     ___  ,     ___  ,     ___  ,     ___  ,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB

  ),
  [L_FN] = LAYOUT_voyager(
      ___  ,     ___  ,     KC_F7,      KC_F8,    KC_F9,    KC_F10,          IIIIIII,   KC_MPRV,   KC_MPLY,   KC_MNXT,     ___  ,     ___  ,
    IIIIIII,   KC_LGUI,    CKC_F4,     CKC_F5,   CKC_F6,   CKC_F11,         CKC_LEFT,  CKC_DOWN,    CKC_UP, CKC_RIGHT,  CKC_VOLU,   IIIIIII,
    IIIIIII,    M_SCRN,     KC_F1,      KC_F2,    KC_F3,    KC_F12,          KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,   KC_VOLD,   IIIIIII,
      ___  ,     ___  ,     ___  ,     ___  ,     ___  ,    KC_TAB,          IIIIIII,     ___  ,     ___  ,     ___  ,     ___  ,     ___  ,
                                              CKC_SPACE, CKC_ENTER,          CKC_ESC,   CKC_TAB
  ),
};
