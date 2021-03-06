#include QMK_KEYBOARD_H

enum layers {
    QWERTY = 0,
    NUM,
    SYM,
    F,
    NAV,
    SHORTCUT
};

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};

//Tap Dance Declarations
enum {
  TD_TAB_GRV = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for TAB, twice for ~`
  [TD_TAB_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_GRV)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Default Layer: QWERTY
 *
 * ,-------------------------------------------.                                   ,-------------------------------------------.
 * | TAB/`~ |   Q  |   W  |   E  |   R  |   T  |                                   |   Y  |   U  |   I  |   O  |   P  |  ' "   |
 * |--------+------+------+------+------+------|                                   |------+------+------+------+------+--------|
 * | ESC    |   A  |   S  |SYM, D|NUM, F|NAV, G|                                   |   H  |   J  |SYM, K|   L  | ;  : |  ENT   |
 * |--------+------+------+------+------+------+-------------.  ,------------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   V  |   B  |   {  | F    |  | RGUI |SHORTCUT, }|   N  |   M  | ,  < | . >  | /  ? |  RSFT  |
 * `----------------------+------+------+------+------+------|  |------+-----------+------+------+------+----------------------'
 *                        |      | LGUI | LCTL |      |      |  | Lead |   Space   | BKSPC| | \  |      |
 *                        |      |      |      |Space | Alt  |  |      |           |      |      |      |
 *                        `----------------------------------'  `---------------------------------------'
 */
    [QWERTY] = LAYOUT(
        TD(TD_TAB_GRV),  KC_Q, KC_W, KC_E,        KC_R,        KC_T,                                                            KC_Y,   KC_U,   KC_I,        KC_O,  KC_P,    KC_QUOT, 
        KC_ESC,  KC_A, KC_S, LT(SYM,KC_D),LT(NUM,KC_F),LT(NAV,KC_G),                                                    KC_H,   KC_J,   LT(SYM,KC_K),KC_L,  KC_SCLN, KC_ENT, 
        KC_LSFT, KC_Z, KC_X, KC_C,        KC_V,        KC_B,        KC_LCBR, MO(F),       KC_RGUI, LT(SHORTCUT,KC_RCBR),KC_N,   KC_M,   KC_COMM,     KC_DOT,KC_SLSH, KC_RSFT, 
                             KC_NO,       KC_LGUI,     KC_LCTL,     KC_SPC , KC_LALT,      KC_LEAD, KC_SPC,             KC_BSPC  , KC_BSLS,KC_NO),
    
 /*
  * Number layer
  *
  * ,--------------------------------------------.                                ,--------------------------------------------.
  * |        |      |      |      |      |       |                                |   -   | 7,&  | 8,*  | 9,(  |  0,) |        |
  * |--------+------+------+------+------+-------|                                |-------+------+------+------+------+--------|
  * |        |      |      |      |(THIS)|       |                                |   +   | 4,$  | 5,%  | 6,^  |      | (ENT)  |
  * |--------+------+------+------+------+-------+--------------.  ,--------------+-------+------+------+------+------+--------|
  * | (LSFT) |      |      |      |      |       |       |      |  |      |       |   `~  | 1,!  | 2,@  | 3,#  |   =  | (RSFT) |
  * `----------------------+------+------+-------+-------+------|  |------+-------+-------+------+------+----------------------'
  *                        |      |(LGUI)|(LCTL) |(Space)|(Alt) |  |(Lead)|(BKSPC)|  0,)  |      |      |
  *                        |      |      |       |       |      |  |      |       |       |      |      |
  *                        `------------------------------------'  `------------------------------------'
  */
    [NUM] = LAYOUT(
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_PMNS, KC_7,   KC_8, KC_9, KC_0,    KC_NO, 
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_PPLS, KC_4,   KC_5, KC_6, KC_NO,   KC_TRNS, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_NO,  KC_GRV,  KC_1,   KC_2, KC_3, KC_PEQL, KC_TRNS, 
                               KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,KC_TRNS,KC_0,    KC_NO,KC_NO),
 

/*
  * Symbol layer
  *
  * ,--------------------------------------------.                                ,--------------------------------------------.
  * |   !    |  @   |   #  |  $   |  %   |   ^   |                                |   &   |   *  |  (   |   )  |  -   |   = +  |
  * |--------+------+------+------+------+-------|                                |-------+------+------+------+------+--------|
  * |    ~   |      |      |(THIS)|      |       |                                |       |      |(THIS)|      |  _   | (ENT)  |
  * |--------+------+------+------+------+-------+--------------.  ,--------------+-------+------+------+------+------+--------|
  * | (LSFT) |      |      |      |      |       |   [   |      |  |      |   ]   |       |      |      |      |      | (RSFT) |
  * `----------------------+------+------+-------+-------+------|  |------+-------+-------+------+------+----------------------'
  *                        |      |(LGUI)|(LCTL) |(Space)|(Alt) |  |(Lead)|(BKSPC)|(Space)|      |      |
  *                        |      |      |       |       |      |  |      |       |       |      |      |
  *                        `------------------------------------'  `------------------------------------'
  */
    [SYM] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH,KC_DLR,KC_PERC, KC_CIRC,                                       KC_AMPR,KC_ASTR,KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, 
        KC_TILD, KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,                                         KC_EQL, KC_NO,  KC_NO,   KC_NO,   KC_UNDS, KC_TRNS, 
        KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_LBRC, KC_NO,       KC_NO,  KC_RBRC,KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, 
                                KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,  KC_NO),

 /*
  * F Keys layer
  *
  * ,--------------------------------------------.                                ,--------------------------------------------.
  * |        |      |      |      |      |       |                                |       |  F7  |  F8  |  F9  |  F12 |        |
  * |--------+------+------+------+------+-------|                                |-------+------+------+------+------+--------|
  * |  CAPS  |      |      |      |      |       |                                |       |  F4  |  F5  |  F6  |  F11 | (ENT)  |
  * |--------+------+------+------+------+-------+--------------.  ,--------------+-------+------+------+------+------+--------|
  * | (LSFT) |      |      |      |      |       |       |(THIS)|  |      |       |       |  F1  |  F2  |  F3  |  F10 | (RSFT) |
  * `----------------------+------+------+-------+-------+------|  |------+-------+-------+------+------+----------------------'
  *                        |      |(LGUI)|(LCTL) |(Space)|(Alt) |  |(Lead)|(BKSPC)|(Space)|      |      |
  *                        |      |      |       |       |      |  |      |       |       |      |      |
  *                        `------------------------------------'  `------------------------------------'
  */    

    [F] = LAYOUT(
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_NO,   KC_F7,   KC_F8, KC_F9,  KC_F12, KC_NO, 
        KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_NO,   KC_F4,   KC_F5, KC_F6,  KC_F11, KC_NO, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_F1,   KC_F2, KC_F3,  KC_F10, KC_NO,
                               KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
/*
 * Navigation Layer
 *
 * ,--------------------------------------------.                                ,--------------------------------------------.
 * |        |      |      |      |      |       |                                |       |      | Up   |      |      |  PGUP  |
 * |--------+------+------+------+------+-------|                                |-------+------+------+------+------+--------|
 * |        |      |      |      |      |(THIS) |                                |       | Left | Down | Right|      |  PGDN  |
 * |--------+------+------+------+------+-------+--------------.  ,--------------+-------+------+------+------+------+--------|
 * | (LSFT) |      |      |      |      |       |       |      |  |      |       |       |      |      |      |      | (RSFT) |
 * `----------------------+------+------+-------+-------+------|  |------+-------+-------+------+------+----------------------'
 *                        |      |(LGUI)|(LCTL) |(Space)|(Alt) |  |(Lead)|(BKSPC)|(Space)|      |      |
 *                        |      |      |       |       |      |  |      |       |       |      |      |
 *                        `------------------------------------'  `------------------------------------'
 */     
    [NAV] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO, KC_PGUP,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                                         KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_PGDN, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
                             KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
    
/*
 * Shortcut Layer
 *
 * ,-------------------------------------------------.                               ,--------------------------------------------.
 * |LGUI(~`)| LGUI(1)|LGUI(2)|LGUI(3)|LGUI(4)|LGUI(5)|                               |       |      |      |      |      |        |
 * |--------+--------+-------+-------+-------+-------|                               |-------+------+------+------+------+--------|
 * |LSFT(F6)|LALT(F7)|SCRSHTC|SCRSHTF|       |       |                               |       |      |      |      |      |        |
 * |--------+--------+-------+-------+-------+-------+--------------.  ,--------------+-------+------+------+------+------+--------|
 * | LOCK   |        |       |       |       |       |       |      |  |      | (THIS)|       |      |      |      |      |        |
 * `-------------------------+-------+-------+-------+-------+------|  |------+-------+-------+------+------+----------------------'
 *                           |       |(LGUI) |(LCTL) |(Space)|(Alt) |  |(Lead)|(BKSPC)|(Space)|      |      |
 *                           |       |       |       |       |      |  |      |       |       |      |      |
 *                           `--------------------------------------'  `------------------------------------'
 */     
    [SHORTCUT] = LAYOUT(
        LGUI(KC_GRV),LGUI(KC_1), LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),                                       KC_NO,   KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, 
        LSFT(KC_F6), LALT(KC_F7),LSFT(LCTL(LGUI(KC_4))),LSFT(LGUI(KC_4)),KC_NO,KC_NO,                                KC_NO,   KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, 
        LCTL(LGUI(KC_Q)),      KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, 
                                           KC_NO,     KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,KC_NO),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("      nchris v0.1.10\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case F:
            oled_write_P(PSTR("F keys\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case SHORTCUT:
            oled_write_P(PSTR("Shortcuts\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) { // Markdown code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_C, KC_B) { // Markdown code block
            SEND_STRING("```" SS_LSFT(SS_TAP(X_ENTER) SS_TAP(X_ENTER)) "``` " SS_TAP(X_UP));
        }
        SEQ_TWO_KEYS(KC_E, KC_N) { // if not nil
            SEND_STRING("if err != nil {" SS_TAP(X_ENTER));
        }
    }
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case QWERTY:
            case NUM:
            case NAV:
                // IntelliJ code navigation, previous and next
                if (clockwise) {
                    tap_code16(LGUI(A(KC_LEFT)));
                } else {
                    tap_code16(LGUI(A(KC_RIGHT)));
                }
                break;
            default:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case QWERTY:
            case NUM:
            case NAV:
                // Move next or previous spaces
                if (clockwise) {
                    tap_code16(C(KC_LEFT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
                
                break;
            default:
                // Volume control.
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
}
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif