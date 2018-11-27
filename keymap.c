#include QMK_KEYBOARD_H
#include "deutsch.h"
//#include "macros.h"

//TODO :
//MEHR SONDERZEICHEN
//COPY-PASTE AUF EINE TASTE


//ZWIBELSCHICHTEN
enum keyboard_layers {
  _QWERTZ,
  _TOOLS,
  _FUNC,
  _SONDER,
  _WCOPA,
};
// TAPDANCE BEZEICHNUNGEN
enum {
    QAT = 0,
    AAE,
    UUE,
    OOE,
    SS,
    BMINUS,
    NPUNKT,
    MKOMMA,
    EQLQST,
    SBS,


};
//Abkürzungen

#define ZSONDER LT(_SONDER,KC_Z)
#define TTOOLS LT(_TOOLS,KC_T)
#define WCOPA LT(_WCOPA,KC_W)

//TAPDANCE ZEUG

qk_tap_dance_action_t tap_dance_actions[] = {
// DOPPELTIP ZEUG
    [QAT] = ACTION_TAP_DANCE_DOUBLE(KC_Q,ALGR(KC_Q)),
    [AAE] = ACTION_TAP_DANCE_DOUBLE(KC_A,DE_AE),
    [UUE] = ACTION_TAP_DANCE_DOUBLE(KC_U,DE_UE),
    [OOE] = ACTION_TAP_DANCE_DOUBLE(KC_O,DE_OE),
    [SS] = ACTION_TAP_DANCE_DOUBLE(KC_S,DE_SS),
    [BMINUS] = ACTION_TAP_DANCE_DOUBLE(KC_B,DE_MINS),
    [NPUNKT] = ACTION_TAP_DANCE_DOUBLE(KC_N,DE_DOT),
    [MKOMMA] = ACTION_TAP_DANCE_DOUBLE(KC_M,DE_COMM),
    [EQLQST] = ACTION_TAP_DANCE_DOUBLE(DE_EQL,DE_QST),
    [SBS] = ACTION_TAP_DANCE_DOUBLE(DE_SLSH,DE_BSLS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTZ] = LAYOUT_ortho_3x10(
    TD(QAT), WCOPA , KC_E, KC_R, TTOOLS,    KC_Y,    TD(UUE),    KC_I,    TD(OOE),  KC_P ,
    TD(AAE),TD(SS),KC_D,KC_F,KC_G,KC_H,KC_J,    KC_K,KC_L,    KC_ENTER,
    ZSONDER,KC_X,KC_C,KC_V,LT(_FUNC,KC_SPACE), LT(_FUNC,KC_BSPC),  TD(BMINUS),TD(NPUNKT),TD(MKOMMA), KC_LSHIFT
  ),

  [_TOOLS] = LAYOUT_ortho_3x10(
    _______,   _______,   _______,   _______,   _______,  _______,   _______,   _______,  _______,    RESET,
    BL_TOGG,   BL_INC,    _______,   RGB_MOD ,  RGB_VAI,  RGB_HUI,   _______,   KC_UP,    _______,    _______,
    BL_BRTG,   BL_DEC,    _______,   RGB_TOG,   RGB_VAD , RGB_HUD,   KC_LEFT,   KC_DOWN,  KC_RIGHT,   _______
  ),


    [_FUNC] = LAYOUT_ortho_3x10(
      KC_ESC,    _______,    KC_DEL,    _______,    _______,    _______,      KC_F1,    KC_F2,    KC_F3,    KC_F4,
      KC_TAB,    _______,    _______,    _______,    _______,    _______,      KC_F5,    KC_F6,    KC_F7,    KC_F8,
      KC_LCTRL,    KC_LGUI, KC_LALT   ,   _______,    _______,    _______,      KC_F9,    KC_F10,   KC_F11,   KC_F12
    ),

    [_SONDER] = LAYOUT_ortho_3x10(
    DE_EXLM,    DE_DQOT,    DE_PARA,  DE_DLR ,    DE_PERC ,   DE_AMPR,    TD(SBS) ,   DE_LPRN,    DE_RPRN,    TD(EQLQST),
    DE_AT,       KC_A,       KC_A,     KC_A,        _______,    _______,     _______,    _______,    _______,   _______,
    _______,    KC_CUT,       KC_COPY,     KC_PASTE,        _______,    _______,     _______,    _______,    _______,    KC_LSHIFT

    ),
    [_WCOPA] = LAYOUT_ortho_3x10(
      _______   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______,
      _______   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______,
      KC_LCTL   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______
    ),
};
