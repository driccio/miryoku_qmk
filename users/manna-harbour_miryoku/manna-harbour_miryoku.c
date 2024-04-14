// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,

#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),

#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_dcir_mode = false;

    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("");
            }
            return false;

        case LT(U_FUN,OP_DCIR):
            if (!record->event.pressed) {
                is_dcir_mode = true;
            }
            return true;

        case OP_W: {
            bool continue_default_handling = true;

            if (is_dcir_mode) {
                is_dcir_mode = false;
                tap_code(KC_BSPC);
                tap_code(OP_Z);
                continue_default_handling = false;
            } else {
                continue_default_handling = true;
            }

            return continue_default_handling;
        }

        case LCTL_T(OP_S): {
            bool continue_default_handling = true;

            if (is_dcir_mode) {
                is_dcir_mode = false;
                tap_code(KC_BSPC);
                tap_code(OP_X);
                continue_default_handling = false;
            } else {
                continue_default_handling = true;
            }

            return continue_default_handling;
        }

        default:
            is_dcir_mode = false;
            return true;
    }

    return true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = {
        {EMAIL},

    },
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

#if defined (MIRYOKU_ALPHAS_OPTIMOT)
  const key_override_t define_delete = ko_make_basic(MOD_MASK_SHIFT, LT(U_NUM,KC_BSPC), KC_DEL);
#endif

  // This globally defines all key overrides to be used
  const key_override_t **key_overrides = (const key_override_t *[]){
      &capsword_key_override,

#if defined (MIRYOKU_ALPHAS_OPTIMOT)
      &define_delete,
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


// Optimot Combos (Not compatible with thumb combos)
#if defined (MIRYOKU_ALPHAS_OPTIMOT)
// Left hand
const uint16_t PROGMEM op_agrav[] = {OP_O, OP_EACU, COMBO_END};
const uint16_t PROGMEM op_unds[] = {ALGR_T(OP_Y), OP_EGRV, COMBO_END};
const uint16_t PROGMEM op_hmin[] = {OP_EGRV, OP_DOT, COMBO_END};
// Right hand
const uint16_t PROGMEM op_q[] = {OP_D, OP_L, COMBO_END};
const uint16_t PROGMEM op_dcir[] = {OP_C, OP_M, COMBO_END};
const uint16_t PROGMEM op_cced[] = {OP_M, ALGR_T(OP_H), COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  // Left hand
  COMBO(op_agrav, OP_AGRV),
  COMBO(op_unds, OP_UNDS),
  COMBO(op_hmin, OP_HMIN),
  // Right hand
  COMBO(op_q, OP_Q),
  COMBO(op_dcir, OP_DCIR),
  COMBO(op_cced, OP_CCED)
};
#endif

// caps word

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case OP_A:
        case OP_AGRV:
        case OP_B:
        case OP_C:
        case OP_D:
        case OP_E:
        case OP_EACU:
        case OP_EGRV:
        case OP_F:
        case OP_G:
        case OP_H:
        case OP_I:
        case OP_J:
        case OP_K:
        case OP_L:
        case OP_M:
        case OP_N:
        case OP_O:
        case OP_P:
        case OP_Q:
        case OP_R:
        case OP_S:
        case OP_T:
        case OP_U:
        case OP_V:
        case OP_W:
        case OP_X:
        case OP_Y:
        case OP_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case OP_1:
        case OP_2:
        case OP_3:
        case OP_4:
        case OP_5:
        case OP_6:
        case OP_7:
        case OP_8:
        case OP_9:
        case OP_0:
        case KC_BSPC:
        case KC_DEL:
        case OP_UNDS:
        case OP_HMIN:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
