#include "keymap_bepo.h"

#define MIRYOKU_ALTERNATIVES_BASE_BEPO \
BP_B,                  BP_EACU,           BP_P,                BP_O,               BP_EGRV,             BP_DCIR,           TD(TD_V),          BP_D,              BP_L,          BP_J,              \
LGUI_T(BP_A),          LALT_T(BP_U),      LCTL_T(BP_I),        LSFT_T(BP_E),       BP_COMM,             BP_C,              LSFT_T(BP_T),      LCTL_T(BP_S),      LALT_T(BP_R),  LGUI_T(BP_N),      \
LT(U_BUTTON,BP_AGRV),  ALGR_T(BP_Y),      BP_X,                BP_DOT,             BP_K,                BP_M,              BP_Q,              BP_G,              ALGR_T(BP_H),  LT(U_BUTTON,BP_F), \
U_NP,                  U_NP,              LT(U_MEDIA,KC_ESC),  LT(U_NAV,BP_NBSP),  LT(U_MOUSE,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_BASE_BEPO_FLIP \
BP_B,                  BP_EACU,           BP_P,                BP_O,               BP_EGRV,             BP_DCIR,             TD(TD_V),           BP_D,                BP_L,          BP_J,              \
LGUI_T(BP_A),          LALT_T(BP_U),      LCTL_T(BP_I),        LSFT_T(BP_E),       BP_COMM,             BP_C,                LSFT_T(BP_T),       LCTL_T(BP_S),        LALT_T(BP_R),  LGUI_T(BP_N),      \
LT(U_BUTTON,BP_AGRV),  ALGR_T(BP_Y),      BP_X,                BP_DOT,             BP_K,                BP_M,                BP_Q,               BP_G,                ALGR_T(BP_H),  LT(U_BUTTON,BP_F), \
U_NP,                  U_NP,              LT(U_FUN,KC_DEL),    LT(U_NUM,KC_BSPC),  LT(U_SYM,KC_ENT),    LT(U_MOUSE,KC_TAB),  LT(U_NAV,BP_NBSP),  LT(U_MEDIA,KC_ESC),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_TAP_BEPO \
BP_B,                  BP_EACU,           BP_P,                BP_O,               BP_EGRV,             BP_DCIR,           TD(TD_V),          BP_D,              BP_L,          BP_J,              \
LGUI_T(BP_A),          LALT_T(BP_U),      LCTL_T(BP_I),        LSFT_T(BP_E),       BP_COMM,             BP_C,              LSFT_T(BP_T),      LCTL_T(BP_S),      LALT_T(BP_R),  LGUI_T(BP_N),      \
LT(U_BUTTON,BP_AGRV),  ALGR_T(BP_Y),      BP_X,                BP_DOT,             BP_K,                BP_M,              BP_Q,              BP_G,              ALGR_T(BP_H),  LT(U_BUTTON,BP_F), \
U_NP,                  U_NP,              LT(U_MEDIA,KC_ESC),  LT(U_NAV,BP_NBSP),  LT(U_MOUSE,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_TAP_BEPO_FLIP \
BP_B,                  BP_EACU,           BP_P,                BP_O,               BP_EGRV,             BP_DCIR,           TD(TD_V),          BP_D,              BP_L,          BP_J,              \
LGUI_T(BP_A),          LALT_T(BP_U),      LCTL_T(BP_I),        LSFT_T(BP_E),       BP_COMM,             BP_C,              LSFT_T(BP_T),      LCTL_T(BP_S),      LALT_T(BP_R),  LGUI_T(BP_N),      \
LT(U_BUTTON,BP_AGRV),  ALGR_T(BP_Y),      BP_X,                BP_DOT,             BP_K,                BP_M,              BP_Q,              BP_G,              ALGR_T(BP_H),  LT(U_BUTTON,BP_F), \
U_NP,                  U_NP,              LT(U_FUN,KC_DEL),    LT(U_NUM,KC_BSPC),  LT(U_SYM,KC_ENT),    LT(U_MOUSE,KC_TAB),  LT(U_NAV,BP_NBSP),  LT(U_MEDIA,KC_ESC),  U_NP,          U_NP

#define MIRYOKU_ALTERNATIVES_NUM_BEPO \
BP_LBRC,           BP_7,              BP_8,              BP_9,              BP_RBRC,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
BP_PLUS,           BP_4,              BP_5,              BP_6,              BP_MINS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
BP_SLSH,           BP_1,              BP_2,              BP_3,              BP_ASTR,           U_NA,              DF(U_NUM),         DF(U_NAV),         KC_ALGR,           U_NA,              \
U_NP,              U_NP,              BP_COMM,            BP_0,             BP_EQL,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NUM_BEPO_FLIP \
QK_BOOT,           DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        U_NA,              BP_LBRC,           BP_7,              BP_8,              BP_9,              BP_RBRC,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              BP_MINS,           BP_4,              BP_5,              BP_6,              BP_PLUS,           \
U_NA,              KC_ALGR,           DF(U_NAV),         DF(U_NUM),         U_NA,              BP_ASTR,           BP_1,              BP_2,              BP_3,              BP_SLSH,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              BP_EQL,            BP_0,              BP_COMM,           U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_SYM_BEPO \
BP_LCBR,           BP_AMPR,           BP_EXLM,           BP_QUES,           BP_RCBR,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
BP_PERC,           BP_DLR,            BP_GRV,            BP_QUOT,           BP_DQUO,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
BP_TILD,           BP_CIRC,           BP_AT,             BP_HASH,           BP_PIPE,           U_NA,              DF(U_SYM),         DF(U_MOUSE),       KC_ALGR,           U_NA,              \
U_NP,              U_NP,              BP_LPRN,           BP_RPRN,           BP_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_SYM_BEPO_FLIP \
QK_BOOT,           DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        U_NA,              BP_LCBR,           BP_QUES,           BP_EXLM,           BP_AMPR,           BP_RCBR,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              BP_DQUO,           BP_QUOT,           BP_GRV,            BP_DLR,            BP_PERC,           \
U_NA,              KC_ALGR,           DF(U_MOUSE),       DF(U_SYM),         U_NA,              BP_PIPE,           BP_HASH,           BP_AT,             BP_CIRC,           BP_TILD,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              BP_MINS,           BP_LPRN,           BP_RPRN,           U_NP,              U_NP
