/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"ero3y/zVYM3"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define MAX_DEFERRED_EXECUTORS 16

// Machine-local combos live in the gitignored sm_secrets.h; without it the
// build just has fewer combos. See the hook macros in sm_voyager_combo.h.
#if __has_include("sm_secrets.h")
#    include "sm_secrets.h"
#endif
#ifndef SM_SECRETS_COMBO_COUNT
#    define SM_SECRETS_COMBO_COUNT 0
#endif

#define COMBO_COUNT (104 + SM_SECRETS_COMBO_COUNT)

#define TAPPING_TERM 200
#define COMBO_TERM 35

#define ONESHOT_TIMEOUT 5000

#define SM_LAYOUTS_SHORTCUT_LAYER 0
#define SM_LAYOUTS_CYR_ENABLED

// Dynamic release window: wider than the sm_td default (30) — the pinky was
// missing holds. Keep in lockstep with the cygnus sm keymap.
#define SMTD_GLOBAL_RELEASE_PERCENT 55

// #define SMTD_DEBUG_ENABLED
// #define SMTD_GLOBAL_SIMULTANEOUS_PRESSES_DELAY_MS 5

// RGB timeout configuration - 15 minutes in milliseconds
#define RGB_DISABLE_TIMEOUT 900000

