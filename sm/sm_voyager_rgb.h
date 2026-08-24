#pragma once
#include QMK_KEYBOARD_H

extern rgb_config_t rgb_matrix_config;
extern uint32_t     rgb_timer;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    // Initialize RGB timer
    rgb_timer = timer_read32();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_EN] =
        {
            {0, 0, 0},       {0, 0, 0},       {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},       {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},       {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},     {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255},

            {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},       {0, 0, 0},       {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},       {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {169, 255, 255}, {0, 0, 0},       {169, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     {169, 255, 255}, {169, 255, 255},
        },

    [L_RU] =
        {
            {0, 0, 0},     {0, 0, 0},     {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231},

            {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 0, 0},     {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 231, 231}, {0, 0, 0},     {0, 231, 231}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     {0, 231, 231}, {0, 231, 231},
        },

    [L_GAMING] =
        {
            {0, 0, 0}, {0, 0, 0}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {150, 255, 150}, {150, 255, 150}, {150, 255, 150},

            {0, 0, 0}, {0, 0, 0}, {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},       {0, 231, 231},   {0, 231, 231},
        },

    [L_NUM] =
        {
            {0, 0, 0},      {0, 0, 0},      {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},      {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},      {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},     {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219},

            {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},      {0, 0, 0},      {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},      {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {99, 245, 219}, {0, 0, 0},      {99, 245, 219}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     {99, 245, 219}, {99, 245, 219},
        },

    [L_FN] =
        {
            {0, 0, 0},       {0, 0, 0},       {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},       {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},       {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},     {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204},

            {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},       {0, 0, 0},       {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},       {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {214, 218, 204}, {0, 0, 0},       {214, 218, 204}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     {214, 218, 204}, {214, 218, 204},
        },

};

const int ledmap_len = sizeof(ledmap) / sizeof(ledmap[0]);

// ============ RGB overlay (shared by ray burst + bg wave) ============

static uint8_t ov_r[RGB_MATRIX_LED_COUNT];
static uint8_t ov_g[RGB_MATRIX_LED_COUNT];
static uint8_t ov_b[RGB_MATRIX_LED_COUNT];

static inline void ov_add(uint8_t i, uint8_t cr, uint8_t cg, uint8_t cb, uint8_t brightness) {
    uint16_t nr = (uint16_t)ov_r[i] + ((uint16_t)cr * brightness >> 8);
    uint16_t ng = (uint16_t)ov_g[i] + ((uint16_t)cg * brightness >> 8);
    uint16_t nb = (uint16_t)ov_b[i] + ((uint16_t)cb * brightness >> 8);
    ov_r[i] = nr > 255 ? 255 : nr;
    ov_g[i] = ng > 255 ? 255 : ng;
    ov_b[i] = nb > 255 ? 255 : nb;
}

// ============ Fade neighbors animation ============

#define GLOW_MAX_EVENTS 6
#define GLOW_DURATION 400
#define GLOW_RADIUS 35
#define GLOW_MAX_BRIGHTNESS 8

typedef struct {
    uint8_t  x;
    uint8_t  y;
    uint8_t  hue;
    uint32_t time;
} glow_event_t;

static glow_event_t glow_events[GLOW_MAX_EVENTS];
static uint8_t      glow_next_idx = 0;
static uint8_t      glow_hue_counter = 0;

// ============ Reactive trail ============

#define TRAIL_LENGTH 12
#define TRAIL_DURATION 15000
#define TRAIL_BRIGHTNESS 4

static uint8_t  trail_leds[TRAIL_LENGTH];
static uint8_t  trail_hues[TRAIL_LENGTH];
static uint32_t trail_times[TRAIL_LENGTH];
static uint8_t  trail_count = 0;
static uint8_t  trail_head  = 0; // next write position

// ============ Heatmap ============

#define HEAT_INCREMENT 1500
#define HEAT_CAP 10000
#define HEAT_DECAY_INTERVAL 1000
#define HEAT_MAX_BRIGHTNESS 6

static uint16_t heat[RGB_MATRIX_LED_COUNT];
static uint32_t heat_decay_timer = 0;

static uint8_t keys_since_combo = 255;

// ============ Layer transition ============

#define LAYER_TRANS_DURATION 400

static uint32_t      layer_trans_time = 0;
static int           layer_trans_old  = -1;
static layer_state_t prev_layer_state = 0;

void ray_trigger(uint8_t row, uint8_t col) {
    uint8_t led = g_led_config.matrix_co[row][col];
    if (led == NO_LED || led >= RGB_MATRIX_LED_COUNT) return;

    // fade neighbors
    glow_events[glow_next_idx] = (glow_event_t){
        .x    = g_led_config.point[led].x,
        .y    = g_led_config.point[led].y,
        .hue  = glow_hue_counter,
        .time = timer_read32(),
    };
    glow_next_idx = (glow_next_idx + 1) % GLOW_MAX_EVENTS;

    // trail
    trail_leds[trail_head]  = led;
    trail_hues[trail_head]  = glow_hue_counter;
    trail_times[trail_head] = timer_read32();
    trail_head = (trail_head + 1) % TRAIL_LENGTH;
    if (trail_count < TRAIL_LENGTH) trail_count++;

    // heatmap
    uint16_t new_heat = heat[led] + HEAT_INCREMENT;
    heat[led] = new_heat > 65535u ? 65535u : new_heat;

    // track keypresses since last combo (D+F always adds exactly 2)
    if (keys_since_combo < 255) keys_since_combo++;

    glow_hue_counter += 47;
}

void glow_compute(void) {
    for (uint8_t e = 0; e < GLOW_MAX_EVENTS; e++) {
        if (glow_events[e].time == 0) continue;
        uint32_t elapsed = timer_elapsed32(glow_events[e].time);
        if (elapsed > GLOW_DURATION) continue;

        // fade out over time: bright at start, zero at end
        uint8_t time_fade = (uint8_t)((GLOW_DURATION - elapsed) * 255 / GLOW_DURATION);

        HSV event_hsv = {glow_events[e].hue, 255, 255};
        RGB event_rgb = hsv_to_rgb(event_hsv);

        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            int16_t  dx  = (int16_t)g_led_config.point[i].x - (int16_t)glow_events[e].x;
            int16_t  dy  = (int16_t)g_led_config.point[i].y - (int16_t)glow_events[e].y;
            uint16_t adx = dx < 0 ? -dx : dx;
            uint16_t ady = dy < 0 ? -dy : dy;
            uint16_t hi  = adx > ady ? adx : ady;
            uint16_t lo  = adx > ady ? ady : adx;
            uint16_t dist = hi + ((lo * 106) >> 8);

            if (dist >= GLOW_RADIUS) continue;

            uint8_t  dist_fade  = (uint8_t)((GLOW_RADIUS - dist) * 255 / GLOW_RADIUS);
            uint16_t brightness = (uint16_t)dist_fade * time_fade >> 8;
            brightness = brightness * GLOW_MAX_BRIGHTNESS >> 8;

            ov_add(i, event_rgb.r, event_rgb.g, event_rgb.b, (uint8_t)brightness);
        }
    }
}

void trail_compute(void) {
    for (uint8_t t = 0; t < trail_count; t++) {
        uint8_t idx = (trail_head + TRAIL_LENGTH - trail_count + t) % TRAIL_LENGTH;
        uint32_t elapsed = timer_elapsed32(trail_times[idx]);
        if (elapsed >= TRAIL_DURATION) continue;
        uint8_t br = (uint8_t)((uint32_t)(TRAIL_DURATION - elapsed) * TRAIL_BRIGHTNESS / TRAIL_DURATION);
        HSV hsv = {trail_hues[idx], 200, 255};
        RGB rgb = hsv_to_rgb(hsv);
        ov_add(trail_leds[idx], rgb.r, rgb.g, rgb.b, br);
    }
}

void heat_compute(void) {
    // exponential decay: multiply by 500/512 every second ≈ half-life ~30 sec
    if (timer_elapsed32(heat_decay_timer) > HEAT_DECAY_INTERVAL) {
        heat_decay_timer = timer_read32();
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            heat[i] = (uint32_t)heat[i] * 500 >> 9;
        }
    }

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (heat[i] == 0) continue;
        uint16_t h = heat[i] > HEAT_CAP ? HEAT_CAP : heat[i];
        uint8_t ratio = (uint32_t)h * 255 / HEAT_CAP;
        // blue(160) → red(0) as heat increases
        uint8_t hue = 160 - (uint16_t)ratio * 160 / 255;
        uint8_t br  = (uint16_t)ratio * HEAT_MAX_BRIGHTNESS >> 8;
        HSV hsv = {hue, 255, 255};
        RGB rgb = hsv_to_rgb(hsv);
        ov_add(i, rgb.r, rgb.g, rgb.b, br);
    }
}

void layer_trans_check(void) {
    layer_state_t current = layer_state;
    if (current != prev_layer_state) {
        layer_trans_old = biton32(prev_layer_state);
        prev_layer_state = current;
        layer_trans_time = timer_read32();
    }
}

// ============ Shared bar helpers ============

#define BAR_WINDOW_SECS 5
#define BAR_LED_COUNT 3
#define BAR_SMOOTH_SPEED 1
#define BAR_FLASH_DURATION 500
#define BAR_FLASH_BLINKS 3

static uint16_t bar_smooth_total(uint8_t *per_sec, uint8_t sec_idx, uint32_t sec_timer) {
    uint32_t ms_in_sec = timer_elapsed32(sec_timer);
    if (ms_in_sec > 1000) ms_in_sec = 1000;
    uint8_t oldest_idx = (sec_idx + 1) % BAR_WINDOW_SECS;
    uint16_t total = 0;
    for (uint8_t i = 0; i < BAR_WINDOW_SECS; i++) {
        if (i == oldest_idx) {
            total += (uint32_t)per_sec[i] * (1000 - ms_in_sec) / 1000;
        } else {
            total += per_sec[i];
        }
    }
    return total;
}

static void bar_smooth_step(uint16_t *current, uint16_t target) {
    if (*current < target) {
        uint16_t diff = target - *current;
        *current += diff < BAR_SMOOTH_SPEED ? diff : BAR_SMOOTH_SPEED;
    } else if (*current > target) {
        uint16_t diff = *current - target;
        *current -= diff < BAR_SMOOTH_SPEED ? diff : BAR_SMOOTH_SPEED;
    }
}

static inline uint8_t lerp8(uint8_t a, uint8_t b, uint8_t t) {
    return a + ((int16_t)(b - a) * t >> 8);
}

#define BAR_COLOR_STEPS 5

static void bar_render(const uint8_t *leds, uint16_t display_val, uint16_t max_val,
                       const uint8_t colors[BAR_COLOR_STEPS][3], uint32_t flash_start) {
    if (display_val > max_val) display_val = max_val;

    // flash at max: blink on/off
    if (display_val >= max_val && flash_start != 0) {
        uint32_t elapsed = timer_elapsed32(flash_start);
        if (elapsed < BAR_FLASH_DURATION) {
            uint32_t period = BAR_FLASH_DURATION / (BAR_FLASH_BLINKS * 2);
            if ((elapsed / period) % 2 == 1) {
                for (uint8_t i = 0; i < BAR_LED_COUNT; i++)
                    rgb_matrix_set_color(leds[i], 0, 0, 0);
                return;
            }
        }
    }

    // each LED goes through: brightness ramp (0..255) then (BAR_COLOR_STEPS-1) color transitions
    // per-LED phase range: 0 .. 255 + (BAR_COLOR_STEPS-1)*255 = BAR_COLOR_STEPS*255
    // total fill so all LEDs reach final color:
    // last LED starts at offset (BAR_LED_COUNT-1)*255, needs BAR_COLOR_STEPS*255 to finish
    #define BAR_PHASE_MAX (BAR_COLOR_STEPS * 255)
    #define BAR_FILL_MAX  ((BAR_LED_COUNT - 1) * 255 + BAR_PHASE_MAX)
    uint16_t fill = (uint32_t)display_val * BAR_FILL_MAX / max_val;

    for (uint8_t i = 0; i < BAR_LED_COUNT; i++) {
        int16_t phase = (int16_t)fill - (int16_t)i * 255;
        if (phase <= 0) {
            rgb_matrix_set_color(leds[i], 0, 0, 0);
            continue;
        }
        if (phase > BAR_PHASE_MAX) phase = BAR_PHASE_MAX;

        uint8_t br, cr, cg, cb;
        if (phase <= 255) {
            // brightness ramp with first color
            br = phase;
            cr = colors[0][0]; cg = colors[0][1]; cb = colors[0][2];
        } else {
            // full brightness, transition through color steps
            br = 255;
            uint16_t color_phase = phase - 255; // 0 .. (BAR_COLOR_STEPS-1)*255
            uint8_t step = color_phase / 255;   // which transition (0-based)
            uint8_t t = color_phase % 255;      // position within transition
            if (step >= BAR_COLOR_STEPS - 1) {
                step = BAR_COLOR_STEPS - 2;
                t = 255;
            }
            cr = lerp8(colors[step][0], colors[step + 1][0], t);
            cg = lerp8(colors[step][1], colors[step + 1][1], t);
            cb = lerp8(colors[step][2], colors[step + 1][2], t);
        }

        br = (uint16_t)br * br >> 8;
        rgb_matrix_set_color(leds[i],
            ((uint16_t)cr * br >> 10) / 3,
            ((uint16_t)cg * br >> 10) / 3,
            ((uint16_t)cb * br >> 10) / 3);
    }
}

// ============ WPM bar (under БЧС, left side, toward center) ============

#define WPM_BAR_MAX 120

// white → cream → gold → amber → orange
static const uint8_t wpm_colors[BAR_COLOR_STEPS][3] = {
    {255, 255, 255}, {255, 230, 150}, {255, 200, 50}, {255, 160, 20}, {255, 120, 0}
};
static const uint8_t wpm_bar_leds[] = {19, 20, 21};

static uint8_t  wpm_per_sec[BAR_WINDOW_SECS];
static uint8_t  wpm_sec_idx = 0;
static uint32_t wpm_sec_timer = 0;
static uint16_t wpm_display = 0;
static uint32_t wpm_flash_start = 0;
static bool     wpm_was_max = false;

void wpm_record(void) {
    if (wpm_per_sec[wpm_sec_idx] < 255) wpm_per_sec[wpm_sec_idx]++;
}

void wpm_bar_compute(void) {
    if (timer_elapsed32(wpm_sec_timer) > 1000) {
        wpm_sec_timer = timer_read32();
        wpm_sec_idx = (wpm_sec_idx + 1) % BAR_WINDOW_SECS;
        wpm_per_sec[wpm_sec_idx] = 0;
    }
    uint16_t total = bar_smooth_total(wpm_per_sec, wpm_sec_idx, wpm_sec_timer);
    uint16_t target = total * 60 / BAR_WINDOW_SECS / 5;
    bar_smooth_step(&wpm_display, target);
    if (wpm_display >= WPM_BAR_MAX && !wpm_was_max) {
        wpm_flash_start = timer_read32();
        wpm_was_max = true;
    } else if (wpm_display < WPM_BAR_MAX) {
        wpm_was_max = false;
    }
    bar_render(wpm_bar_leds, wpm_display, WPM_BAR_MAX, wpm_colors, wpm_flash_start);
}

// ============ Combo bar (under ЗЙХ, right side, toward center) ============

#define COMBO_BAR_MAX 45

// green → lime → yellow → orange → red
static const uint8_t combo_colors[BAR_COLOR_STEPS][3] = {
    {0, 255, 0}, {128, 255, 0}, {255, 255, 0}, {255, 128, 0}, {255, 0, 0}
};
static const uint8_t combo_bar_leds[] = {48, 47, 46};

static uint8_t  combo_per_sec[BAR_WINDOW_SECS];
static uint8_t  combo_sec_idx = 0;
static uint32_t combo_sec_timer = 0;
static uint16_t combo_display = 0;
static uint32_t combo_flash_start = 0;
static bool     combo_was_max = false;

void combo_record(void) {
    if (keys_since_combo > 2) {
        if (combo_per_sec[combo_sec_idx] < 255) combo_per_sec[combo_sec_idx]++;
    }
    keys_since_combo = 0;
}

void combo_bar_compute(void) {
    if (timer_elapsed32(combo_sec_timer) > 1000) {
        combo_sec_timer = timer_read32();
        combo_sec_idx = (combo_sec_idx + 1) % BAR_WINDOW_SECS;
        combo_per_sec[combo_sec_idx] = 0;
    }
    uint16_t total = bar_smooth_total(combo_per_sec, combo_sec_idx, combo_sec_timer);
    uint16_t target = total * 60 / BAR_WINDOW_SECS;
    bar_smooth_step(&combo_display, target);
    if (combo_display >= COMBO_BAR_MAX && !combo_was_max) {
        combo_flash_start = timer_read32();
        combo_was_max = true;
    } else if (combo_display < COMBO_BAR_MAX) {
        combo_was_max = false;
    }
    bar_render(combo_bar_leds, combo_display, COMBO_BAR_MAX, combo_colors, combo_flash_start);
}

// ============ Layer coloring with overlay ============

static inline void led_color_from_layer(int layer, int i, uint8_t *r, uint8_t *g, uint8_t *b) {
    if (layer < 0 || layer >= ledmap_len) {
        *r = *g = *b = 0;
        return;
    }
    HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        *r = *g = *b = 0;
        return;
    }
    RGB rgb = hsv_to_rgb(hsv);
    uint8_t v = rgb_matrix_config.hsv.v;
    *r = ((uint16_t)rgb.r * v >> 10) / 3;
    *g = ((uint16_t)rgb.g * v >> 10) / 3;
    *b = ((uint16_t)rgb.b * v >> 10) / 3;
}

void set_layer_color(int new_layer) {
    // check if transition is active
    bool transitioning = false;
    uint16_t wavefront = 0;
    if (layer_trans_time != 0 && layer_trans_old >= 0) {
        uint32_t elapsed = timer_elapsed32(layer_trans_time);
        if (elapsed <= LAYER_TRANS_DURATION) {
            transitioning = true;
            wavefront = (uint32_t)elapsed * 200 / LAYER_TRANS_DURATION;
        }
    }

    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        uint8_t r, g, b;

        if (transitioning) {
            int16_t dx = (int16_t)g_led_config.point[i].x - 112;
            int16_t dy = (int16_t)g_led_config.point[i].y - 32;
            uint16_t adx = dx < 0 ? -dx : dx;
            uint16_t ady = dy < 0 ? -dy : dy;
            uint16_t hi  = adx > ady ? adx : ady;
            uint16_t lo  = adx > ady ? ady : adx;
            uint16_t dist = hi + ((lo * 106) >> 8);

            uint8_t cr, cg, cb, pr, pg, pb;
            led_color_from_layer(new_layer, i, &cr, &cg, &cb);
            led_color_from_layer(layer_trans_old, i, &pr, &pg, &pb);

            int16_t edge_diff = (int16_t)dist - (int16_t)wavefront;
            if (edge_diff < 0) edge_diff = -edge_diff;

            if (edge_diff < 12) {
                r = ((uint16_t)cr + pr) / 2;
                g = ((uint16_t)cg + pg) / 2;
                b = ((uint16_t)cb + pb) / 2;
            } else if (dist <= wavefront) {
                r = cr; g = cg; b = cb;
            } else {
                r = pr; g = pg; b = pb;
            }
        } else {
            led_color_from_layer(new_layer, i, &r, &g, &b);
        }

        // no-key positions stay dark, skip overlay
        if (!r && !g && !b) {
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }

        // additive overlay
        uint16_t fr = (uint16_t)r + ov_r[i]; r = fr > 255 ? 255 : fr;
        uint16_t fg = (uint16_t)g + ov_g[i]; g = fg > 255 ? 255 : fg;
        uint16_t fb = (uint16_t)b + ov_b[i]; b = fb > 255 ? 255 : fb;

        rgb_matrix_set_color(i, r, g, b);
    }
}

// A: Throttle expensive overlay computations to once per ~25ms.
// The LED flush only happens every 26ms anyway, so computing every scan cycle is wasted work.
#define RGB_OVERLAY_INTERVAL 25

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    static uint32_t last_overlay_compute = 0;
    if (timer_elapsed32(last_overlay_compute) >= RGB_OVERLAY_INTERVAL) {
        last_overlay_compute = timer_read32();
        memset(ov_r, 0, sizeof(ov_r));
        memset(ov_g, 0, sizeof(ov_g));
        memset(ov_b, 0, sizeof(ov_b));
        glow_compute();
        trail_compute();
        heat_compute();
    }

    layer_trans_check();
    set_layer_color(biton32(layer_state));
    wpm_bar_compute();
    combo_bar_compute();
    return true;
}
