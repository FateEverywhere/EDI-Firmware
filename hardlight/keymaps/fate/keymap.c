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
    _RAISE,
    _LOWER,
    _SET,
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define SET     MO(_SET)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Backsp | Delete |   7    |   8    |   9    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Esc    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | Pause  |   4    |   5    |   6    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LShift | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | Up     | Enter  |   1    |   2    |   3    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCtrl  |  Menu  |   GUI  |   Alt  | Lower  | Space  |  Space | Raise  | Leader | RShift | Left   | Down   | Right  |   0    |   .    |  Enter |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_MAIN] = LAYOUT_ortho_4x16(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,  KC_KP_7, KC_KP_8,   KC_KP_9,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PAUS, KC_KP_4, KC_KP_5,   KC_KP_6,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_ENT,  KC_KP_1, KC_KP_2,   KC_KP_3,
  KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, LOWER,   KC_SPC, KC_SPC, RAISE, QK_LEAD, KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_KP_0, KC_KP_DOT, KC_PENT
  ),

/* RAISE
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    `   |  1     |  2     |  3     |  4     |  5     |  6     |  7     |  8     |  9     |  0     |        | Insert |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | -      | =      | [      | ]      |   \    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  PgUp  |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |  Vol-  |  PgDn  |  Vol+  |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_4x16(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_INS,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_PGDN, KC_VOLU, _______, _______, _______
  ),

/* LOWER
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |        |   K/   |   K*   |   K-   |   K+   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |    _   |    +   |    {   |    }   |   |    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |        |        |        |        |  Home  |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |  Mute  |  End   |  Play  |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_4x16(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, 
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_HOME, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_END,  KC_MPLY, _______, _______, _______
  ),

 /* SETTINGS
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |        | CapLok | ScrLok | NumLok | VK I/O | AudI/O |        | RGB IO | Mode+  | Mode-  | Plain  |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | BootLd |        |        |        |        | Clicky |        |  Hue+  |  Sat+  |  Val+  | Larsen |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | Music? |        |  Hue-  |  Sat-  |  Val-  | Rswirl |        | Reset  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | MuMode |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SET] = LAYOUT_ortho_4x16(
  _______, KC_CAPS, KC_SCRL, KC_NUM,  VK_TOGG, AU_TOGG, _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_M_P, _______, _______, _______, _______, _______,
  QK_BOOT, _______, _______, _______, _______, CK_TOGG, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_SW,_______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, MU_TOGG, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_K, _______, QK_RBT,  _______, _______, _______, 
  _______, _______, _______, _______, _______, MU_NEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SET);
}

#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(AG_NORM_SOUND);
float leader_succeed_song[][2] = SONG(AUDIO_ON_SOUND);
float leader_fail_song[][2] = SONG(AUDIO_OFF_SOUND);
#endif

void leader_start_user(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end_user(void) {
    bool did_leader_succeed = false;

    if (leader_sequence_one_key(KC_RSFT)) {
        SEND_STRING(SS_LGUI("l"));
        did_leader_succeed = true;
    } else if (leader_sequence_three_keys(KC_Q, KC_W, KC_E)) {
        SEND_STRING("nah bro you don't get my passwords"),tap_code16(KC_ENT);
        did_leader_succeed = true;
    } else if (leader_sequence_three_keys(KC_A, KC_S, KC_D)) {
        SEND_STRING("secondary password goes here"),tap_code16(KC_ENT);
        did_leader_succeed = true;
    }

#ifdef AUDIO_ENABLE
    if (did_leader_succeed) {
        PLAY_SONG(leader_succeed_song);
    } else {
        PLAY_SONG(leader_fail_song);
    }
#endif
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MAIN:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
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
    
    return false;
}
#endif