#include "keymap_optimot.h"

#define MIRYOKU_ALTERNATIVES_BASE_OPTIMOT \
OP_AGRV,               OP_J,              OP_O,                OP_EACU,            OP_B,                OP_F,              OP_D,              OP_L,              OP_QUOT,       OP_Q,              \
LGUI_T(OP_A),          LALT_T(OP_I),      LCTL_T(OP_E),        LSFT_T(OP_U),       OP_COMM,             OP_P,              LSFT_T(OP_T),      LCTL_T(OP_S),      LALT_T(OP_R),  LGUI_T(OP_N),      \
LT(U_BUTTON,OP_K),     ALGR_T(OP_Y),      OP_EGRV,             OP_DOT,             OP_W,                OP_G,              OP_C,              OP_M,              ALGR_T(OP_H),  LT(U_BUTTON,OP_V), \
U_NP,                  U_NP,              LT(U_MEDIA,KC_ESC),  LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,OP_DCIR),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_TAP_OPTIMOT \
OP_AGRV,               OP_J,              OP_O,                OP_EACU,            OP_B,                OP_F,              OP_D,              OP_L,              OP_QUOT,       OP_Q,              \
LGUI_T(OP_A),          LALT_T(OP_I),      LCTL_T(OP_E),        LSFT_T(OP_U),       OP_COMM,             OP_P,              LSFT_T(OP_T),      LCTL_T(OP_S),      LALT_T(OP_R),  LGUI_T(OP_N),      \
LT(U_BUTTON,OP_K),     ALGR_T(OP_Y),      OP_EGRV,             OP_DOT,             OP_W,                OP_G,              OP_C,              OP_M,              ALGR_T(OP_H),  LT(U_BUTTON,OP_V), \
U_NP,                  U_NP,              LT(U_MEDIA,KC_ESC),  LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,OP_DCIR),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_NUM_OPTIMOT \
OP_LBRC,           OP_7,              OP_8,              OP_9,              OP_RBRC,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
OP_PLUS,           OP_4,              OP_5,              OP_6,              OP_HMIN,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
OP_SLSH,           OP_1,              OP_2,              OP_3,              OP_ASTR,           U_NA,              DF(U_NUM),         DF(U_NAV),         KC_ALGR,           U_NA,              \
U_NP,              U_NP,              OP_COMM,           OP_0,              OP_EQL,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_SYM_OPTIMOT \
OP_LCBR,           OP_AMPR,           U_NP,             OP_GRV,           OP_RCBR,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
OP_LABK,           OP_DLR,            OP_PERC,           OP_DQUO,          OP_RABK,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
OP_DTIL,           OP_DCIR,           OP_AT,             OP_HASH,          OP_PIPE,           U_NA,              DF(U_SYM),         DF(U_MOUSE),       KC_ALGR,           U_NA,              \
U_NP,              U_NP,              OP_LPRN,           OP_RPRN,          OP_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP
