// !!! DO NOT ADD #pragma once !!! //
// This file is included multiple times by the RGB matrix framework:
// once to register the effect name, once to compile the implementation.

RGB_MATRIX_EFFECT(SMART_GUIDE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    ifdef WIRELESS_ENABLE
#        include "battery.h"
#    endif

// Layer indices — keep in sync with enum layers in keymap.c.
#    define SG_MAC_FN 1
#    define SG_WIN_FN 3

static void sg_set(uint8_t led_min, uint8_t led_max, uint8_t row, uint8_t col,
                   uint8_t r, uint8_t g, uint8_t b) {
    uint8_t index = g_led_config.matrix_co[row][col];
    if (index != NO_LED && index >= led_min && index < led_max) {
        rgb_matrix_set_color(index, r, g, b);
    }
}

static void sg_fill(uint8_t led_min, uint8_t led_max,
                    uint8_t r, uint8_t g, uint8_t b,
                    effect_params_t *params) {
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, r, g, b);
    }
}

// Paint a battery gauge across the number row (row 1, cols 1..10 = keys 1..0).
// Green when healthy, yellow mid, red when low.
static void sg_battery_bar(uint8_t led_min, uint8_t led_max) {
#    ifdef WIRELESS_ENABLE
    uint8_t pct   = battery_get_percentage();          // 0..100
    uint8_t cells = (pct + 9) / 10;                    // 0..10
    if (cells > 10) cells = 10;

    uint8_t r, g, b;
    if (pct <= 20)       { r = 0xFF; g = 0x00; b = 0x00; } // red
    else if (pct <= 50)  { r = 0xFF; g = 0xA0; b = 0x00; } // amber
    else                 { r = 0x20; g = 0xFF; b = 0x40; } // green

    for (uint8_t c = 1; c <= cells; c++) {
        sg_set(led_min, led_max, 1, c, r, g, b);
    }
#    else
    (void)led_min; (void)led_max;
#    endif
}

static bool SMART_GUIDE(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    bool fn_held = layer_state_is(SG_MAC_FN) || layer_state_is(SG_WIN_FN);

    if (!fn_held) {
        // Base state: plain white across the whole board.
        sg_fill(led_min, led_max, 0xFF, 0xFF, 0xFF, params);
        return rgb_matrix_check_finished_leds(led_max);
    }

    // Fn held: dim everything, then light the groups.
    sg_fill(led_min, led_max, 0x02, 0x02, 0x02, params);

    // --- Top row: battery gauge on the number keys ---------------------------
    sg_battery_bar(led_min, led_max);

    // --- F-row hints (media / brightness) ------------------------------------
    // Row 0 cols 1..2 = brightness down/up (Win) or F1..F2 (Mac). Soft yellow.
    for (uint8_t c = 1; c <= 12; c++) {
        sg_set(led_min, led_max, 0, c, 0x30, 0x30, 0x10);
    }

    // --- Bluetooth group: BT_HST1..3 on 1/2/3 (row 1 cols 1..3) --------------
    // Overwrites battery cells 1..3 while Fn is held — that's fine, these are
    // the BT host slots and you want them obvious.
    sg_set(led_min, led_max, 1, 1, 0x20, 0x60, 0xFF); // BT1
    sg_set(led_min, led_max, 1, 2, 0x20, 0x60, 0xFF); // BT2
    sg_set(led_min, led_max, 1, 3, 0x20, 0x60, 0xFF); // BT3

    // --- RGB control group: row 2 cols 0..5 (Fn+` Q W E R T) — pink ---------
    for (uint8_t c = 0; c <= 5; c++) {
        sg_set(led_min, led_max, 2, c, 0xFF, 0x30, 0xB0);
    }
    // Second line of RGB controls: row 3 cols 1..5 (Fn+A S D F G) — pink too
    for (uint8_t c = 1; c <= 5; c++) {
        sg_set(led_min, led_max, 3, c, 0xFF, 0x30, 0xB0);
    }

    // --- Direct RGB mode presets: row 2 cols 10..13 (Fn+P [ ] \) — cyan -----
    sg_set(led_min, led_max, 2, 10, 0x00, 0xC0, 0xFF); // Static
    sg_set(led_min, led_max, 2, 11, 0x00, 0xC0, 0xFF); // Rainbow
    sg_set(led_min, led_max, 2, 12, 0x00, 0xC0, 0xFF); // Per-key layout
    sg_set(led_min, led_max, 2, 13, 0x00, 0xC0, 0xFF); // Smart guide

    // --- Repeat helpers: row 3 cols 7/8 (Fn+J / Fn+K) -----------------------
    sg_set(led_min, led_max, 3, 7, 0xFF, 0x90, 0x00); // Alt Repeat — orange
    sg_set(led_min, led_max, 3, 8, 0x20, 0xFF, 0x40); // Repeat     — green

    // --- System: BAT_LVL (Fn+B) + NK_TOGG (Fn+N), row 4 cols 6/7 ------------
    sg_set(led_min, led_max, 4, 6, 0xFF, 0xFF, 0x00); // Battery query — yellow
    sg_set(led_min, led_max, 4, 7, 0xFF, 0x00, 0xFF); // NKRO toggle    — magenta

    // --- Fn key itself (right Fn, row 5 col 10) -----------------------------
    sg_set(led_min, led_max, 5, 10, 0xFF, 0xFF, 0xFF);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
