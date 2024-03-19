#include QMK_KEYBOARD_H
#include "sm_voyager_keymap.h"
#include "sm_voyager_combo.h"
#include "sm_voyager_rgb.h"
#include "sm_cyr_layer/sm_cyr_layer.h"
#include "sm_utils.h"
#include "sm_td.h"
#include "sm_td_user.h"


bool process_smunicode(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) return false;
    if (!process_smcyr(keycode, record)) return false;
    if (!process_smunicode(keycode, record)) return false;

    return true;
}

bool process_smunicode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_SCRN:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_F12)));
                return false;
            }
            break;

        case M_QUE:
            if (record->event.pressed) {
               if (get_mods() & MOD_MASK_SHIFT) {
                   SM_PRESS_NO_MODS(KC_EXLM);
               } else {
                   SM_PRESS_NO_MODS(KC_QUES);
               }
               return false;
            }
            break;
    };

    return true;
}
