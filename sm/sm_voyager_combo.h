#pragma once
#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include <timer.h>

#ifndef COMBO_TAP_TERM
#define COMBO_TAP_TERM TAPPING_TERM
#endif

#define CASE_COMBO1_TAP(combo1, key) \
    case combo1: \
        if (pressed) { \
            register_code16(key); \
        } else { \
            unregister_code16(key); \
        } \
        return;

#define CASE_COMBO2_TAP(combo1, combo2, key) \
    case combo2: \
    CASE_COMBO1_TAP(combo1, key)


enum combo_events {

// HOME ROW COMBOS
AS,
AD,
AF,
SD,
SF,
ASD,
ASF,
ADF,
SDF,
ASDF,

// CYRILLIC HOME ROW COMBOS
CYR_AS,
CYR_AD,
CYR_AF,
CYR_SD,
CYR_SF,
CYR_ASD,
CYR_ASF,
CYR_ADF,
CYR_SDF,
CYR_ASDF,

// SYSTEM COMBOS ON EN LAYOUT
AW,
ZX,
WE,
WR,
SE,
SC,
XC,
XD,
ER,
EF,
DR,
DF,
DV,
CV,

UI,
UO,
JI,
JK,
JL,
MK,
MP,
MQ,
PQ,

// SYSTEM COMBOS ON RU LAYOUT
AW_RU,
ZX_RU,
WE_RU,
WR_RU,
SE_RU,
SC_RU,
XC_RU,
XD_RU,
ER_RU,
EF_RU,
DR_RU,
DF_RU,
DV_RU,
CV_RU,
UI_RU,
UO_RU,
JI_RU,
JK_RU,
JL_RU,
MK_RU,
MP_RU,
MQ_RU,
PQ_RU,


};


const uint16_t PROGMEM combo_AS[] = { CKC_A, CKC_S, COMBO_END };
const uint16_t PROGMEM combo_AD[] = { CKC_A, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_AF[] = { CKC_A, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_SD[] = { CKC_S, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_SF[] = { CKC_S, CKC_F, COMBO_END };
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
const uint16_t PROGMEM combo_CYR_ASD[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASF[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ADF[] = { SM_CYR_F, SM_CYR_V, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_SDF[] = { SM_CYR_YI, SM_CYR_V, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASDF[] = { SM_CYR_F, SM_CYR_YI, SM_CYR_V, SM_CYR_A, COMBO_END };


const uint16_t PROGMEM combo_AW[] = { CKC_A, KC_W, COMBO_END };
const uint16_t PROGMEM combo_ZX[] = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM combo_WE[] = { KC_W, KC_E, COMBO_END };
const uint16_t PROGMEM combo_WR[] = { KC_W, KC_R, COMBO_END };
const uint16_t PROGMEM combo_SE[] = { CKC_S, KC_E, COMBO_END };
const uint16_t PROGMEM combo_SC[] = { CKC_S, KC_C, COMBO_END };
const uint16_t PROGMEM combo_XC[] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_XD[] = { KC_X, CKC_D, COMBO_END };
const uint16_t PROGMEM combo_ER[] = { KC_E, KC_R, COMBO_END };
const uint16_t PROGMEM combo_EF[] = { KC_E, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_DR[] = { CKC_D, KC_R, COMBO_END };
const uint16_t PROGMEM combo_DF[] = { CKC_D, CKC_F, COMBO_END };
const uint16_t PROGMEM combo_DV[] = { CKC_D, KC_V, COMBO_END };
const uint16_t PROGMEM combo_CV[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM combo_UI[] = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM combo_UO[] = { KC_U, KC_O, COMBO_END };
const uint16_t PROGMEM combo_JI[] = { CKC_J, KC_I, COMBO_END };
const uint16_t PROGMEM combo_JK[] = { CKC_J, CKC_K, COMBO_END };
const uint16_t PROGMEM combo_JL[] = { CKC_J, CKC_L, COMBO_END };
const uint16_t PROGMEM combo_MK[] = { KC_M, CKC_K, COMBO_END };
const uint16_t PROGMEM combo_MP[] = { KC_M, KC_P, COMBO_END };
const uint16_t PROGMEM combo_MQ[] = { KC_M, KC_Q, COMBO_END };
const uint16_t PROGMEM combo_PQ[] = { KC_P, KC_Q, COMBO_END };


const uint16_t PROGMEM combo_AW_RU[] = { SM_CYR_F, SM_CYR_CC, COMBO_END };
const uint16_t PROGMEM combo_ZX_RU[] = { SM_CYR_YA, SM_CYR_CH, COMBO_END };
const uint16_t PROGMEM combo_WE_RU[] = { SM_CYR_CC, SM_CYR_U, COMBO_END };
const uint16_t PROGMEM combo_WR_RU[] = { SM_CYR_CC, SM_CYR_K, COMBO_END };
const uint16_t PROGMEM combo_SE_RU[] = { SM_CYR_YI, SM_CYR_U, COMBO_END };
const uint16_t PROGMEM combo_SC_RU[] = { SM_CYR_YI, SM_CYR_S, COMBO_END };
const uint16_t PROGMEM combo_XC_RU[] = { SM_CYR_CH, SM_CYR_S, COMBO_END };
const uint16_t PROGMEM combo_XD_RU[] = { SM_CYR_CH, SM_CYR_B, COMBO_END };
const uint16_t PROGMEM combo_ER_RU[] = { SM_CYR_U, SM_CYR_K, COMBO_END };
const uint16_t PROGMEM combo_EF_RU[] = { SM_CYR_U, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_DR_RU[] = { SM_CYR_B, SM_CYR_K, COMBO_END };
const uint16_t PROGMEM combo_DF_RU[] = { SM_CYR_B, SM_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_DV_RU[] = { SM_CYR_B, SM_CYR_M, COMBO_END };
const uint16_t PROGMEM combo_CV_RU[] = { SM_CYR_S, SM_CYR_M, COMBO_END };
const uint16_t PROGMEM combo_UI_RU[] = { SM_CYR_G, SM_CYR_SH, COMBO_END };
const uint16_t PROGMEM combo_UO_RU[] = { SM_CYR_G, SM_CYR_SCH, COMBO_END };
const uint16_t PROGMEM combo_JI_RU[] = { SM_CYR_O, SM_CYR_SH, COMBO_END };
const uint16_t PROGMEM combo_JK_RU[] = { SM_CYR_O, SM_CYR_L, COMBO_END };
const uint16_t PROGMEM combo_JL_RU[] = { SM_CYR_O, SM_CYR_D, COMBO_END };
const uint16_t PROGMEM combo_MK_RU[] = { SM_CYR_SOFT, SM_CYR_L, COMBO_END };
const uint16_t PROGMEM combo_MP_RU[] = { SM_CYR_SOFT, SM_CYR_B, COMBO_END };
const uint16_t PROGMEM combo_MQ_RU[] = { SM_CYR_SOFT, SM_CYR_YU, COMBO_END };
const uint16_t PROGMEM combo_PQ_RU[] = { SM_CYR_B, SM_CYR_YU, COMBO_END };


combo_t key_combos[COMBO_COUNT] = {
    [AS] = COMBO_ACTION(combo_AS),
    [AD] = COMBO_ACTION(combo_AD),
    [AF] = COMBO_ACTION(combo_AF),
    [SD] = COMBO_ACTION(combo_SD),
    [SF] = COMBO_ACTION(combo_SF),
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
    [CYR_ASD] = COMBO_ACTION(combo_CYR_ASD),
    [CYR_ASF] = COMBO_ACTION(combo_CYR_ASF),
    [CYR_ADF] = COMBO_ACTION(combo_CYR_ADF),
    [CYR_SDF] = COMBO_ACTION(combo_CYR_SDF),
    [CYR_ASDF] = COMBO_ACTION(combo_CYR_ASDF),

    [AW] = COMBO_ACTION(combo_AW),
    [ZX] = COMBO_ACTION(combo_ZX),
    [WE] = COMBO_ACTION(combo_WE),
    [WR] = COMBO_ACTION(combo_WR),
    [SE] = COMBO_ACTION(combo_SE),
    [SC] = COMBO_ACTION(combo_SC),
    [XC] = COMBO_ACTION(combo_XC),
    [XD] = COMBO_ACTION(combo_XD),
    [ER] = COMBO_ACTION(combo_ER),
    [EF] = COMBO_ACTION(combo_EF),
    [DR] = COMBO_ACTION(combo_DR),
    [DF] = COMBO_ACTION(combo_DF),
    [DV] = COMBO_ACTION(combo_DV),
    [CV] = COMBO_ACTION(combo_CV),
    [UI] = COMBO_ACTION(combo_UI),
    [UO] = COMBO_ACTION(combo_UO),
    [JI] = COMBO_ACTION(combo_JI),
    [JK] = COMBO_ACTION(combo_JK),
    [JL] = COMBO_ACTION(combo_JL),
    [MK] = COMBO_ACTION(combo_MK),
    [MP] = COMBO_ACTION(combo_MP),
    [MQ] = COMBO_ACTION(combo_MQ),
    [PQ] = COMBO_ACTION(combo_PQ),

    [AW_RU] = COMBO_ACTION(combo_AW_RU),
    [ZX_RU] = COMBO_ACTION(combo_ZX_RU),
    [WE_RU] = COMBO_ACTION(combo_WE_RU),
    [WR_RU] = COMBO_ACTION(combo_WR_RU),
    [SE_RU] = COMBO_ACTION(combo_SE_RU),
    [SC_RU] = COMBO_ACTION(combo_SC_RU),
    [XC_RU] = COMBO_ACTION(combo_XC_RU),
    [XD_RU] = COMBO_ACTION(combo_XD_RU),
    [ER_RU] = COMBO_ACTION(combo_ER_RU),
    [EF_RU] = COMBO_ACTION(combo_EF_RU),
    [DR_RU] = COMBO_ACTION(combo_DR_RU),
    [DF_RU] = COMBO_ACTION(combo_DF_RU),
    [DV_RU] = COMBO_ACTION(combo_DV_RU),
    [CV_RU] = COMBO_ACTION(combo_CV_RU),
    [UI_RU] = COMBO_ACTION(combo_UI_RU),
    [UO_RU] = COMBO_ACTION(combo_UO_RU),
    [JI_RU] = COMBO_ACTION(combo_JI_RU),
    [JK_RU] = COMBO_ACTION(combo_JK_RU),
    [JL_RU] = COMBO_ACTION(combo_JL_RU),
    [MK_RU] = COMBO_ACTION(combo_MK_RU),
    [MP_RU] = COMBO_ACTION(combo_MP_RU),
    [MQ_RU] = COMBO_ACTION(combo_MQ_RU),
    [PQ_RU] = COMBO_ACTION(combo_PQ_RU),
};


static uint8_t mods_before_combo = 0;
static uint32_t last_combo_pressed = 0;


void process_combo_event(uint16_t combo_index, bool pressed) {

    switch (combo_index) {
        CASE_COMBO2_TAP(AW, AW_RU, KC_ESC)
        CASE_COMBO2_TAP(ZX, ZX_RU, KC_UNDS)
        CASE_COMBO2_TAP(WE, WE_RU, KC_PLUS)
        CASE_COMBO2_TAP(WR, WR_RU, KC_LPRN)
        CASE_COMBO2_TAP(SE, SE_RU, KC_ASTR)
        CASE_COMBO2_TAP(SC, SC_RU, KC_BSLS)
        CASE_COMBO2_TAP(XC, XC_RU, KC_MINS)
        CASE_COMBO2_TAP(XD, XD_RU, KC_SLSH)
        CASE_COMBO2_TAP(ER, ER_RU, KC_RPRN)
        CASE_COMBO2_TAP(DF, DF_RU, KC_BSPC)
        CASE_COMBO2_TAP(DV, DV_RU, KC_ENT)
        CASE_COMBO2_TAP(CV, CV_RU, KC_EQL)
        CASE_COMBO2_TAP(UI, UI_RU, KC_LABK)
        CASE_COMBO2_TAP(UO, UO_RU, KC_RABK)
        CASE_COMBO2_TAP(JI, JI_RU, KC_SCLN)
        CASE_COMBO2_TAP(JK, JK_RU, KC_LCBR)
        CASE_COMBO2_TAP(JL, JL_RU, KC_RCBR)
        CASE_COMBO2_TAP(MK, MK_RU, KC_COLN)
        CASE_COMBO2_TAP(MP, MP_RU, KC_LBRC)
        CASE_COMBO2_TAP(MQ, MQ_RU, KC_RBRC)

        case PQ:
            if (pressed) {
                register_unicode(0x2014);
            }
            return;

        case EF:
            if (pressed) {
                register_code(KC_LCMD);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_LCMD);
            }
            return;

        case DR:
            if (pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSHIFT);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCMD);
            }
            return;

        default: break;
    }

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
