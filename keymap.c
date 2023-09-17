#include QMK_KEYBOARD_H

// TAP DANCE SETUP
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_t;

// td_state_t cur_dance(tap_dance_state_t *state);

// // For the x tap dance. Put it here so it can be used in any keymap
// void x_finished(tap_dance_state_t *state, void *user_data);
// void x_reset(tap_dance_state_t *state, void *user_data);


// LAYERS
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAME_PZ 4
#define _GAME_HS 5
#define _GAME_MD 6

// Tap dance enums
enum {
    TDACT_X,
    TDACT_C,
    TDACT_V,
    TDARR_FN
};

// Custom keycodes enums
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  SUPER
};

// TAP DANCE
#define TD_ACT_X TD(TDACT_X)
#define TD_ACT_C TD(TDACT_C)
#define TD_ACT_V TD(TDACT_V)
#define TD_ARR_FN TD(TDARR_FN)

// Homerows mod keys GACS(linux)/CAGS(macos)
// HRM querty layer
#define HRM_LG LGUI_T(KC_A)
#define HRM_LA LALT_T(KC_S)
#define HRM_LC LCTL_T(KC_D)
#define HRM_LS LSFT_T(KC_F)

#define HRM_RS RSFT_T(KC_J)
#define HRM_RC RCTL_T(KC_K)
#define HRM_RA LALT_T(KC_L)
#define HRM_RG RGUI_T(KC_SCLN)
// HRM symbols layer
#define HRM2_RS RSFT_T(KC_MINS)
#define HRM2_RC RCTL_T(KC_EQL)
#define HRM2_RA LALT_T(KC_QUOT)
#define HRM2_RG RGUI_T(KC_COLN)
// HRM mouse layer
#define HRM3_LG LGUI_T(KC_NO)
#define HRM3_LA LALT_T(KC_NO)
#define HRM3_LC LCTL_T(KC_NO)
#define HRM3_LS LSFT_T(KC_NO)

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, HRM_LG,  HRM_LA,  HRM_LC,  HRM_LS,  KC_G,                               KC_H,    HRM_RS,  HRM_RC,  HRM_RA,  HRM_RG,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    TD_ACT_X,TD_ACT_C,TD_ACT_V,KC_B,    KC_WBAK,          KC_WFWD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    SUPER,   MO(_LOWER), KC_SPC,                 KC_ENT,  MO(_RAISE),MOD_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DLR,                             KC_AT,   KC_EXLM, KC_AMPR, KC_PERC, KC_CIRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PPLS,                            KC_GRV,  HRM2_RS, HRM2_RC, HRM2_RA, HRM2_RG, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PSCR, KC_INS,  KC_LT,   TD_ARR_FN,KC_LPRN, KC_LBRC, KC_PAST,         KC_HASH, KC_RBRC, KC_RPRN, KC_RCBR, KC_GT,   KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                            _______, _______, OSM(MOD_LCTL|MOD_LALT), OSM(MOD_LCTL|MOD_LSFT),  MO(_ADJUST),  OSM(MOD_LSFT)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                             KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_BTN3,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, HRM3_LG, HRM3_LA, HRM3_LC, HRM3_LS, KC_UNDS,                            KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_BTN1,          KC_BTN2, KC_PLUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, MO(_ADJUST),  _______,              _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     EE_CLR,  QK_BOOT, QK_MAKE, _______, _______, _______,                            CG_SWAP, CG_NORM, _______, _______, _______, QK_RBT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,                              KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_VOLU, KC_BRIU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO,                              KC_NO,   KC_BTN4, KC_BTN3, KC_BTN5, KC_VOLD, KC_BRID,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_G, RGB_M_SW,RGB_M_X, KC_LSFT,          _______, TG(_GAME_PZ),TG(_GAME_HS),TG(_GAME_MD),VK_TOGG, KC_MUTE, BL_TOGG,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LCTL,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME_PZ] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_F,    KC_2,    KC_1,    KC_3,    KC_4,                               KC_WH_L, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_R,    KC_W,    KC_H,    KC_M,                               KC_WH_R, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(_GAME_PZ),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_A,    KC_S,    KC_D,    KC_X,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_QWERTY),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_N,    KC_V,    KC_C,    KC_RBRC, KC_L,    KC_LALT,          KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, KC_E,    KC_SPC,                    KC_ENT,  KC_NO,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME_HS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,                               KC_F8,   KC_F10,  KC_F12,  KC_NO,   KC_GRV,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,                               KC_F9,   KC_F11,  KC_NO,   KC_NO,   KC_TAB,  TG(_GAME_HS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,                               KC_7,    KC_8,    KC_9,    KC_NO,   KC_LSFT, TO(_QWERTY),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_S,    KC_T,    KC_U,    KC_V,    KC_W,    KC_X,    KC_0,             KC_ESC,  KC_3,    KC_4,    KC_5,    KC_6,    KC_LCTL, KC_LALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_Y,    KC_Z,    KC_1,                      KC_ENT,  KC_NO,   KC_2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME_MD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_V,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_WH_L, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_M,    KC_Z,    KC_T,    KC_W,    KC_G,    KC_COMM,                            KC_WH_R, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(_GAME_MD),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_X,    KC_A,    KC_S,    KC_D,    KC_DOT,                             KC_LBRC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_QWERTY),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F,             KC_ESC,  KC_RBRC, KC_F5,   KC_F6,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_B,    KC_R,    KC_SPC,                    KC_ENT,  KC_NO,   KC_F1
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// TAP DANCE HANDLERS
// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }

//     // Assumes no one is trying to type the same letter three times (at least not quickly).
//     // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//     // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
//         else return TD_TRIPLE_HOLD;
//     } else return TD_UNKNOWN;
// }

// static td_tap_t xtap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
// void x_finished(tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_X); break;
//         case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
//         case TD_DOUBLE_TAP: register_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
//         // Last case is for fast typing. Assuming your key is `f`:
//         // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//         // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//         case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
//         default: break;
//     }
// }

// void x_reset(tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: unregister_code(KC_X); break;
//         case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
//         case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
//         case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
//         default: break;
//     }
//     xtap_state.state = TD_NONE;
// }

// tap_dance_action_t tap_dance_actions[] = {
//     [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
// };

void td_arrow_fn_handle_each(qk_tap_dance_state_t *state, void *user_data) {}

void td_arrow_fn_handle_reset(qk_tap_dance_state_t *state, void *user_data) {}

void td_arrow_fn_handle_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_LCBR);
            break;
        case 2:
            SEND_STRING("()=>{}");
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            break;
        case 3:
            SEND_STRING("()=>{}");
            tap_code16(KC_LEFT);
            break;
    }
}

void td_act_x_handle_each(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_x_handle_reset(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_x_handle_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_X);
    }
    else if (state->count == 2) {
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    else if (state->count >= 3) {
        tap_code16(C(KC_X));
    }
}

void td_act_c_handle_each(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_c_handle_reset(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_c_handle_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_C);
    }
    else if (state->count == 2) {
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    else if (state->count >= 3) {
        tap_code16(C(KC_C));
    }
}

void td_act_v_handle_each(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_v_handle_reset(qk_tap_dance_state_t *state, void *user_data) {}

void td_act_v_handle_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_V);
    }
    else if (state->count == 2) {
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    else if (state->count >= 3) {
        tap_code16(C(KC_V));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TDARR_FN] = ACTION_TAP_DANCE_FN_ADVANCED(td_arrow_fn_handle_each, td_arrow_fn_handle_finished, td_arrow_fn_handle_reset),
    [TDACT_X] = ACTION_TAP_DANCE_FN_ADVANCED(td_act_x_handle_each, td_act_x_handle_finished, td_act_x_handle_reset),
    [TDACT_C] = ACTION_TAP_DANCE_FN_ADVANCED(td_act_c_handle_each, td_act_c_handle_finished, td_act_c_handle_reset),
    [TDACT_V] = ACTION_TAP_DANCE_FN_ADVANCED(td_act_v_handle_each, td_act_v_handle_finished, td_act_v_handle_reset),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_LG:
        case HRM_LA:
        case HRM_LC:
        case HRM_LS:
        case HRM_RS:
        case HRM_RC:
        case HRM_RA:
        case HRM_RG:
        case HRM2_RS:
        case HRM2_RC:
        case HRM2_RA:
        case HRM3_LG:
        case HRM3_LA:
        case HRM3_LC:
        case HRM3_LS:
            return QUICK_TAP_TERM - 20;
        default:
            return QUICK_TAP_TERM;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case SUPER:
      if (!record->event.pressed) {
        tap_code16(KC_LGUI);
      }
      return false;
      break;
  }
  return true;
}

