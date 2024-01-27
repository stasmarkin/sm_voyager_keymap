#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include "sm_voyager_combo.h"
#include "sm_voyager_rgb.h"
#include "sm_voyager_keymap_ru.h"
#include "sm_utils.h"
#include "sm_td.h"
#include "sm_td_user.h"

static uint8_t mods_before_macro = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) return false;
    if (!process_ru(keycode, record)) return false;

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
    }

    return true;
}
