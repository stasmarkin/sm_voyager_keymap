#pragma once

#include QMK_KEYBOARD_H

#define IIIIIII KC_NO
#define   ___   KC_NO // no switches on a board

enum layers {
    L_EN = 0,
    L_RU,
    L_GAMING,
    L_NUM,
    L_FN,
    L_RU_FAKE,
};

// Spotify control via Raycast hotkeys instead of media keys: media keys go to
// whatever the OS thinks is the active player, these always hit Spotify.
// Base is Ctrl+Shift+Cmd with LEFT modifiers — a Karabiner rule maps
// right_command+hjkl to arrow keys with `optional: any`, which would eat L.
#define SPFY_LIKE LCTL(LSFT(LGUI(KC_Y)))
#define SPFY_PREV LCTL(LSFT(LGUI(KC_U)))
#define SPFY_PLAY LCTL(LSFT(LGUI(KC_I)))
#define SPFY_SEEK LCTL(LSFT(LGUI(KC_O)))
#define SPFY_NEXT LCTL(LSFT(LGUI(KC_L)))
