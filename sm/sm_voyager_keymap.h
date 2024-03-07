#pragma once
#include QMK_KEYBOARD_H

enum custom_keycodes {
  SM_CYR_YY = ML_SAFE_RANGE,
  SM_CYR_CC,
  SM_CYR_U,
  SM_CYR_K,
  SM_CYR_E,
  SM_CYR_F,
  SM_CYR_YI,
  SM_CYR_V,
  SM_CYR_A,
  SM_CYR_P,
  SM_CYR_YA,
  SM_CYR_CH,
  SM_CYR_S,
  SM_CYR_M,
  SM_CYR_I,
  SM_CYR_N,
  SM_CYR_G,
  SM_CYR_SH,
  SM_CYR_SCH,
  SM_CYR_Z,
  SM_CYR_H,
  SM_CYR_R,
  SM_CYR_O,
  SM_CYR_L,
  SM_CYR_D,
  SM_CYR_EE,
  SM_CYR_T,
  SM_CYR_SOFT,
  SM_CYR_B,
  SM_CYR_YU,
  SM_CYR_ZH,
  SM_CYR_SOLID,
  SM_CYR_DOT,

  ST_MACRO_0,
  ST_MACRO_66,
  ST_MACRO_67,
  ST_MACRO_68,
  ST_MACRO_69,
  ST_MACRO_70,
  ST_MACRO_71,
  ST_MACRO_72,

  CKC_SPACE,
  CKC_ENTER,
  CKC_ESC,
  CKC_TAB,
  CKC_LANG,

  CKC_A,
  CKC_S,
  CKC_D,
  CKC_F,
  CKC_G,

  CKC_H,
  CKC_J,
  CKC_K,
  CKC_L,
  CKC_SEMICOLON,

  MACRO_TO_SEMICOLON,
  MACRO_TO_COLON,
  MACRO_TO_BSLASH,
  MACRO_SLSH_OR_COLON,

  CKC_KP_DOT,
  CKC_KP_4,
  CKC_KP_5,
  CKC_KP_6,
  CKC_LPRN_L,
  CKC_LABK,
  CKC_LCBR,
  CKC_LPRN_R,
  CKC_LBRACKET,
  CKC_DQUO,

  CKC_F4,
  CKC_F5,
  CKC_F6,
  CKC_F11,
  CKC_LEFT,
  CKC_DOWN,
  CKC_UP,
  CKC_RIGHT,
  CKC_MEDIA_PREV_TRACK,
};

enum layers {
  L_QWE_L = 0,
  L_QWE_U,
  L_CYR,
  L_NUM,
  L_FN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWE_L] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_BSPACE,      CKC_A,         CKC_S,          CKC_D,          CKC_F,          CKC_G,                                          CKC_H,          CKC_J,          CKC_K,          CKC_L,           CKC_SEMICOLON,   KC_TRANSPARENT,
    CKC_LANG,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_HASH,    MACRO_TO_COLON,  MACRO_TO_SEMICOLON, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_PLUS,     KC_KP_EQUAL,    KC_TAB,                                         KC_TRANSPARENT, KC_MINUS,       KC_AT,          KC_EXLM,        KC_QUES,        KC_TRANSPARENT,
                                                    CKC_SPACE,  CKC_ENTER,                                 CKC_ESC, CKC_TAB
  ),
  [L_QWE_U] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MACRO_TO_BSLASH,      KC_NO,          KC_NO,          KC_UNDS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_0,     KC_HASH,    MACRO_TO_COLON,  MACRO_TO_SEMICOLON,      KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [L_CYR] = LAYOUT_voyager(
    KC_TRANSPARENT, SM_CYR_YY,    SM_CYR_CC,    SM_CYR_U,    SM_CYR_K,    SM_CYR_E,                                    SM_CYR_N,    SM_CYR_G,    SM_CYR_SH,    SM_CYR_SCH,    SM_CYR_Z,    SM_CYR_H,
    KC_TRANSPARENT, SM_CYR_A,      SM_CYR_S,   SM_CYR_D,     SM_CYR_F,      SM_CYR_G,                                 SM_CYR_R,       SM_CYR_O,       SM_CYR_K,     SM_CYR_L,  SM_CYR_DOT, SM_CYR_EE,
    KC_TRANSPARENT, SM_CYR_YA,    SM_CYR_CH,    SM_CYR_S,    SM_CYR_M,    SM_CYR_I,                                    SM_CYR_T,    SM_CYR_SOFT,    SM_CYR_B,    SM_CYR_YU,    SM_CYR_ZH,    SM_CYR_SOLID,
    KC_TRANSPARENT, KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_PLUS,     KC_KP_EQUAL,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_AT,          KC_EXLM,        KC_QUES,        KC_TRANSPARENT,
    CKC_SPACE,  CKC_ENTER,                                 CKC_ESC, CKC_TAB
  ),
  [L_NUM] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_PERC,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_RPRN,                                        KC_RABK,        KC_RCBR,        KC_RPRN,        KC_RBRACKET,    KC_QUOTE,       KC_DLR,
    KC_TRANSPARENT, CKC_KP_DOT,     CKC_KP_4,       CKC_KP_5,       CKC_KP_6,       CKC_LPRN_L,                                     CKC_LABK, CKC_LCBR , CKC_LPRN_R,  CKC_LBRACKET, CKC_DQUO,    ST_MACRO_66,
    KC_TRANSPARENT, KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,                                    KC_CIRC,        KC_AMPR,        KC_PIPE,        KC_TILD,        KC_GRAVE,       ST_MACRO_67,
    KC_TRANSPARENT, MACRO_SLSH_OR_COLON,    KC_KP_ASTERISK, KC_KP_PLUS,     KC_KP_EQUAL,    KC_TRANSPARENT,                                 ST_MACRO_68,    ST_MACRO_69,    ST_MACRO_70,    ST_MACRO_71,    KC_NO,          KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [L_FN] = LAYOUT_voyager(
    KC_TRANSPARENT, ST_MACRO_72,    KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LGUI,        CKC_F4,  CKC_F5, CKC_F6,  CKC_F11,                                CKC_LEFT, CKC_DOWN, CKC_UP, CKC_RIGHT, CKC_MEDIA_PREV_TRACK, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F12,                                         KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
