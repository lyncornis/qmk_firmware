#include QMK_KEYBOARD_H
#define ENABLE_USER_CUSTOM

#define BASE 0
#ifdef ENABLE_USER_CUSTOM
    #define FPS    1
    #define FF14   2
#else
    #define META 1
    #define SYMB 2
    #define GAME 3
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   [  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | FPS  | RCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   ]  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | FF14 | LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  UP  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | BASE | LCtrl|      |   \  | LAlt |      |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT(
    KC_ESC  , KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_BSPC,
    DF(FPS) , KC_RCTL, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RBRC, KC_ENT,
    DF(FF14), KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_UP,   KC_RSFT,
    DF(BASE), KC_LCTL, XXXXXXX, KC_BSLS, KC_LALT, XXXXXXX, KC_SPC, KC_SPC, KC_QUOT, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
#ifdef ENABLE_USER_CUSTOM
  /* FPS
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   Ww  |   E  |   R  |  T   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | FPS  | RCtrl|   A  |   S  |   D  |   F  |  G   |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | FF14 | LSft |   Z  |   X  |   C  |   V  |  B   |   |  }   |      |      |      |      |  UP  | Sft  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | BASE | LCtrl| LALT |   1  |   2  |   3  |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [FPS] = LAYOUT(
    KC_ESC,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    DF(FPS),  KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    DF(FF14), KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    DF(BASE), KC_LCTL, KC_LALT, KC_1,    KC_2,    KC_3,     KC_SPC,   _______,    _______, _______, _______, _______, _______, _______
  ),

    /* FF14
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | NUM2 |      |      |      |   X  | PRNT |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | FPS  | NUM0 |   1  |   2  |   3  |   4  |      |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | FF14 | LALT |   5  |   6  |   7  |   8  |      |   |  }   |      |      |      |      |  UP  | Sft  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | BASE | LCtrl|   9  | NUM/ | NUM* | NUM- |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
    #if 0
  [FF14] = LAYOUT(
    KC_ESC  , KC_KP_2, S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_PRINT_SCREEN,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    DF(FPS) , KC_KP_0, KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX,            S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    DF(FF14), KC_LALT, KC_5,    KC_6,    KC_7,    KC_8,    XXXXXXX,            S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    DF(BASE), KC_LCTL, KC_9,    KC_0,    KC_MINS, KC_CIRC, KC_SPC,             _______,    _______, _______, _______, _______, _______, _______
  )
    #endif
    [FF14] = LAYOUT(
    KC_ESC  , KC_KP_2, XXXXXXX, XXXXXXX, XXXXXXX, KC_X,    KC_PRINT_SCREEN,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    DF(FPS) , KC_KP_0, KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX,            S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    DF(FF14), KC_LALT, KC_5,    KC_6,    KC_7,    KC_8,    XXXXXXX,            S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    DF(BASE), KC_LCTL, KC_9,    KC_PSLS, KC_PAST, KC_PMNS, KC_SPC,             _______,    _______, _______, _______, _______, _______, _______
  )
#else
  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Reset|   1  |   2  |   3  |   4  |   5  |  [   |   |  ]   |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |  F1  |      |Muhen | Henk |      |      |   | Left | Down |  Up  |Right |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT(
    QK_BOOT,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,    KC_RBRC,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, XXXXXXX,    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, _______,
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   S(KC_LBRC), S(KC_RBRC), KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB |      |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  | Sft  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT(
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______
  )
#endif
};

#include "joystick.h"
#include "analog.h"
void send_joystick_packet(joystick_t *joystick);

void joystick_task(){
		joystick_status.axes[0] = analogReadPin(F4)/4 - 128;
		joystick_status.axes[1] = analogReadPin(D4)/4 - 128;
		joystick_status.status |= JS_UPDATED;
        send_joystick_packet(&joystick_status);
}
