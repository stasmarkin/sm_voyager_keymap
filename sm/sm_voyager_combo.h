#pragma once
#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include "sm_layouts.h"
#include "sm_td.h"
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

#define CASE_COMBO3_TAP(combo1, combo2, combo3, key) \
    case combo3: \
    case combo2: \
    CASE_COMBO1_TAP(combo1, key)


enum combo_events {

// LANG SWITCH COMBOS
XCV,
MPQ,
XCV_RU,
MPQ_RU,
ERUI,
ERUI_GAMING,

// CAPSWORD
FJ,
CYR_FJ,

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
IO,
IL,
KL,
KQ,
PQ,
OZ,
LDOT,
QQUE,

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
IO_RU,
IL_RU,
KL_RU,
KQ_RU,
PQ_RU,
OZ_RU,
LDOT_RU,
QQUE_RU,


// SYSTEM COMBOS ON NUM LAYOUT
AW_NUM,
ZX_NUM,
WE_NUM,
WR_NUM,
SE_NUM,
SC_NUM,
XC_NUM,
XD_NUM,
ER_NUM,
EF_NUM,
DR_NUM,
DF_NUM,
DV_NUM,
CV_NUM,

};

const uint16_t PROGMEM combo_XCV[] = { KC_X, KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM combo_MPQ[] = { KC_M, KC_P, KC_Q, COMBO_END };
const uint16_t PROGMEM combo_XCV_RU[] = { CYR_CH, CYR_SS, CYR_M, COMBO_END };
const uint16_t PROGMEM combo_MPQ_RU[] = { CYR_SFT, CYR_B, CYR_YU, COMBO_END };
const uint16_t PROGMEM combo_ERUI[] = { KC_E, KC_R, KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM combo_ERUI_GAMING[] = { KC_W, KC_E, M_EMPTY1, M_EMPTY2, COMBO_END };

const uint16_t PROGMEM combo_FJ[] = { CKC_F, CKC_J, COMBO_END };
const uint16_t PROGMEM combo_CYR_FJ[] = { CKC_CYR_A, CKC_CYR_O, COMBO_END };

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

const uint16_t PROGMEM combo_CYR_AS[] = { CKC_CYR_F, CKC_CYR_YI, COMBO_END };
const uint16_t PROGMEM combo_CYR_AD[] = { CKC_CYR_F, CKC_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_AF[] = { CKC_CYR_F, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_SD[] = { CKC_CYR_YI, CKC_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_SF[] = { CKC_CYR_YI, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASD[] = { CKC_CYR_F, CKC_CYR_YI, CKC_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASF[] = { CKC_CYR_F, CKC_CYR_YI, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ADF[] = { CKC_CYR_F, CKC_CYR_V, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_SDF[] = { CKC_CYR_YI, CKC_CYR_V, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_CYR_ASDF[] = { CKC_CYR_F, CKC_CYR_YI, CKC_CYR_V, CKC_CYR_A, COMBO_END };


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
const uint16_t PROGMEM combo_IO[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM combo_IL[] = { KC_I, CKC_L, COMBO_END };
const uint16_t PROGMEM combo_KL[] = { CKC_K, CKC_L, COMBO_END };
const uint16_t PROGMEM combo_KQ[] = { CKC_K, KC_Q, COMBO_END };
const uint16_t PROGMEM combo_PQ[] = { KC_P, KC_Q, COMBO_END };
const uint16_t PROGMEM combo_OZ[] = { KC_O, KC_RCMD, COMBO_END };
const uint16_t PROGMEM combo_LDOT[] = { CKC_L, KC_RCMD, COMBO_END };
const uint16_t PROGMEM combo_QQUE[] = { KC_Q, M_QUE, COMBO_END };


const uint16_t PROGMEM combo_AW_RU[] = { CKC_CYR_F, CYR_CC, COMBO_END };
const uint16_t PROGMEM combo_ZX_RU[] = { CYR_YA, CYR_CH, COMBO_END };
const uint16_t PROGMEM combo_WE_RU[] = { CYR_CC, CYR_U, COMBO_END };
const uint16_t PROGMEM combo_WR_RU[] = { CYR_CC, CYR_K, COMBO_END };
const uint16_t PROGMEM combo_SE_RU[] = { CKC_CYR_YI, CYR_U, COMBO_END };
const uint16_t PROGMEM combo_SC_RU[] = { CKC_CYR_YI, CYR_SS, COMBO_END };
const uint16_t PROGMEM combo_XC_RU[] = { CYR_CH, CYR_SS, COMBO_END };
const uint16_t PROGMEM combo_XD_RU[] = { CYR_CH, CKC_CYR_V, COMBO_END };
const uint16_t PROGMEM combo_ER_RU[] = { CYR_U, CYR_K, COMBO_END };
const uint16_t PROGMEM combo_EF_RU[] = { CYR_U, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_DR_RU[] = { CKC_CYR_V, CYR_K, COMBO_END };
const uint16_t PROGMEM combo_DF_RU[] = { CKC_CYR_V, CKC_CYR_A, COMBO_END };
const uint16_t PROGMEM combo_DV_RU[] = { CKC_CYR_V, CYR_M, COMBO_END };
const uint16_t PROGMEM combo_CV_RU[] = { CYR_SS, CYR_M, COMBO_END };
const uint16_t PROGMEM combo_UI_RU[] = { CYR_G, CYR_SH, COMBO_END };
const uint16_t PROGMEM combo_UO_RU[] = { CYR_G, CYR_SCH, COMBO_END };
const uint16_t PROGMEM combo_JI_RU[] = { CKC_CYR_O, CYR_SH, COMBO_END };
const uint16_t PROGMEM combo_JK_RU[] = { CKC_CYR_O, CKC_CYR_L, COMBO_END };
const uint16_t PROGMEM combo_JL_RU[] = { CKC_CYR_O, CKC_CYR_D, COMBO_END };
const uint16_t PROGMEM combo_MK_RU[] = { CYR_SFT, CKC_CYR_L, COMBO_END };
const uint16_t PROGMEM combo_MP_RU[] = { CYR_SFT, CYR_B, COMBO_END };
const uint16_t PROGMEM combo_MQ_RU[] = { CYR_SFT, CYR_YU, COMBO_END };
const uint16_t PROGMEM combo_IO_RU[] = { CYR_SH, CYR_SCH, COMBO_END };
const uint16_t PROGMEM combo_IL_RU[] = { CYR_SH, CKC_CYR_D, COMBO_END };
const uint16_t PROGMEM combo_KL_RU[] = { CKC_CYR_L, CKC_CYR_D, COMBO_END };
const uint16_t PROGMEM combo_KQ_RU[] = { CKC_CYR_L, CYR_YU, COMBO_END };
const uint16_t PROGMEM combo_PQ_RU[] = { CYR_B, CYR_YU, COMBO_END };
const uint16_t PROGMEM combo_OZ_RU[] = { CYR_SCH, CKC_CYR_ZH, COMBO_END };
const uint16_t PROGMEM combo_LDOT_RU[] = { CKC_CYR_D, CKC_CYR_ZH, COMBO_END };
const uint16_t PROGMEM combo_QQUE_RU[] = { CYR_YU, CYR_ZZ, COMBO_END };


const uint16_t PROGMEM combo_AW_NUM[] = { CKC_NDOT, KC_7, COMBO_END };
const uint16_t PROGMEM combo_ZX_NUM[] = { KC_0, KC_1, COMBO_END };
const uint16_t PROGMEM combo_WE_NUM[] = { KC_7, KC_8, COMBO_END };
const uint16_t PROGMEM combo_WR_NUM[] = { KC_7, KC_9, COMBO_END };
const uint16_t PROGMEM combo_SE_NUM[] = { CKC_4, KC_8, COMBO_END };
const uint16_t PROGMEM combo_SC_NUM[] = { CKC_4, KC_2, COMBO_END };
const uint16_t PROGMEM combo_XC_NUM[] = { KC_1, KC_2, COMBO_END };
const uint16_t PROGMEM combo_XD_NUM[] = { KC_1, CKC_5, COMBO_END };
const uint16_t PROGMEM combo_ER_NUM[] = { KC_8, KC_9, COMBO_END };
const uint16_t PROGMEM combo_EF_NUM[] = { KC_8, CKC_6, COMBO_END };
const uint16_t PROGMEM combo_DR_NUM[] = { CKC_5, KC_9, COMBO_END };
const uint16_t PROGMEM combo_DF_NUM[] = { CKC_5, CKC_6, COMBO_END };
const uint16_t PROGMEM combo_DV_NUM[] = { CKC_5, KC_3, COMBO_END };
const uint16_t PROGMEM combo_CV_NUM[] = { KC_2, KC_3, COMBO_END };





combo_t key_combos[COMBO_COUNT] = {
    [XCV] = COMBO_ACTION(combo_XCV),
    [MPQ] = COMBO_ACTION(combo_MPQ),
    [XCV_RU] = COMBO_ACTION(combo_XCV_RU),
    [MPQ_RU] = COMBO_ACTION(combo_MPQ_RU),
    [ERUI] = COMBO_ACTION(combo_ERUI),
    [ERUI_GAMING] = COMBO_ACTION(combo_ERUI_GAMING),

    [FJ] = COMBO_ACTION(combo_FJ),
    [CYR_FJ] = COMBO_ACTION(combo_CYR_FJ),

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
    [IO] = COMBO_ACTION(combo_IO),
    [IL] = COMBO_ACTION(combo_IL),
    [KL] = COMBO_ACTION(combo_KL),
    [KQ] = COMBO_ACTION(combo_KQ),
    [PQ] = COMBO_ACTION(combo_PQ),
    [OZ] = COMBO_ACTION(combo_OZ),
    [LDOT] = COMBO_ACTION(combo_LDOT),
    [QQUE] = COMBO_ACTION(combo_QQUE),

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
    [IO_RU] = COMBO_ACTION(combo_IO_RU),
    [IL_RU] = COMBO_ACTION(combo_IL_RU),
    [KL_RU] = COMBO_ACTION(combo_KL_RU),
    [KQ_RU] = COMBO_ACTION(combo_KQ_RU),
    [PQ_RU] = COMBO_ACTION(combo_PQ_RU),
    [OZ_RU] = COMBO_ACTION(combo_OZ_RU),
    [LDOT_RU] = COMBO_ACTION(combo_LDOT_RU),
    [QQUE_RU] = COMBO_ACTION(combo_QQUE_RU),

    [AW_NUM] = COMBO_ACTION(combo_AW_NUM),
    [ZX_NUM] = COMBO_ACTION(combo_ZX_NUM),
    [WE_NUM] = COMBO_ACTION(combo_WE_NUM),
    [WR_NUM] = COMBO_ACTION(combo_WR_NUM),
    [SE_NUM] = COMBO_ACTION(combo_SE_NUM),
    [SC_NUM] = COMBO_ACTION(combo_SC_NUM),
    [XC_NUM] = COMBO_ACTION(combo_XC_NUM),
    [XD_NUM] = COMBO_ACTION(combo_XD_NUM),
    [ER_NUM] = COMBO_ACTION(combo_ER_NUM),
    [EF_NUM] = COMBO_ACTION(combo_EF_NUM),
    [DR_NUM] = COMBO_ACTION(combo_DR_NUM),
    [DF_NUM] = COMBO_ACTION(combo_DF_NUM),
    [DV_NUM] = COMBO_ACTION(combo_DV_NUM),
    [CV_NUM] = COMBO_ACTION(combo_CV_NUM),
};


static uint8_t mods_before_combo = 0;
static uint32_t last_combo_pressed = 0;


void process_combo_event(uint16_t combo_index, bool pressed) {

    switch (combo_index) {
        CASE_COMBO3_TAP(AW, AW_RU, AW_NUM, KC_ESC)
        CASE_COMBO3_TAP(ZX, ZX_RU, ZX_NUM, KC_UNDS)
        CASE_COMBO3_TAP(WE, WE_RU, WE_NUM, KC_PLUS)
        CASE_COMBO3_TAP(WR, WR_RU, WR_NUM, KC_RPRN)
        CASE_COMBO3_TAP(SE, SE_RU, SE_NUM, KC_ASTR)
        CASE_COMBO3_TAP(SC, SC_RU, SC_NUM, KC_BSLS)
        CASE_COMBO3_TAP(XC, XC_RU, XC_NUM, KC_MINS)
        CASE_COMBO3_TAP(XD, XD_RU, XD_NUM, KC_SLSH)
        CASE_COMBO3_TAP(ER, ER_RU, ER_NUM, KC_LPRN)
        CASE_COMBO3_TAP(DV, DV_RU, DV_NUM, KC_ENT)
        CASE_COMBO3_TAP(CV, CV_RU, CV_NUM, KC_EQL)

        CASE_COMBO2_TAP(UI, UI_RU, KC_COLN)
        CASE_COMBO2_TAP(UO, UO_RU, KC_LABK)
        CASE_COMBO2_TAP(JI, JI_RU, KC_SCLN)
        CASE_COMBO2_TAP(JK, JK_RU, KC_DOT)
        CASE_COMBO2_TAP(JL, JL_RU, KC_LCBR)
        CASE_COMBO2_TAP(MK, MK_RU, KC_COMMA)
        CASE_COMBO2_TAP(MQ, MQ_RU, KC_LBRC)
        CASE_COMBO2_TAP(IO, IO_RU, KC_RABK)
        CASE_COMBO2_TAP(IL, IL_RU, KC_EXLM)
        CASE_COMBO2_TAP(KL, KL_RU, KC_RCBR)
        CASE_COMBO2_TAP(KQ, KQ_RU, KC_QUES)
        CASE_COMBO2_TAP(PQ, PQ_RU, KC_RBRC)
        CASE_COMBO2_TAP(OZ, OZ_RU, KC_GRAVE)
        CASE_COMBO2_TAP(LDOT, LDOT_RU, KC_DQUO)
        CASE_COMBO2_TAP(QQUE, QQUE_RU, KC_QUOTE)

        case DF:
        case DF_NUM:
        case DF_RU: {
            keyrecord_t record = {.event = MAKE_KEYEVENT(0, 0, pressed)};
            process_smtd(CKC_DF_COMBO, &record);
            return;
        }

        case XCV:
        case XCV_RU:
        case ERUI_GAMING: {
            if (!pressed) return;

            uint8_t current_mods = get_mods();
            if (current_mods & MOD_MASK_SHIFT) {
                unregister_mods(current_mods);
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
                unregister_mods(MOD_BIT(KC_LCTL));

                wait_ms(25);
                register_code(KC_T);
                unregister_code(KC_T);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);

                register_mods(current_mods);
            }

            layer_move(L_EN);
            return;
        }

        case MPQ:
        case MPQ_RU: {
            if (!pressed) return;

             uint8_t current_mods = get_mods();
             if (current_mods & MOD_MASK_SHIFT) {
                 unregister_mods(current_mods);
                 register_mods(MOD_BIT(KC_LCTL));
                 register_code(KC_SPACE);
                 unregister_code(KC_SPACE);
                 unregister_mods(MOD_BIT(KC_LCTL));

                 wait_ms(25);
                 register_code(KC_T);
                 unregister_code(KC_T);
                 register_code(KC_SPACE);
                 unregister_code(KC_SPACE);

                 register_mods(current_mods);
             }

            layer_move(L_RU);
            return;
        }

        case ERUI:
            if (pressed) {
                layer_move(L_GAMING);
            }
            return;

        case FJ:
        case CYR_FJ:
            if (pressed) {
                caps_word_toggle();
            }
            return;

        case MP:
        case MP_RU:
            if (pressed) {
                register_unicode(0x2014);
            }
            return;

        case EF:
        case EF_RU:
            if (pressed) {
                register_code(KC_LCMD);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_LCMD);
            }
            return;

        case DR:
        case DR_RU:
            if (pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSFT);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_LSFT);
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
