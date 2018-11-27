// Macros
enum {
    COPY = 0,
    PASTE,
};
// Macro funktionen
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    // for basic strings
    case COPY: {
        if (record->event.pressed) {
            SEND_STRING(KC_CTL); // REPLACE with what you want your macro to be
            return false;
        }
    }

    // for more complex macros (want to add modifiers, etc.)
    case PASTE: {
      if (recond->event.pressed) {
        return MACRO(
          // INSERT CODE HERE for your macro. See https://docs.qmk.fm/macros.html
        );
      }
    }


    //
  }
  return MACRO_NONE;
};
