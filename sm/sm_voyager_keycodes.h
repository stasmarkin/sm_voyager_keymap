#pragma once
#include QMK_KEYBOARD_H

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

  KC_SAFE_RANGE,
};

enum layers {
  L_EN = 0,
  L_RU,
  L_NUM,
  L_FN,
};
