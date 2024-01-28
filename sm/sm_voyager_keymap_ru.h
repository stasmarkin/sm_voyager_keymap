#pragma once

#include QMK_KEYBOARD_H
#include <sm_utils.h>

bool process_ru(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                register_unicode(0x2014);
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                register_unicode(0x0439);
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                register_unicode(0x0446);
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                register_unicode(0x0443);
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                register_unicode(0x043A);
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                register_unicode(0x0435);
            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
                register_unicode(0x0444);
            }
            break;
        case ST_MACRO_7:
            if (record->event.pressed) {
                register_unicode(0x044B);
            }
            break;
        case ST_MACRO_8:
            if (record->event.pressed) {
                register_unicode(0x0432);
            }
            break;
        case ST_MACRO_9:
            if (record->event.pressed) {
                register_unicode(0x0430);
            }
            break;
        case ST_MACRO_10:
            if (record->event.pressed) {
                register_unicode(0x043F);
            }
            break;
        case ST_MACRO_11:
            if (record->event.pressed) {
                register_unicode(0x044F);
            }
            break;
        case ST_MACRO_12:
            if (record->event.pressed) {
                register_unicode(0x0447);
            }
            break;
        case ST_MACRO_13:
            if (record->event.pressed) {
                register_unicode(0x0441);
            }
            break;
        case ST_MACRO_14:
            if (record->event.pressed) {
                register_unicode(0x043C);
            }
            break;
        case ST_MACRO_15:
            if (record->event.pressed) {
                register_unicode(0x0438);
            }
            break;
        case ST_MACRO_16:
            if (record->event.pressed) {
                register_unicode(0x043D);
            }
            break;
        case ST_MACRO_17:
            if (record->event.pressed) {
                register_unicode(0x0433);
            }
            break;
        case ST_MACRO_18:
            if (record->event.pressed) {
                register_unicode(0x0448);
            }
            break;
        case ST_MACRO_19:
            if (record->event.pressed) {
                register_unicode(0x0449);
            }
            break;
        case ST_MACRO_20:
            if (record->event.pressed) {
                register_unicode(0x0437);
            }
            break;
        case ST_MACRO_21:
            if (record->event.pressed) {
                register_unicode(0x0445);
            }
            break;
        case ST_MACRO_22:
            if (record->event.pressed) {
                register_unicode(0x0440);
            }
            break;
        case ST_MACRO_23:
            if (record->event.pressed) {
                register_unicode(0x043E);
            }
            break;
        case ST_MACRO_24:
            if (record->event.pressed) {
                register_unicode(0x043B);
            }
            break;
        case ST_MACRO_25:
            if (record->event.pressed) {
                register_unicode(0x0434);
            }
            break;
        case ST_MACRO_26:
            if (record->event.pressed) {
                register_unicode(0x044D);
            }
            break;
        case ST_MACRO_27:
            if (record->event.pressed) {
                register_unicode(0x0442);
            }
            break;
        case ST_MACRO_28:
            if (record->event.pressed) {
                register_unicode(0x044C);
            }
            break;
        case ST_MACRO_29:
            if (record->event.pressed) {
                register_unicode(0x0431);
            }
            break;
        case ST_MACRO_30:
            if (record->event.pressed) {
                register_unicode(0x044E);
            }
            break;
        case ST_MACRO_31:
            if (record->event.pressed) {
                register_unicode(0x0436);
            }
            break;
        case ST_MACRO_32:
            if (record->event.pressed) {
                register_unicode(0x044A);
            }
            break;
        case ST_MACRO_33:
            if (record->event.pressed) {
                register_unicode(0x0419);
            }
            break;
        case ST_MACRO_34:
            if (record->event.pressed) {
                register_unicode(0x0426);
            }
            break;
        case ST_MACRO_35:
            if (record->event.pressed) {
                register_unicode(0x0423);
            }
            break;
        case ST_MACRO_36:
            if (record->event.pressed) {
                register_unicode(0x041A);
            }
            break;
        case ST_MACRO_37:
            if (record->event.pressed) {
                register_unicode(0x0415);
            }
            break;
        case ST_MACRO_38:
            if (record->event.pressed) {
                register_unicode(0x0424);
            }
            break;
        case ST_MACRO_39:
            if (record->event.pressed) {
                register_unicode(0x042B);
            }
            break;
        case ST_MACRO_40:
            if (record->event.pressed) {
                register_unicode(0x0412);
            }
            break;
        case ST_MACRO_41:
            if (record->event.pressed) {
                register_unicode(0x0410);
            }
            break;
        case ST_MACRO_42:
            if (record->event.pressed) {
                register_unicode(0x041F);
            }
            break;
        case ST_MACRO_43:
            if (record->event.pressed) {
                register_unicode(0x042F);
            }
            break;
        case ST_MACRO_44:
            if (record->event.pressed) {
                register_unicode(0x0427);
            }
            break;
        case ST_MACRO_45:
            if (record->event.pressed) {
                register_unicode(0x0421);
            }
            break;
        case ST_MACRO_46:
            if (record->event.pressed) {
                register_unicode(0x041C);
            }
            break;
        case ST_MACRO_47:
            if (record->event.pressed) {
                register_unicode(0x0418);
            }
            break;
        case ST_MACRO_48:
            if (record->event.pressed) {
                register_unicode(0x041D);
            }
            break;
        case ST_MACRO_49:
            if (record->event.pressed) {
                register_unicode(0x0413);
            }
            break;
        case ST_MACRO_50:
            if (record->event.pressed) {
                register_unicode(0x0428);
            }
            break;
        case ST_MACRO_51:
            if (record->event.pressed) {
                register_unicode(0x0429);
            }
            break;
        case ST_MACRO_52:
            if (record->event.pressed) {
                register_unicode(0x0417);
            }
            break;
        case ST_MACRO_53:
            if (record->event.pressed) {
                register_unicode(0x0425);
            }
            break;
        case ST_MACRO_54:
            if (record->event.pressed) {
                register_unicode(0x0420);
            }
            break;
        case ST_MACRO_55:
            if (record->event.pressed) {
                register_unicode(0x041E);
            }
            break;
        case ST_MACRO_56:
            if (record->event.pressed) {
                register_unicode(0x041B);
            }
            break;
        case ST_MACRO_57:
            if (record->event.pressed) {
                register_unicode(0x0414);
            }
            break;
        case ST_MACRO_58:
            if (record->event.pressed) {
                register_unicode(0x042D);
            }
            break;
        case ST_MACRO_59:
            if (record->event.pressed) {
                register_unicode(0x0422);
            }
            break;
        case ST_MACRO_60:
            if (record->event.pressed) {
                register_unicode(0x042C);
            }
            break;
        case ST_MACRO_61:
            if (record->event.pressed) {
                register_unicode(0x0411);
            }
            break;
        case ST_MACRO_62:
            if (record->event.pressed) {
                register_unicode(0x042E);
            }
            break;
        case ST_MACRO_63:
            if (record->event.pressed) {
                register_unicode(0x0416);
            }
            break;
        case ST_MACRO_64:
            if (record->event.pressed) {
                register_unicode(0x042A);
            }
            break;
        case ST_MACRO_65:
            if (record->event.pressed) {
                register_unicode(0x2014);
            }
            break;
        case ST_MACRO_66:
            if (record->event.pressed) {
                register_unicode(0x20AC);
            }
            break;
        case ST_MACRO_67:
            if (record->event.pressed) {
                register_unicode(0x20BD);
            }
            break;
        case ST_MACRO_68:
            if (record->event.pressed) {
                register_unicode(0x2190);
            }
            break;
        case ST_MACRO_69:
            if (record->event.pressed) {
                register_unicode(0x2193);
            }
            break;
        case ST_MACRO_70:
            if (record->event.pressed) {
                register_unicode(0x2191);
            }
            break;
        case ST_MACRO_71:
            if (record->event.pressed) {
                register_unicode(0x2192);
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
