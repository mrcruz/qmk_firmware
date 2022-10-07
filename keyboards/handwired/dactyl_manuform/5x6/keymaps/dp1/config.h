#pragma once

#define USE_SERIAL

// #define MASTER_LEFT
#define MASTER_RIGHT
//#define EE_HANDS

// delay between key presses to improve RDP experience
#define TAP_CODE_DELAY 1

// tap dance timer
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

// mouse
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 4
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_INITIAL_SPEED 80

#define ONESHOT_TIMEOUT 2000

// needed if we use link time optmization
// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTIO

// limit the layer size
#define LAYER_STATE_16BIT

// combo
// #define COMBO_COUNT 1

// swap hands
#define SWAP_HANDS_ENABLE


// trackball

// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
// #undef MATRIX_ROW_PINS
// #define MATRIX_ROW_PINS { F6, F5, F4, D2, D3, F7 }

// #define PMW33XX_CS_PIN B6 // marked as 10 in pro micro
// #define PMW33XX_CS_PIN F7 // marked as A0 in pro micro
// #define PMW33XX_CS_PIN D1 // marked as 2 in pro micro
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define PMW33XX_CPI 400
// #define USB_MAX_POWER_CONSUMPTION 100
// #define PMW33XX_LIFTOFF_DISTANCE 0x05
// #define PMW33XX_LIFTOFF_DISTANCE 0b1111
// #undef ROTATIONAL_TRANSFORM_ANGLE
// #define ROTATIONAL_TRANSFORM_ANGLE -65
// #define POINTING_DEVICE_INVERT_Y
