#pragma once

#include <sm_voyager_keymaps.h>

#define SMCYR_SIZE 33 //fixme
#define SMCYR_FIRST_IDX SM_CYR_YY //fixme
#define SMCYR_LAST_IDX SM_CYR_SOLID //fixme

#ifndef START_OF_SM_CYR_KEYCODES
#    define START_OF_SM_CYR_KEYCODES KC_SAFE_RANGE
#endif

enum sm_cyr_keycodes {
  SM_CYR_YY = START_OF_SM_CYR_KEYCODES,
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
  SM_CYR_YO,
  SM_CYR_L,
  SM_CYR_D,
  SM_CYR_EE,
  SM_CYR_T,
  SM_CYR_SOFT,
  SM_CYR_B,
  SM_CYR_YU,
  SM_CYR_ZH,
  SM_CYR_SOLID,

  END_OF_SM_CYR_KEYCODES,
};
