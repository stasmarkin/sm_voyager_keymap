#pragma once
#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include <timer.h>

#ifndef COMBO_TAP_TERM
#define COMBO_TAP_TERM TAPPING_TERM
#endif

enum combo_events {
AS,
AD,
AF,
SD,
SF,
DF,
ASD,
ASF,
ADF,
SDF,
ASDF,

CYR_AS,
CYR_AD,
CYR_AF,
CYR_SD,
CYR_SF,
CYR_DF,
CYR_ASD,
CYR_ASF,
CYR_ADF,
CYR_SDF,
CYR_ASDF,

};


const uint16_t PROGMEM combo_AS[] = { CKC_A, CKC_S, COMBO_END };
const uint16_t PROGMEM combo_AD[] = { CKC_A, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_AF[] = { CKC_A, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_SD[] = { CKC_S, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_SF[] = { CKC_S, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_DF[] = { CKC_D, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_ASD[] = { CKC_A, CKC_S, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_ASF[] = { CKC_A, CKC_S, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_ADF[] = { CKC_A, CKC_D, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_SDF[] = { CKC_S, CKC_D, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_ASDF[] = { CKC_A, CKC_S, CKC_D, CKC_F, COMBO_END };

const uint16_t PROGMEM combo_CYR_AS[] = { SM_CYR_F, SM_CYR_YI, COMBO_END };
const uint16_t PROGMEM combo_CYR_AD[] = { SM_CYR_F, SM_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_AF[] = { SM_CYR_F, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_SD[] = { SM_CYR_YI, SM_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_SF[] = { SM_CYR_YI, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_DF[] = { SM_CYR_V, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASD[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASF[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ADF[] = { SM_CYR_F, SM_CYR_V, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_SDF[] = { SM_CYR_YI, SM_CYR_V, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASDF[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_V, SM_CYR_A, COMBO_END };


combo_t key_combos[COMBO_COUNT] = {
    [AS] = COMBO_ACTION(combo_AS),
    [AD] = COMBO_ACTION(combo_AD),
    [AF] = COMBO_ACTION(combo_AF),
    [SD] = COMBO_ACTION(combo_SD),
    [SF] = COMBO_ACTION(combo_SF),
    [DF] = COMBO_ACTION(combo_DF),
    [ASD] = COMBO_ACTION(combo_ASD),
    [ASF] = COMBO_ACTION(combo_ASF),
    [ADF] = COMBO_ACTION(combo_ADF),
    [SDF] = COMBO_ACTION(combo_SDF),
    [ASDF] = COMBO_ACTION(combo_ASDF),

    [CYR_AS] = COMBO_ACTION(combo_CYR_AS),
    [CYR_AD] = COMBO_ACTION(combo_CYR_AD),
    [CYR_AF] = COMBO_ACTION(combo_CYR_AF),
    [CYR_SD] = COMBO_ACTION(combo_CYR_SD),
    [CYR_SF] = COMBO_ACTION(combo_CYR_SF),
    [CYR_DF] = COMBO_ACTION(combo_CYR_DF),
    [CYR_ASD] = COMBO_ACTION(combo_CYR_ASD),
    [CYR_ASF] = COMBO_ACTION(combo_CYR_ASF),
    [CYR_ADF] = COMBO_ACTION(combo_CYR_ADF),
    [CYR_SDF] = COMBO_ACTION(combo_CYR_SDF),
    [CYR_ASDF] = COMBO_ACTION(combo_CYR_ASDF),
};


static uint8_t mods_before_combo = 0;
static uint32_t last_combo_pressed = 0;


void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        mods_before_combo = get_mods();
    }

  switch(combo_index) {

    case AS:
    case CYR_AS:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case AD:
    case CYR_AD:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case AF:
    case CYR_AF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case SD:
    case CYR_SD:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case SF:
    case CYR_SF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case DF:
    case CYR_DF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case ASD:
    case CYR_ASD:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case ASF:
    case CYR_ASF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case ADF:
    case CYR_ADF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case SDF:
    case CYR_SDF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;

    case ASDF:
    case CYR_ASDF:
        if (pressed) {
            mods_before_combo = timer_read32();
            add_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            send_keyboard_report();
        } else {
            del_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            if (((int32_t) TIMER_DIFF_32(timer_read32(), last_combo_pressed)) < COMBO_TAP_TERM) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_LEFT_SHIFT));
            } else {
                send_keyboard_report();
            }
        }

        break;
  }

  if (pressed) {
      last_combo_pressed = timer_read32();
  }
}
