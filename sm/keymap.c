#include QMK_KEYBOARD_H

#include "sm_voyager_keymap.h"
#include "sm_voyager_combo.h"
#include "sm_voyager_rgb.h"
#include "sm_layouts.h"
#include "sm_utils.h"
#include "sm_td_user.h"
#include "modules/sm_td/sm_td.h"

// RGB timeout state
uint32_t rgb_timer = 0;
static bool rgb_disabled = false;

bool process_smunicode(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Reset RGB timeout on any key press
    if (record->event.pressed) {
        rgb_timer = timer_read32();
        if (rgb_disabled) {
            rgb_disabled = false;
            rgb_matrix_enable();
        }
    }

    if (!process_smtd(keycode, record)) return false;
    if (!process_sm_layouts(keycode, record)) return false;
    if (!process_smunicode(keycode, record)) return false;

    return true;
}


void matrix_scan_user(void) {
    // Check for RGB timeout
    if (!rgb_disabled && timer_elapsed32(rgb_timer) > RGB_DISABLE_TIMEOUT) {
        rgb_disabled = true;
        rgb_matrix_disable();
    }
}

bool process_smunicode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_SCRN:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_F12)));
                return false;
            }
            break;

        case M_EURO:
            if (record->event.pressed) {
                register_unicode(0x20AC);
                return false;
            }
            break;

        case M_RUB:
            if (record->event.pressed) {
                register_unicode(0x20BD);
                return false;
            }
            break;

//        case M_QUE:
//            if (record->event.pressed) {
//               if (get_mods() & MOD_MASK_SHIFT) {
//                   SM_PRESS_NO_MODS(KC_EXLM);
//               } else {
//                   SM_PRESS_NO_MODS(KC_QUES);
//               }
//               return false;
//            }
//            break;
    };

    return true;
}
