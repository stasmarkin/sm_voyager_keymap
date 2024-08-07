/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"ero3y/zVYM3"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define MAX_DEFERRED_EXECUTORS 16
#define COMBO_COUNT 103

#define TAPPING_TERM 200
#define RELEASING_TERM 50

#define ONESHOT_TIMEOUT 5000

#define SM_LAYOUTS_SHORTCUT_LAYER L_EN
#define SM_LAYOUTS_CYR_ENABLED
