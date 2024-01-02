#pragma once


typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);
uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        return SINGLE_HOLD;
    }

    if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        if (state->pressed) return DOUBLE_HOLD;
        return DOUBLE_TAP;
    }

    return MORE_TAPS;
}



void on_dance(qk_tap_dance_state_t *state, void *user_data);
void on_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_SLASH);
        tap_code16(KC_KP_SLASH);
        tap_code16(KC_KP_SLASH);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_SLASH);
    }
}
void dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_SLASH);
            break;
        case DOUBLE_TAP:
            register_code16(KC_COLN);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_SLASH);
            register_code16(KC_KP_SLASH);
    }
}
void dance_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_SLASH);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_COLN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_SLASH);
            break;
    }
    dance_state[0].step = 0;
}



qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance, dance_finished, dance_reset), //
};
