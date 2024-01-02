#pragma once

#include QMK_KEYBOARD_H
#include <sm_utils.h>

bool process_ru(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_A));
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_7:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_B));
            }
            break;
        case ST_MACRO_8:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_9:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_10:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_F));
            }
            break;
        case ST_MACRO_11:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_F));
            }
            break;
        case ST_MACRO_12:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_13:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_14:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_15:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_16:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_17:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_18:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_19:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_20:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_21:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_22:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_23:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_24:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_B));
            }
            break;
        case ST_MACRO_25:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_26:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_27:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_28:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_29:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_30:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_31:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_3) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_32:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_4) SS_TAP(X_A));
            }
            break;
        case ST_MACRO_33:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_34:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_35:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_36:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_A));
            }
            break;
        case ST_MACRO_37:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_38:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_39:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_B));
            }
            break;
        case ST_MACRO_40:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_41:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_42:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_F));
            }
            break;
        case ST_MACRO_43:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_F));
            }
            break;
        case ST_MACRO_44:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_45:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_46:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_47:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_48:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_49:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_50:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_51:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_52:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_53:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_54:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_55:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_56:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_B));
            }
            break;
        case ST_MACRO_57:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_58:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_59:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_60:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_61:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_62:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_63:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_1) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_64:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_0) SS_TAP(X_4) SS_TAP(X_2) SS_TAP(X_A));
            }
            break;
        case ST_MACRO_65:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_66:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_A) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_67:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_68:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_69:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_70:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_71:
            if (record->event.pressed) {
                SM_UNICODE(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_72:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_F12)));
            }
            break;
    }

    return true;
}
