/*
©2021 Everywhere Defense Industries / Fate Everywhere <fate@7storm.org>
 
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _SET,
};

//set up Tap Dances
enum {
    TD_VOLD,
    TD_VOLU,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [TD_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MUTE),
};

//00 Macro
enum custom_keycodes {
    KP_00 = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KP_00:
        if (record->event.pressed) {
            SEND_STRING("00");
        } else {
        }
        break;
    }
    return true;
};

// Readability keycodes
#define SET      MO(_SET)
#define _______  KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_MAIN] = LAYOUT_dreadnaught(
  KC_ESC,       _______,     _______, _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,   TD(TD_VOLU), TD(TD_VOLD),
  _______,      _______,     _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,   _______, _______,
  LSG(KC_S),    G(KC_G),     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS, _______,
  LAG(KC_PSCR), LAG(KC_R),   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, KC_KP_7, KC_KP_8, KC_KP_9,   KC_PPLS, _______,
  G(KC_DOT),    RCS(KC_ESC), KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6,   KC_TAB,  _______,
  G(KC_TAB),    C(KC_X),     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, _______, _______, KC_UP,   _______, KC_KP_1, KC_KP_2, KC_KP_3,   _______, _______,
  C(KC_C),      C(KC_V),     KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_SPC,  _______, _______, KC_RALT, KC_RGUI, SET,     KC_RCTL, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_KP_0, KP_00,   KC_KP_DOT, KC_PENT, _______
  ),

  [_SET] = LAYOUT_dreadnaught(
  QK_BOOT,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AU_TOGG, CK_TOGG, MU_TOGG, _______, _______, _______,   _______, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,  RGB_SPI, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_RBT,  _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI,   RGB_SPD, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD,   _______, _______,
  _______,     _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______
  ),

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MAIN:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SET:
            oled_write_P(PSTR("Settings\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return true;
}
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

  for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x04)) { // 0x04 is general 'alphas' LEDs, commissioner requires teal.
            rgb_matrix_set_color(i, 0, 128, 128);
        }
  }

  for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 is 'modifier' LEDs, setting to orange.
            rgb_matrix_set_color(i, 128, 62, 0);
        }
  }

  for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 is 'activator' LEDs, green.
            rgb_matrix_set_color(i, 0, 128, 0);
        }
  }

  for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x08 is the LED for the Esc key, and should be red.
            rgb_matrix_set_color(i, 128, 0, 0);
        }
  }

if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 128, 128, 128); // scroll lock key is LED #15
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 0, 128, 128);
    }

if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(46, 128, 128, 128); // num lock key is LED #48       
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(46, 0, 128, 128);
    }

if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(75, 128, 128, 128); // caps lock key is LED #75
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(75, 0, 128, 128);
    }

    return false;
}