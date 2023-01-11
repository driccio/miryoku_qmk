#include "keymap.h"

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ $ │ « │ » │ " │ - │ + │ * │ / │ = │ ( │ ) │ @ │ # │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ À │ J │ O │ É │ B │ F │ D │ L │ ' │ Q │ X │ Ç │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ I │ E │ U │ , │ P │ T │ S │ R │ N │ ^ │ Z │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │ K │ Y │ È │ . │ W │ G │ C │ M │ H │ V │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define OP_DLR   KC_GRV   // $
#define OP_LDAQ  KC_1     // «
#define OP_RDAQ  KC_2     // »
#define OP_DQUO  KC_3     // "
#define OP_HMIN  KC_4     // -
#define OP_PLUS  KC_5     // +
#define OP_ASTR  KC_6     // *
#define OP_SLSH  KC_7     // /
#define OP_EQL   KC_8     // =
#define OP_LPRN  KC_9     // (
#define OP_RPRN  KC_0     // )
#define OP_AT    KC_MINS  // @
#define OP_HASH  KC_EQL   // #
// Row 2
#define OP_AGRV  KC_Q     // À
#define OP_J     KC_W     // J
#define OP_O     KC_E     // O
#define OP_EACU  KC_R     // È
#define OP_B     KC_T     // B
#define OP_F     KC_Y     // F
#define OP_D     KC_U     // D
#define OP_L     KC_I     // L
#define OP_QUOT  KC_O     // '
#define OP_Q     KC_P     // Q
#define OP_X     KC_LBRC  // X
#define OP_CCED  KC_RBRC  // Ç
// Row 3
#define OP_A     KC_A     // A
#define OP_I     KC_S     // I
#define OP_E     KC_D     // E
#define OP_U     KC_F     // U
#define OP_COMM  KC_G     // ,
#define OP_P     KC_H     // P
#define OP_T     KC_J     // T
#define OP_S     KC_K     // S
#define OP_R     KC_L     // R
#define OP_N     KC_SCLN  // N
#define OP_DCIR  KC_QUOT  // ^ (dead)
#define OP_Z     KC_BSLS  // Z
// Row 4
#define OP_K     KC_Z     // K
#define OP_Y     KC_X     // Y
#define OP_EGRV  KC_C     // È
#define OP_DOT   KC_V     // .
#define OP_W     KC_B     // W
#define OP_G     KC_N     // G
#define OP_C     KC_M     // C
#define OP_M     KC_COMM  // M
#define OP_H     KC_DOT   // H
#define OP_V     KC_SLSH  // V

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ € │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ _ │ % │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │ ? │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │ ; │   │   │   │   │   │ ! │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │ : │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
#define OP_EURO  S(OP_DLR ) // €
#define OP_1     S(OP_LDAQ) // 1
#define OP_2     S(OP_RDAQ) // 2
#define OP_3     S(OP_DQUO) // 3
#define OP_4     S(OP_HMIN) // 4
#define OP_5     S(OP_PLUS) // 5
#define OP_6     S(OP_ASTR) // 6
#define OP_7     S(OP_SLSH) // 7
#define OP_8     S(OP_EQL ) // 8
#define OP_9     S(OP_LPRN) // 9
#define OP_0     S(OP_RPRN) // 0
#define OP_UNDS  S(OP_AT  ) // _
#define OP_PERC  S(OP_HASH) // %
#define OP_QUES  S(OP_HASH) // ?
#define OP_SCLN  S(OP_COMM) // ;
#define OP_EXLM  S(OP_DCIR) // !
#define OP_COLN  S(OP_DOT)  // :
#define OP_NBSP  S(KC_SPC)  //   (non-breaking space)

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ¤ │ “ │ ” │ „ │ ‑ │ ± │ × │ \ │ ≠ │ [ │ ] │ − │ ° │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ < │ > │ œ │ ´ │ — │ ‘ │ { │ } │ ’ │ ˚ │ | │  ̛ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ æ │ ₂ │   │ ù │ – │ ` │ & │ ∞ │ L'│ ∼ │ ¨ │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │ ø │ ˙ │ ` │ … │ • │ µ │ ¸ │ ¯ │ ˘ │  ˇ│          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define OP_CURR  ALGR(OP_DLR)   // ¤
#define OP_LDQU  ALGR(OP_LDAQ)  // “
#define OP_RDQU  ALGR(OP_RDAQ)  // ”
#define OP_DLQU  ALGR(OP_DQUO)  // „
#define OP_MMNS  ALGR(OP_HMIN)  // ‑
#define OP_PLMN  ALGR(OP_PLUS)  // ±
#define OP_MUL   ALGR(OP_ASTR)  // ×
#define OP_BSLS  ALGR(OP_SLSH)  // (backslash)
#define OP_NEQL  ALGR(OP_EQL)   // ≠
#define OP_LBRC  ALGR(OP_LPRN)  // [
#define OP_RBRC  ALGR(OP_RPRN)  // ]
#define OP_MINS  ALGR(OP_AT)    // −
#define OP_DEG   ALGR(OP_HASH)  // °
// Row 2
#define OP_LABK  ALGR(OP_AGRV)  // <
#define OP_RABK  ALGR(OP_J)     // >
#define OP_OE    ALGR(OP_O)     // œ
#define OP_ACUT  ALGR(OP_EACU)  // ´ (dead)
#define OP_MDSH  ALGR(OP_B)     // —
#define OP_LSQM  ALGR(OP_F)     //‘
#define OP_LCBR  ALGR(OP_D)     // {
#define OP_RCBR  ALGR(OP_L)     // }
#define OP_RSQM  ALGR(OP_QUOT)  // ’
#define OP_RNGA  ALGR(OP_Q)     // ˚ (dead)
#define OP_PIPE  ALGR(OP_X)     // |
#define OP_LIG1  ALGR(OP_CCED)  // ̉ (dead)
// Row 3
#define OP_AE    ALGR(OP_A)     // æ
#define OP_SUB2  ALGR(OP_I)     // ₂
#define OP_SUP2  ALGR(OP_E)     // superscript two
#define OP_UGRV  ALGR(OP_U)     // ù
#define OP_EDSH  ALGR(OP_COMM)  // –
#define OP_GRV   ALGR(OP_P)     // `
#define OP_AMPR  ALGR(OP_T)     // &
#define OP_INFT  ALGR(OP_S)     // ∞
#define OP_LLWC  ALGR(OP_R)     // L'
#define OP_DTIL  ALGR(OP_N)     // ~ (dead)
#define OP_DIAE  ALGR(OP_DCIR)  // ¨ (dead)
#define OP_RWAR  ALGR(OP_Z)     // Rightwards arrow
// Row 4
#define OP_LOWS  ALGR(OP_K)     // ø
#define OP_DOTA  ALGR(OP_Y)     // ˙ (dead)
#define OP_DGRV  ALGR(OP_EGRV)  // ` (dead)
#define OP_ELLP  ALGR(OP_DOT)   // …
#define OP_BULT  ALGR(OP_W)     // •
#define OP_DGRK  ALGR(OP_G)     // µ (dead Greek key)
#define OP_CEDL  ALGR(OP_C)     // ¸ (dead)
#define OP_MACR  ALGR(OP_M)     //  ̄ (dead)
#define OP_BREV  ALGR(OP_H)     //  ̆ (dead)
#define OP_CARN  ALGR(OP_V)     // ˇ (dead)

/* Shift+AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ © │ ¼ │ ½ │ ¾ │ ⅓ │ ⅔ │ ✻ │ ÷ │ ≈ │ ′ │ ″ │ ª │ º │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ ⩽ │ ⩾ │ Œ │ ❏ │ ❖ │ ✦ │ † │ ‡ │ ¿ │ ⸮ │ ® │  │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Æ │ § │ ¶ │ Ù │ ✓ │ ★ │ ⬅ │ ⬇ │ ⬆ │ ➡ │ ¡ │ ™ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │ ⎈ │ ⌥ │ ⌘ │ · │ ✗ │ ✣ │ ♠ │ ♥ │ ♦ │ ♣ │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define OP_COPY  S(ALGR(OP_DLR))   // ©
#define OP_QRTR  S(ALGR(OP_LDAQ))  // ¼
#define OP_HALF  S(ALGR(OP_RDAQ))  // ½
#define OP_TQTR  S(ALGR(OP_DQUO))  // ¾
#define OP_OTHD  S(ALGR(OP_MINS))  // ⅓
#define OP_TTHD  S(ALGR(OP_PLUS))  // ⅔
#define OP_TDSA  S(ALGR(OP_ASTR))  // ✻ Teardrop-spoked asterisk
#define OP_DIV   S(ALGR(OP_SLSH))  // ÷
#define OP_AEQT  S(ALGR(OP_EQL))   // ≈
#define OP_PRIM  S(ALGR(OP_LPRN))  // ′
#define OP_DPRM  S(ALGR(OP_RPRN))  // ″
#define OP_FOIN  S(ALGR(OP_AT))    // ª Feminine ordinal indicator
#define OP_MOIN  S(ALGR(OP_HASH))  // º Masculine ordinal indicator
// Row 2
#define OP_LEQL   S(ALGR(OP_AGRV))  // ⩽
#define OP_GEQL   S(ALGR(OP_J))     // ⩾
#define OP_LRDWS  S(ALGR(OP_EACU))  // ❏ Lower right drop-shadowed white square
#define OP_BDMW   S(ALGR(OP_B))     // ❖ Black diamond minus white x
#define OP_BFPS   S(ALGR(OP_F))     // ✦ Black four pointed star
#define OP_DAGG   S(ALGR(OP_D))     // †
#define OP_DDAG   S(ALGR(OP_L))     // ‡
#define OP_IQUE   S(ALGR(OP_QUOT))  // ¿
#define OP_RQUS   S(ALGR(OP_Q))     // ⸮
#define OP_REGD   S(ALGR(OP_X))     // ®
#define OP_HORN   S(ALGR(OP_CCED))  // horne (dead)
// Row 3
#define OP_SECT S(ALGR(OP_I))     // §
#define OP_PARA S(ALGR(OP_E))     // ¶
#define OP_CMRK S(ALGR(OP_COMM))  // ✓
#define OP_BSTR S(ALGR(OP_P))     // ★
#define OP_LBAW S(ALGR(OP_T))     // ⬅
#define OP_DBAW S(ALGR(OP_S))     // ⬇
#define OP_UBAW S(ALGR(OP_R))     // ⬆
#define OP_RBAW S(ALGR(OP_N))     // ➡
#define OP_IEXL S(ALGR(OP_DCIR))  // ¡
#define OP_TM   S(ALGR(OP_Z))     // ™
// Row 4
#define OP_HELM  S(ALGR(OP_K))     // ⎈
#define OP_OPTN  S(ALGR(OP_Y))     // ⌥
#define OP_POI   S(ALGR(OP_EGRV))  // ⌘ Place of interest sign
#define OP_MDOT  S(ALGR(OP_DOT))   // · Middle dot
#define OP_BLTX  S(ALGR(OP_W))     // ✗
#define OP_FBSA  S(ALGR(OP_G))     // ✣ Four balloon-spoked asterisk
#define OP_BSS   S(ALGR(OP_C))     // ♠
#define OP_BHS   S(ALGR(OP_M))     // ♥
#define OP_BDS   S(ALGR(OP_H))     // ♦
#define OP_BCS   S(ALGR(OP_V))     // ♣
