// Copyright 2023 FateEverywhere (@FateEverywhere)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define RGB_MATRIX_LED_COUNT 64
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#define WS2812_PIO_USE_PIO1
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 250U

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_PWM_CHANNEL_ALT RP2040_PWM_CHANNEL_B
#define AUDIO_PIN GP16
#define AUDIO_PIN_ALT GP17
#define AUDIO_INIT_DELAY 5
#define STARTUP_SONG SONG(STARTUP_SOUND)

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP28
#define I2C1_SCL_PIN GP29
#define OLED_DISPLAY_128X32

#define RGB_DISABLE_WHEN_USB_SUSPENDED

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
