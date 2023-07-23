/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "action_layer.h"
#include "rgblight.h"
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    // _DVORAK,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define J_SHIFT  MT(MOD_RSFT  , KC_J)
#define K_CTRL   MT(MOD_RCTL  , KC_K)
#define L_ALT    MT(MOD_RALT  , KC_L)
#define SC_GUI   MT(MOD_RGUI  , KC_SCLN)

#define F_SHIFT  MT(MOD_LSFT  , KC_F)
#define D_CTRL   MT(MOD_LCTL  , KC_D)
#define S_ALT    MT(MOD_LALT  , KC_S)
#define A_GUI    MT(MOD_LGUI  , KC_A)
#define D_GUI    MT(MOD_LGUI  , KC_D)

#define N_SHIFT  MT(MOD_RSFT  , KC_N)
#define E_CTRL   MT(MOD_RCTL  , KC_E)
#define I_ALT    MT(MOD_RALT  , KC_I)
#define O_GUI    MT(MOD_RGUI  , KC_O)
#define H_GUI    MT(MOD_RGUI  , KC_H)

#define T_SHIFT  MT(MOD_LSFT  , KC_T)
#define S_CTRL   MT(MOD_LCTL  , KC_S)
#define R_ALT    MT(MOD_LALT  , KC_R)
// #define A_GUI    MT(MOD_LGUI  , KC_A)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |     ' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |F-Keys|      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| Nav  | Tab  | Bksp |      |  |      | Space| Enter| Sym  | Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      XXXXXXX , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , XXXXXXX,
      KC_ESC  , A_GUI,  S_ALT  , D_CTRL , F_SHIFT,   KC_G ,                                        KC_H, J_SHIFT, K_CTRL,   L_ALT, SC_GUI, KC_QUOT,
      XXXXXXX , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , FKEYS  ,XXXXXXX,     XXXXXXX, XXXXXXX, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                                 ADJUST, NAV    ,  KC_TAB ,KC_BSPC, XXXXXXX,     XXXXXXX, KC_SPC , KC_ENT, SYM  , KC_APP
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |     ' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |F-Keys|      |  |      |      |   K  |   H  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| Nav  | Tab  | Bksp |      |  |      | Space| Enter| Sym  | Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
      XXXXXXX , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, XXXXXXX,
      KC_ESC  , KC_A , R_ALT   , S_CTRL , T_SHIFT,   KC_G ,                                        KC_M, N_SHIFT, E_CTRL, I_ALT  , KC_O  , KC_QUOT,
      XXXXXXX , KC_Z ,  KC_X   ,  KC_C  ,  D_GUI ,   KC_V , FKEYS  ,XXXXXXX,     XXXXXXX, XXXXXXX, KC_K,  H_GUI ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                                 ADJUST, NAV    ,  KC_TAB ,KC_BSPC, XXXXXXX,     XXXXXXX, KC_SPC , KC_ENT, SYM  , KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |Home  | PgDn | PgUp | End  |M Play| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |  ←   |   ↓  |   ↑  |   →  | Mute | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |M Prev|Vol - |Vol + |M Next|Pause | PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MPLY , KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_MUTE, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_PAUS, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ~   |  !   |  *   |  _   |  -   |  &   |                              |   +  |  7   |  8   |  9   |  @   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    `   |  #   |  [   |  {   |  )   |  |   |                              |   =  |  4   |  5   |  6   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  $   |  ]   |  }   |  )   |  ^   |      |      |  |      |      |   %  |  1   |  2   |  3   |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     KC_TILD , KC_EXLM, KC_ASTR, KC_UNDS, KC_MINS, KC_AMPR,                                     KC_PLUS, KC_7   , KC_8   , KC_9   , KC_AT  , _______,
     KC_GRV  , KC_HASH, KC_LBRC, KC_LCBR, KC_LPRN, KC_PIPE,                                     KC_EQL , KC_4   , KC_5   , KC_6   , KC_0   , _______,
     KC_PIPE , KC_DLR , KC_RBRC, KC_RCBR, KC_RPRN, KC_CIRC, _______, _______, _______, _______, KC_PERC, KC_1   , KC_2   , KC_3   , KC_BSLS, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  F7  |  F8  |  F9  |  F12 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F10 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7  , KC_F8  , KC_F9  , KC_F12 , _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F10 , _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(230, 160, 255);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state | default_layer_state)) {
        case _QWERTY:
            rgblight_sethsv_noeeprom(0, 200, 255);
            break;
        case _COLEMAK_DH:
            rgblight_sethsv_noeeprom(230, 160, 255);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(80, 160, 255);
            break;
        case _NAV:
            rgblight_sethsv_noeeprom(150, 128, 255);
            break;
        default:
            break;
    }
    return state;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
