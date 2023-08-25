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
#include "color.h"
#include "gpio.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "rgblight.h"
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _NAV_NUM,
    _SYM,
    _NUM,
    _FUNCTION,
    _ADJUST,
    _MODS,
    _LEAGUE,
    _WASD,
};


// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define LEAGUE   DF(_LEAGUE)
#define WASD   DF(_WASD)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV_NUM)
#define NUM      MO(_NUM)
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

#define N_SHIFT  MT(MOD_RSFT  , KC_N)
#define E_CTRL   MT(MOD_RCTL  , KC_E)
#define I_ALT    MT(MOD_RALT  , KC_I)
#define O_GUI    MT(MOD_RGUI  , KC_O)
#define H_GUI    MT(MOD_RGUI  , KC_H)

#define T_SHIFT  MT(MOD_LSFT  , KC_T)
#define S_CTRL   MT(MOD_LCTL  , KC_S)
#define R_ALT    MT(MOD_LALT  , KC_R)
// #define A_GUI    MT(MOD_LGUI  , KC_A)
#define D_GUI    MT(MOD_LGUI  , KC_D)

#define N1_SHFT  MT(MOD_LSFT  , KC_1)
#define N2_CTRL  MT(MOD_LCTL  , KC_2)
#define N3_ALT   MT(MOD_LALT  , KC_3)
#define N6_GUI   MT(MOD_LGUI  , KC_6)
#define CTRL_D   C(KC_D)
#define CTRL_U   C(KC_U)

#define MOD_SPC  LT(_MODS, KC_SPC)

#define OS_LCTL  OSM(MOD_LCTL)
#define OS_LALT  OSM(MOD_LALT)
#define OS_LSFT  OSM(MOD_LSFT)
#define OS_LGUI  OSM(MOD_LGUI)

#define OS_RCTL  OSM(MOD_RCTL)
#define OS_RALT  OSM(MOD_RALT)
#define OS_RSFT  OSM(MOD_RSFT)
#define OS_RGUI  OSM(MOD_RGUI)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK_DH] = LAYOUT(
      XXXXXXX , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, XXXXXXX,
      KC_ESC  , KC_A , R_ALT   , S_CTRL , T_SHIFT,   KC_G ,                                        KC_M, N_SHIFT, E_CTRL, I_ALT  , KC_O  , KC_QUOT,
      CW_TOGG , KC_Z ,  KC_X   ,  KC_C  ,  D_GUI ,   KC_V , XXXXXXX,KC_MUTE,     XXXXXXX, XXXXXXX, KC_K,  H_GUI ,KC_COMM, KC_DOT ,KC_SLSH, XXXXXXX,
                                 ADJUST , CTRL_U,  KC_TAB ,KC_BSPC, SYM    ,     NAV    , MOD_SPC, KC_ENT, CTRL_D, FKEYS
    ),

    [_NAV_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_DEL,
      _______, KC_4   , N3_ALT , N2_CTRL, N1_SHFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_INS,
      _______, KC_9   , KC_8   , KC_7   , N6_GUI , _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, _______, KC_MNXT, KC_PAUS, KC_PSCR,
                                 _______, _______, _______, KC_0   , KC_5   , _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |  `   |  [   |  ]   |  &   |                              |      |  +   |  !   |  @   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  ~   |  (   |  )   |  |   |                              |   *  |  -   |  =   |  $   |  \   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  {   |  }   |  ^   |      |      |  |      |      |   %  |  _   |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     _______, _______, KC_GRV , KC_LBRC, KC_RBRC, KC_AMPR,                                     _______, KC_PLUS, KC_EXLM, KC_AT  , _______, _______,
     _______, KC_HASH, KC_TILD, KC_LPRN, KC_RPRN, KC_PIPE,                                     KC_ASTR, KC_MINS, KC_EQL , KC_DLR , KC_BSLS, _______,
     _______, _______, _______, KC_LCBR, KC_RCBR, KC_CIRC, _______, _______, _______, _______, KC_PERC, KC_UNDS, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_7   , KC_5   , KC_3   , KC_1   , _______,                                     _______, KC_0   , KC_2   , KC_4   , KC_6   , _______,
      _______, _______, _______, _______, KC_9   , _______, _______, _______, _______, _______, _______, KC_8   , _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
      _______, _______, _______, KC_F12 , KC_F11 , _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F4  , KC_F3  , KC_F2  , KC_F1  , _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F9  , KC_F8  , KC_F7  , KC_F6  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, KC_F10 , KC_F5  , _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, WASD   , _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, LEAGUE , _______, _______,                                     RGB_TOG, _______, _______, RGB_VAI, _______, _______,
      _______, _______, _______, COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MODS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, OS_LALT, OS_LCTL, OS_LSFT, _______,                                     _______, OS_RSFT, OS_RCTL, OS_RALT, _______, _______,
      _______, _______, _______, _______, OS_LGUI, _______, _______, _______, _______, _______, _______, OS_RGUI, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LEAGUE] = LAYOUT(
      KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
      KC_P   , KC_A   , KC_S   , KC_D   , KC_F   , KC_B   , XXXXXXX, KC_MUTE, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
                                 KC_LSFT, KC_LCTL, KC_LALT, KC_SPC , XXXXXXX, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK
    ),

    [_WASD] = LAYOUT(
      KC_ESC , KC_1   , KC_Q   , KC_X   , KC_E   , KC_R   ,                                     COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
      KC_TAB , KC_LSFT, KC_A   , KC_W   , KC_D   , KC_F   ,                                     COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
      KC_LCTL, KC_2   , KC_Z   , KC_S   , KC_C   , XXXXXXX, XXXXXXX, KC_MUTE, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK,
                                 KC_4   , KC_3   , KC_LALT, KC_SPC , XXXXXXX, COLEMAK, COLEMAK, COLEMAK, COLEMAK, COLEMAK
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

//     RGB index map
//     LEFT UNDERGLOW: 0 1 2 3 4 5                                                                              RIGHT_UNDERGLOW: 31 32 33 34 35 36
//       30     , 29     , 28     , 27     , 26     , 25     ,                                     56     , 57     , 58     , 59     , 60     , 61     ,
//       24     , 23     , 22     , 21     , 20     , 19     ,                                     50     , 51     , 52     , 53     , 54     , 55     ,
//       18     , 17     , 16     , 15     , 14     , 13     , 12     , 11     , 42     , 43     , 44     , 45     , 46     , 47     , 48     , 49     ,
//                                  10     , 9      , 8      , 7      , 6      , 37     , 38     , 39     , 40     , 41
//     ),
#define LEFT_ALL 0, 31
#define RIGHT_ALL 31, 31
#define BOTH_ALL 0, 62
#define LEFT_UNDER 0, 6
#define LEFT_KEYS 6, 25
#define RIGHT_UNDER 31, 6
#define RIGHT_KEYS 37, 25

#define HSV_BASE_WHITE 230, 60, 255
#define HSV_SYM_YELLOW 40, 180, 255
#define HSV_NAV_BLUE 150, 128, 255
#define HSV_NUM_GREEN 80, 160, 255
#define HSV_FUNC_PURPLE 200, 160, 255
#define HSV_ADJ_RED 10, 160, 255
#define HSV_DIM 230, 60, 50

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {BOTH_ALL, HSV_BASE_WHITE},
    {37, 1, HSV_NAV_BLUE},
    {41, 1, HSV_FUNC_PURPLE},
    {6, 1, HSV_SYM_YELLOW},
    {10, 1, HSV_ADJ_RED}
);

const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_KEYS, HSV_DIM},
    {RIGHT_KEYS, HSV_DIM},
    {6, 1, HSV_SYM_YELLOW},

    {13, 3, HSV_SYM_YELLOW},
    {19, 5, HSV_SYM_YELLOW},
    {25, 4, HSV_SYM_YELLOW},
    {44, 2, HSV_SYM_YELLOW},
    {50, 5, HSV_SYM_YELLOW},
    {57, 3, HSV_SYM_YELLOW},
    {LEFT_UNDER, HSV_SYM_YELLOW},
    {RIGHT_UNDER, HSV_SYM_YELLOW}
);

const rgblight_segment_t PROGMEM nav_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_KEYS, HSV_DIM},
    {RIGHT_KEYS, HSV_DIM},
    {37, 1, HSV_NAV_BLUE},

    {14, 4, HSV_NUM_GREEN},
    {20, 4, HSV_NUM_GREEN},
    {6, 2, HSV_NUM_GREEN},
    {LEFT_UNDER, HSV_NUM_GREEN},

    {61, 1, HSV_NAV_BLUE},
    {56, 4, HSV_NAV_BLUE},
    {55, 1, HSV_NAV_BLUE},
    {50, 4, HSV_NAV_BLUE},
    {47, 3, HSV_NAV_BLUE},
    {44, 2, HSV_NAV_BLUE},
    {RIGHT_UNDER, HSV_NAV_BLUE}
);

const rgblight_segment_t PROGMEM func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_KEYS, HSV_DIM},
    {RIGHT_KEYS, HSV_DIM},
    {41, 1, HSV_FUNC_PURPLE},

    {14, 4, HSV_FUNC_PURPLE},
    {20, 4, HSV_FUNC_PURPLE},
    {6, 2, HSV_FUNC_PURPLE},
    {26, 2, HSV_FUNC_PURPLE},
    {LEFT_UNDER, HSV_FUNC_PURPLE}
);

const rgblight_segment_t PROGMEM caps_word_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 1, HSV_NUM_GREEN}
);

const rgblight_segment_t PROGMEM league_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_UNDER, 160, 180, 255},
    {LEFT_KEYS, 27, 220, 255},
    {20, 4, 160, 180, 255},
    {RIGHT_ALL, HSV_DIM}
);

const rgblight_segment_t PROGMEM adj_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LEFT_KEYS, HSV_DIM},
    {RIGHT_KEYS, HSV_DIM},
    {10, 1, HSV_ADJ_RED},

    {50, 1, HSV_ADJ_RED},
    {15, 1, HSV_ADJ_RED},
    {21, 1, HSV_ADJ_RED},
    {27, 1, HSV_ADJ_RED},
    {LEFT_UNDER, HSV_ADJ_RED},
    {RIGHT_UNDER, HSV_ADJ_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    sym_layer,
    nav_num_layer,
    func_layer,
    caps_word_layer,
    league_layer,
    adj_layer
);

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(230, 60, 255);
    rgblight_layers = my_rgb_layers;

    // disable Liatris light
    setPinOutput(24);
    writePinHigh(24);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV_NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(6, layer_state_cmp(state, _ADJUST));
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK_DH));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LEAGUE));
    return state;
}
void caps_word_set_user(bool active) {
    rgblight_set_layer_state(4, active);
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
