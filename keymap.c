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
    BKOMMA,
    NPUNKT,
    MMINUS,
    EQLQST,
    SBS,
    CPSL,
    EEUR,

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
    [BKOMMA] = ACTION_TAP_DANCE_DOUBLE(KC_B,DE_COMM),
    [NPUNKT] = ACTION_TAP_DANCE_DOUBLE(KC_N,DE_DOT),
    [MMINUS] = ACTION_TAP_DANCE_DOUBLE(KC_M,DE_MINS),
    [EQLQST] = ACTION_TAP_DANCE_DOUBLE(DE_EQL,DE_QST),
    [SBS] = ACTION_TAP_DANCE_DOUBLE(DE_SLSH,DE_BSLS),
    [CPSL] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT,KC_CAPSLOCK),
    [EEUR] = ACTION_TAP_DANCE_DOUBLE(KC_E,LALT(KC_E)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTZ] = LAYOUT_ortho_3x10(
    KC_Q, WCOPA , KC_E, KC_R, TTOOLS,    KC_Y,    TD(UUE),    KC_I,    TD(OOE),  KC_P ,
    TD(AAE),TD(SS),KC_D,KC_F,KC_G,KC_H,KC_J,    KC_K,KC_L,    KC_ENTER,
    ZSONDER,LT(_FUNC,KC_X),KC_C,KC_V,KC_SPACE, KC_BSPACE,  TD(BKOMMA),TD(NPUNKT),TD(MMINUS), TD(CPSL)
  ),
//,.-
  [_TOOLS] = LAYOUT_ortho_3x10(
    KC_VOLD,   KC_VOLU,   KC_MUTE,   _______,   _______,  _______,   _______,   _______,  _______,    RESET,
    BL_TOGG,   BL_INC,    KC_VOLU,   RGB_MOD ,  RGB_VAI,  RGB_HUI,   _______,   KC_UP,    _______,    _______,
    BL_BRTG,   BL_DEC,    KC_VOLD,   RGB_TOG,   RGB_VAD , RGB_HUD,   KC_LEFT,   KC_DOWN,  KC_RIGHT,   DE_ALGR
  ),


    [_FUNC] = LAYOUT_ortho_3x10(
      KC_ESC,    _______,    KC_DEL,    KC_1,    KC_2,   KC_3,      KC_F1,    KC_F2,    KC_F3,    KC_F4,
      KC_TAB,    _______,   KC_0,   KC_4,    KC_5,    KC_6,      KC_F5,    KC_F6,    KC_F7,    KC_F8,
      KC_LCTRL,  _______, KC_LALT   ,   KC_7,    KC_8,    KC_9,      KC_F9,    KC_F10,   KC_F11,   KC_F12
    ),

    [_SONDER] = LAYOUT_ortho_3x10(
    DE_EXLM,    DE_DQOT,    DE_PARA,  DE_DLR ,    DE_PERC ,   DE_AMPR,    TD(SBS) ,   DE_LPRN,    DE_RPRN,    TD(EQLQST),
    DE_AT,       _______,       _______,     _______,        _______,    _______,     _______,     KC_UP,    _______,   _______,
    _______,    KC_COMM,       KC_DOT,     KC_MINUS,        _______,    _______,     KC_LEFT,   KC_DOWN,  KC_RIGHT,    KC_LSHIFT

    ),
    [_WCOPA] = LAYOUT_ortho_3x10(
      _______   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______,
      _______   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______,
      KC_LCTL   ,_______    ,_______    ,_______,   _______,    _______   ,_______    ,_______    ,_______,   _______
    ),
};
