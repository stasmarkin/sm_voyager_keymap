#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include "sm_voyager_combo.h"
#include "sm_voyager_rgb.h"
#include "sm_cyr_layer/sm_cyr_layer.h"
#include "sm_utils.h"
#include "sm_td.h"
#include "sm_td_user.h"

static uint8_t mods_before_macro = 0;

bool process_smunicode(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) return false;
    if (!process_smcyr(keycode, record)) return false;
    if (!process_smunicode(keycode, record)) return false;

    return true;
}

bool process_smunicode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_TO_SEMICOLON:
            if (record->event.pressed) {
                mods_before_macro = get_mods();
                unregister_mods(mods_before_macro);
                register_code(KC_SCOLON);
            } else {
                unregister_code(KC_SCOLON);
                register_mods(mods_before_macro);
            }
            return false;

        case MACRO_TO_COLON:
            if (record->event.pressed) {
                mods_before_macro = get_mods();
                del_mods(mods_before_macro);
                register_mods(MOD_BIT(KC_LSFT));
                register_code(KC_SCOLON);
            } else {
                unregister_code(KC_SCOLON);
                del_mods(MOD_BIT(KC_LSFT));
                register_mods(mods_before_macro);
            }
            return false;

        case MACRO_TO_BSLASH:
            if (record->event.pressed) {
                mods_before_macro = get_mods();
                unregister_mods(mods_before_macro);
                register_code(KC_BSLASH);
            } else {
                unregister_code(KC_BSLASH);
                register_mods(mods_before_macro);
            }
            return false;

        case ST_MACRO_0:
            if (record->event.pressed) {
                register_unicode(0x2014);
                return false;
            }
            break;
        case ST_MACRO_66:
            if (record->event.pressed) {
                register_unicode(0x20AC);
                return false;
            }
            break;
        case ST_MACRO_67:
            if (record->event.pressed) {
                register_unicode(0x20BD);
                return false;
            }
            break;
        case ST_MACRO_68:
            if (record->event.pressed) {
                register_unicode(0x2190);
                return false;
            }
            break;
        case ST_MACRO_69:
            if (record->event.pressed) {
                register_unicode(0x2193);
                return false;
            }
            break;
        case ST_MACRO_70:
            if (record->event.pressed) {
                register_unicode(0x2191);
                return false;
            }
            break;
        case ST_MACRO_71:
            if (record->event.pressed) {
                register_unicode(0x2192);
                return false;
            }
            break;
        case ST_MACRO_72:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_F12)));
                return false;
            }
            break;
    };

    return true;
}
