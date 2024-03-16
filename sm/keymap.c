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

        case MACRO_EM_DASH:
            if (record->event.pressed) {
                register_unicode(0x2014);
                return false;
            }
            break;
        case MACRO_EURO:
            if (record->event.pressed) {
                register_unicode(0x20AC);
                return false;
            }
            break;
        case MACRO_RUBLE:
            if (record->event.pressed) {
                register_unicode(0x20BD);
                return false;
            }
            break;
        case MACRO_SCREENSHOT:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_F12)));
                return false;
            }
            break;
    };

    return true;
}
