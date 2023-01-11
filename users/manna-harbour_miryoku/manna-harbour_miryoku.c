// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,

#if defined (MIRYOKU_ALPHAS_BEPO)
    TD_V,
#endif

#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(qk_tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(qk_tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

qk_tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),

#if defined (MIRYOKU_ALPHAS_BEPO)
    [TD_V]  = ACTION_TAP_DANCE_DOUBLE(BP_V, BP_W),
#endif

#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

#if defined (MIRYOKU_ALPHAS_BEPO)
  const key_override_t define_w = ko_make_basic(MOD_BIT(KC_RALT), BP_V, BP_W);
  const key_override_t define_z = ko_make_basic(MOD_BIT(KC_RALT), LGUI_T(BP_N), BP_Z);
  const key_override_t define_cced = ko_make_basic(MOD_BIT(KC_RALT), BP_C, BP_CCED);
  const key_override_t define_altgr_m = ko_make_basic(MOD_BIT(KC_RALT), BP_M, BP_PRIM);

  const key_override_t define_altgr_g = ko_make_basic(MOD_BIT(KC_RALT), BP_G, BP_LABK);
  const key_override_t define_altgr_h = ko_make_basic(MOD_BIT(KC_RALT), ALGR_T(BP_H), BP_RABK);
  const key_override_t define_altgr_shift_g = ko_make_basic(MOD_MASK_SA, BP_G, BP_LEQL);
  const key_override_t define_altgr_shift_h = ko_make_basic(MOD_MASK_SA, ALGR_T(BP_H), BP_GEQL);

  const key_override_t define_altgr_f = ko_make_basic(MOD_BIT(KC_RALT), LT(U_BUTTON,BP_F), BP_SLSH);

  const key_override_t define_altgr_s = ko_make_basic(MOD_BIT(KC_RALT), LCTL_T(BP_S), BP_LDAQ);
  const key_override_t define_altgr_r = ko_make_basic(MOD_BIT(KC_RALT), LALT_T(BP_R), BP_RDAQ);
  const key_override_t define_altgr_shift_s = ko_make_basic(MOD_MASK_SA, LCTL_T(BP_S), BP_LDQU);
  const key_override_t define_altgr_shift_r = ko_make_basic(MOD_MASK_SA, LALT_T(BP_R), BP_RDQU);

  const key_override_t define_altgr_shift_comma = ko_make_basic(MOD_MASK_SA, BP_COMM, BP_DQUO);
#endif

  // This globally defines all key overrides to be used
  const key_override_t **key_overrides = (const key_override_t *[]){
      &capsword_key_override,

#if defined (MIRYOKU_ALPHAS_BEPO)
      &define_w,
      &define_z,
      &define_cced,
      &define_altgr_m,

      &define_altgr_g,
      &define_altgr_h,
      &define_altgr_shift_g,
      &define_altgr_shift_h,

      &define_altgr_f,

      &define_altgr_shift_s,
      &define_altgr_shift_r,
      &define_altgr_s,
      &define_altgr_r,

      &define_altgr_shift_comma,
#endif

      NULL
  };


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
