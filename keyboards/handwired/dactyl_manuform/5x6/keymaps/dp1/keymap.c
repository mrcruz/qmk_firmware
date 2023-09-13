/*

TODO:
    KC_REPEAT

how to improve?
    what am I using more?
    taps are less stressful than holds
    move things to one shot mods
    single press actions should be one single shot away
    goal: everything 2 key presses away

KNOW HOW
    tap dance
        https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md
        Criteria for "good placement" of a tap dance key:
        *  Not a key that is hit frequently in a sentence
        *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
        *    in a web form. So 'tab' would be a poor choice for a tap dance.
        *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
        *    letter 'p', the word 'pepper' would be quite frustating to type.

HARDWARE
    https://github.com/v0Ch/vfk-001/
    https://github.com/chenfucn/dactyl-pivot
    https://www.printables.com/model/102789-dactyl-flex-w-threaded-tenting

REFERENCES
    https://colemakmods.github.io/ergonomic-mods/wide.html
    https://configure.zsa.io/ergodox-ez/layouts/GWjD3/latest/1
    https://configure.zsa.io/planck-ez/layouts/Wblvj/latest/0
    https://configure.zsa.io/planck-ez/search?q=qwerty&page=1&legacy=false&anonymous=false&withTour=false
    https://dreymar.colemak.org/layers-extend.html
    https://forum.colemak.com/topic/2014-extend-extra-extreme/
    https://geekhack.org/index.php?topic=51069.0
    https://getreuer.info/posts/keyboards/macros/index.html
    https://getreuer.info/posts/keyboards/triggers/index.html
    https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
    https://github.com/dschil138/Fulcrum
    https://github.com/getreuer/qmk-keymap/blob/main/README.md
    https://github.com/klavgen/klavgen
    https://github.com/manna-harbour/miryoku
    https://github.com/nickcoutsos/dactyl-flatpacked/
    https://github.com/precondition/dactyl-manuform-keymap
    https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md
    https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
    https://github.com/rafaelromao/keyboards
    https://github.com/Yowkees/keyball
    https://imgur.com/gallery/l1xNsoO
    https://keymapdb.com/
    https://precondition.github.io/home-row-mods
    https://ryanis.cool/dactyl/
    https://stevep99.github.io/seniply/k
    https://www.keybr.com/
    https://www.reddit.com/r/olkb/comments/tnbvu3/planned_34_key_layout_to_reduce_rsi_pain_from/
    https://www.reddit.com/r/olkb/comments/y07cb8/new_multimode_use_for_caps_word/
    nice simpler one shot layer with thumb shift and ctrl https://www.youtube.com/watch?v=8wZ8FRwOzhU

*/

#include QMK_KEYBOARD_H
#include "features/secrets.h"

#define _QWERTY 0
#define _MODTAP 1
#define _LANG 2
#define _GAME 3
#define _SYMBOLS 4
#define _NAV 5
#define _RAISE 6
#define _NUMBER 7
#define _FUNC 8
#define _WIN 9
#define _MNAV 10
#define _ONE 11
#define _HIGHQWERTY 14
#define _ADJUST 15

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    ALT_TAB,
    ALT_TABB,
    M_BB1,
    M_BB2,
    M_BB3,
    M_BB4,
    M_QUO1,
    M_QUO2,
    M_QUO3,
    C_MACRO1,
    C_MACRO2,
    C_MACRO3,
    C_MACRO4,
    C_MACRO5,
    DT_CPYTO, // copy + alttab + paste
    DT_MOVE, // cut + alttab + paste
    AUTOFIX,
    SAVENOTE, // copy + go to my notes app + paste + alttab
    BROWSE, // new browser tab
    BROWSEP, // new private browser window
    BROWSEN,
    WINTAP, // just a tap in lgui, to search for stuff
    SETMAIN, // reset state of the keyboard
    UP10,
    DOWN10,
    LEFT10,
    RIGHT10,
    M_GOMA, // hit enter and go to main layer
    M_MSEL, // mouse double click and ctrl c
    M_CIRC, // ^
    M_TILD, // ~
    M_DOTSLH, // ./
    // # ENGLISH
    L_QUOM, // 'm
    L_QUOT, // 't
    L_QUOS, // 's
    L_QUOV, // 'v
    // PORTUGUESE
    L_CEDI, // ç
    L_ACIR, // â
    L_ATIL, // ã
    L_AGRA, // à
    L_AACU, // á
    L_OTIL, // õ
    L_OCIR, // ô
    L_OACU, // ó
    L_ECIR, // ê
    L_EACU, // é
    L_IACU, // í
    L_UACU, // ú
    // num row on main layer
    M_N1,
    M_N2,
    M_N3,
    M_N4,
    M_N5,
    M_N6,
    M_N7,
    M_N8,
    M_N9,
    M_N0,
    M_SCRT1,
    M_SCRT2,
    M_TSTRUN, // run tests
    M_TSTDEB, // debug tests
    M_SELWORD, // select word
    M_BRWTB1, // browser tab 1
    M_BRWTB2, // browser tab 2
    M_BRWTB3, // browser tab 3
};

// #define L_SYMNAV MO(_SYMNAV)

// mod taps
#define ADJ(kc)  LT(_ADJUST, kc)
#define TA(kc) LALT_T(kc)
#define TC(kc) LCTL_T(kc)
#define TS(kc) LSFT_T(kc)
#define TW(kc) LGUI_T(kc)

#define CT_PGDN TC(KC_PGDN)
#define SFT_NEXT TS(KC_F3)
#define SFT_PGUP TS(KC_PGUP)
#define WIN_PGUP LT(_WIN, KC_PGUP)
#define WIN_NEXT LT(_WIN, KC_F3)
#define ONE_TAB LT(_ONE, KC_TAB)
#define ONE_ESC LT(_ONE, KC_ESC)

// oneshots
#define OS_FUNC OSL(_FUNC)
#define OS_SYM  OSL(_SYMBOLS)
#define OS_LANG OSL(_LANG)
#define OS_NUM  OSL(_NUMBER)
#define OS_QWER OSL(_HIGHQWERTY)
#define OS_RAIS OSL(_RAISE)
#define OS_ADJ  OSL(_ADJUST)
#define OS_ONE  OSL(_ONE)
#define OS_WIN  OSL(_WIN)


#define OSM_ALT  OSM(MOD_LALT)
#define OSM_CTRL OSM(MOD_LCTL)
#define OSM_SHFT OSM(MOD_LSFT)

// commands
#define TABNEXT C(KC_PGDN)
#define TABPREV C(KC_PGUP)
#define LASTTAB C(KC_TAB)
#define TAB1 A(KC_1)
#define TAB0 A(KC_0)
#define CLOSETAB C(KC_W)
#define CLOSEAPP A(KC_F4)
#define REDO S(C(KC_Z))
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define COMMENT C(KC_SLSH)
#define DELWORD C(KC_BSPC)
#define FINDP S(KC_F3)
#define SELCT C(KC_D)
#define GOTOLINE C(KC_G)
#define PRINTSCR SGUI(KC_S)
#define FORWARD A(KC_RIGHT)
#define BACK A(KC_LEFT)
#define CTLSPACE C(KC_SPACE)
#define ALTENTER A(KC_ENTER)
#define PIPMODE S(C(KC_RBRC))

// ide specific commands
#define FINDANY S(C(KC_P)) // fuzzy search of anything
#define ASK A(S(C(KC_F))) // ai assistance
#define GOTO C(KC_SCLN) // jump to line/column in my IDE setup
#define I_STOP  S(KC_F5) // stop debug/run
#define I_BUILD S(C(KC_B)) // build
#define I_GOSCM A(KC_9) // RIDER: go to scm tab
#define I_GTEST A(KC_8) // RIDER: go to tests tab
#define I_HIDTA S(KC_ESC) // RIDER: hide tabs
#define I_EXPLR A(KC_1) // RIDER: show explorer
#define I_QUOT C(KC_QUOTE) // used to cycle tabs / maximize and minimize tabs

#define GO_APP1 G(KC_1)
#define GO_APP2 G(KC_2)
#define GO_APP3 G(KC_3)
#define GO_APP4 G(KC_4)
#define GO_APP5 G(KC_5)
#define GO_APP6 G(KC_6)
#define GO_APP7 G(KC_7)
#define GO_APP8 G(KC_8)
#define GO_APP9 G(KC_9)

#define MDSWI C(KC_SCRL) // software macro to switch audio output stream

#define W_LEFT G(KC_LEFT)
#define W_RIGHT G(KC_RIGHT)
#define W_MAX G(KC_UP)
#define W_MIN G(KC_DOWN)
#define W_SWTDSP S(G(KC_LEFT)) // cycle window through displays
#define W_DSKTPNEW C(G(KC_D))
#define W_DSKTPCLOSE C(G(KC_F4))
#define W_DSKTPLEFT C(G(KC_LEFT))
#define W_DSKTPRIGHT C(G(KC_RIGHT))
#define W_DSKTPTAB G(KC_TAB)
#define W_WINPASTE G(KC_V)
#define W_LOCK G(KC_L)
#define W_DSKTPSHOW G(KC_D)
#define CHANGEDISPLAY G(KC_P)

// tap-hold macros
// even though these are LT macros, they are not meant to be used as layer togglers.
// this is a trick to easily diferentiate between tap and hold, as explained here:
// https://getreuer.info/posts/keyboards/triggers/index.html
// TLDR: the layer and the keycode don't mean anything, they are used as identifiers only.
#define TH_APP1 LT(_HIGHQWERTY, KC_1)
#define TH_APP2 LT(_HIGHQWERTY, KC_2)
#define TH_APP3 LT(_HIGHQWERTY, KC_3)
#define TH_AMPR LT(_HIGHQWERTY, KC_5)
#define TH_EXLM LT(_HIGHQWERTY, KC_6)
#define TH_COLON LT(_HIGHQWERTY, KC_7)
#define TH_PLUS LT(_HIGHQWERTY, KC_8)
#define TH_BSLS LT(_HIGHQWERTY, KC_9)
#define TH_BACK LT(_HIGHQWERTY, KC_LEFT)
#define TH_CLIC2 LT(_HIGHQWERTY, KC_Q)
#define TH_SELCT LT(_HIGHQWERTY, KC_S)
#define TH_FIND LT(_HIGHQWERTY, KC_P)
#define TH_COMM LT(_HIGHQWERTY, KC_COMM)
#define TH_DOT LT(_HIGHQWERTY, KC_DOT)
#define TH_END LT(_HIGHQWERTY, KC_END)
#define TH_EQL LT(_HIGHQWERTY, KC_EQL)
#define TH_HOME LT(_HIGHQWERTY, KC_HOME)
#define TH_MINS LT(_HIGHQWERTY, KC_MINS)
#define TH_PGUP LT(_HIGHQWERTY, KC_PGUP)
#define TH_PIPE LT(_HIGHQWERTY, KC_PIPE)
#define TH_SCLN LT(_HIGHQWERTY, KC_SCLN)
#define TH_SLSH LT(_HIGHQWERTY, KC_SLSH)

// toggles
#define SET_NAV TO(_NAV)
#define SET_FUN TO(_FUNC)
#define SET_NUM TO(_NUMBER)
#define SET_MNAV TO(_MNAV)
#define T_MODTAP TG(_MODTAP)

// software defined macros.
#define C_MACRO KC_F19

// eye tracker key: toogles the mouse eye tracking
#define KX_MEYE X_F14

// tap dances
#define TD_ALTAB TD(TDK_AT)
#define TD_ATB TD(TDK_ATB)
#define TD_ALFU TD(TDK_ALTFUN)
#define TD_1SHOT TD(TDK_1SHOT)
#define TD_CLICK TD(TDK_CLICK)
#define TD_THUMBR TD(TDK_THMBR1N)

// macros
#define SS_ALTTAB SS_DOWN(X_LALT) SS_DELAY(10) SS_TAP(X_TAB) SS_DELAY(10) SS_UP(X_LALT)
#define SS_COPY SS_LCTL(SS_TAP(X_C))
#define SS_PASTE SS_LCTL(SS_TAP(X_V))
#define SS_CUT SS_LCTL(SS_TAP(X_X))
#define SS_GOAPP(kc) SS_LGUI(SS_LCTL(SS_TAP(kc)))
#define SS_BACK SS_DELAY(20)  SS_TAP(X_LEFT)

// helpers
#define GET_ONESHOT_SHIFT get_oneshot_mods() & MOD_BIT(KC_LSFT)
#define GET_SHIFT get_mods() & MOD_BIT(KC_LSFT)

//tap dances
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (!state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    }
    else return TD_UNKNOWN;
}

static td_state_t td_state_alttab;
static bool at_press_mouse;
void td_alttab_finished(tap_dance_state_t *state, void *user_data) {
    td_state_alttab = cur_dance(state);
    switch (td_state_alttab) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_ALTTAB);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_MNAV);
            SEND_STRING(SS_DOWN(KX_MEYE));
            at_press_mouse = true;
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(80) SS_TAP(X_TAB) SS_DELAY(20) SS_UP(X_LALT));
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(30) SS_UP(X_LALT) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

void alttab_reset(tap_dance_state_t *state, void *user_data) {
    bool oneshotShifted = GET_ONESHOT_SHIFT;
    bool regularShifted = GET_SHIFT;
    bool shifted = oneshotShifted || regularShifted;

    switch (td_state_alttab) {
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_TAP(X_ENTER));
            break;
        case TD_SINGLE_HOLD:
            layer_off(_MNAV);
            SEND_STRING(SS_UP(KX_MEYE));
            if(shifted == false && at_press_mouse) SEND_STRING(SS_TAP(X_BTN1));
            break;
        default:
            break;
    }
}

static td_state_t td_state_atb;
void td_atb_finished(tap_dance_state_t *state, void *user_data) {
    td_state_atb = cur_dance(state);
    switch (td_state_atb) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB));
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

void td_atb_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_atb) {
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

static td_state_t td_state_altfun;
void td_altfun_finished(tap_dance_state_t *state, void *user_data) {
    td_state_altfun = cur_dance(state);
    switch (td_state_altfun) {
        case TD_SINGLE_TAP:
            set_oneshot_layer(_FUNC, ONESHOT_START);
            break;
        case TD_SINGLE_HOLD:
            add_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

void td_altfun_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_altfun) {
        case TD_SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_SINGLE_HOLD:
            del_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

#define DEFAULT_ONESHOT_MOD MOD_BIT(KC_LCTL)

static td_state_t td_state_oneshot;
void td_oneshot_finished(tap_dance_state_t *state, void *user_data) {
    td_state_oneshot = cur_dance(state);

    uint8_t mod_state = get_mods();
    if (mod_state == 0) {
        // when this TD is pressed we need to have at least one mod, since it does not make sense to use this TD wihout a mod.
        mod_state = DEFAULT_ONESHOT_MOD;
    }

    switch (td_state_oneshot) {
        case TD_SINGLE_TAP:
            // convert any mods to one shots
            add_oneshot_mods(mod_state);
            set_oneshot_layer(_HIGHQWERTY, ONESHOT_START);
            break;
        case TD_SINGLE_HOLD:
            // add default mods
            layer_on(_HIGHQWERTY);
            add_mods(mod_state);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_F)));
            break;
        default:
            break;
    }
}

void td_oneshot_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_oneshot) {
        case TD_SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            // clear_mods();
            // clear_oneshot_mods();
            // clear_keyboard_but_mods();
            // add_oneshot_mods(mod_state);
            // add_weak_mods(MOD_BIT(KC_LSFT));
            // reset_oneshot_layer(). // cancel the oneshot
            // reset_tap_dance(state);
            break;
        case TD_SINGLE_HOLD:
            layer_off(_HIGHQWERTY);

            // only clear mods if only the default mod is being used
            if (get_mods() == DEFAULT_ONESHOT_MOD) {
                clear_mods();
            }
            break;
        default:
            break;
    }
}

static td_state_t td_state_click;
void td_click_finished(tap_dance_state_t *state, void *user_data) {
    td_state_click = cur_dance(state);
    switch (td_state_click) {
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_BTN2) SS_DELAY(800) SS_TAP(X_P)); // open link in a new private window
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_BTN1)); // hold mouse button 1 until it is pressed again
            break;
        case TD_SINGLE_TAP:
        default:
            SEND_STRING(SS_TAP(X_BTN1));
            break;
    }
}

static td_state_t td_state_thmbr1n;
void td_thmbr1n_finished(tap_dance_state_t *state, void *user_data) {
    td_state_thmbr1n = cur_dance(state);
    switch (td_state_thmbr1n) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)));
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_ENTER)));
            break;
        case TD_SINGLE_HOLD:
        default:
            layer_on(_RAISE);
            break;
    }
}

void td_thmbr1n_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_thmbr1n) {
        case TD_DOUBLE_TAP:
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
        default:
            layer_off(_RAISE);
            break;

    }
}

// Tap Dance declarations
enum tap_dance{
    TDK_AT,
    TDK_ATB,
    TDK_ALTFUN,
    TDK_1SHOT,
    TDK_CLICK,
    TDK_THMBR1N,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TDK_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_click_finished, NULL),
    [TDK_1SHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_oneshot_finished, td_oneshot_reset),
    [TDK_AT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alttab_finished, alttab_reset),
    [TDK_ATB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_atb_finished, td_atb_reset),
    [TDK_ALTFUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_altfun_finished, td_altfun_reset),
    [TDK_THMBR1N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_thmbr1n_finished, td_thmbr1n_reset),
};

// tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_ALTAB:
            return 200;
        case TH_END:
        case TH_HOME:
            return 250;
        case TD_THUMBR:
            return 220;
        case TD_1SHOT:
            return 170;
        case TD_ATB:
            return 200;
        case TH_APP1:
        case TH_APP2:
        case TH_APP3:
            return 600;
        default:
            return TAPPING_TERM;
    }
}

#define clear_shift del_mods(MOD_BIT(KC_LSFT)); del_oneshot_mods(MOD_BIT(KC_LSFT));
#define restore_shift if (regularShifted) add_mods(MOD_BIT(KC_LSFT));

// process macros
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool oneshotShifted = GET_ONESHOT_SHIFT;
    bool regularShifted = GET_SHIFT;
    bool shifted = oneshotShifted || regularShifted;

    // getting information to differentiate between presses and holds
    bool pressed = record->event.pressed;
    bool hold = record->tap.count == 0;

    // after some key presses, mostly keys in the _MNAV layer, we want to cancel the click on release of TDK_AT
    switch (keycode)
    {
        case TD_CLICK:
        case TH_CLIC2:
        case TH_SELCT:
        case CLOSEAPP:
        case CLOSETAB:
        case KC_BTN1:
        case KC_BTN2:
        case KC_BTN3:
        case GO_APP1:
        case GO_APP2:
        case GO_APP3:
        case GO_APP4:
        case GO_APP5:
        case GO_APP6:
        case GO_APP7:
        case GO_APP8:
        case GO_APP9:
        case TH_APP1:
        case TH_APP2:
        case TH_APP3:
        case TABNEXT:
        case TABPREV:
        case TD_ATB:
        case W_MIN:
        case W_MAX:
        case W_SWTDSP:
        case W_LEFT:
        case W_RIGHT:
            at_press_mouse = false;
        default:
            break;
    }

    // special shifted number macros
    #define process_shifted_keys(regular_key, shifted_key) if (shifted) { clear_shift;  tap_code16(shifted_key); restore_shift; } else { if (pressed) tap_code16(regular_key); } return false;
    switch (keycode) {
            case M_N1:
                process_shifted_keys(KC_1, KC_F1);
            case M_N2:
                process_shifted_keys(KC_2, KC_F2);
            case M_N3:
                process_shifted_keys(KC_3, KC_F3);
            case M_N4:
                process_shifted_keys(KC_4, KC_F4);
            case M_N5:
                process_shifted_keys(KC_5, KC_F5);
            case M_N6:
                process_shifted_keys(KC_6, KC_F6);
            case M_N7:
                process_shifted_keys(KC_7, KC_F7);
            case M_N8:
                process_shifted_keys(KC_8, KC_F8);
            case M_N9:
                process_shifted_keys(KC_9, KC_F9);
            case M_N0:
                process_shifted_keys(KC_0, KC_F10);
    }

    // tap-hold key macros
    #define process_tap_and_hold(actionOnTap, actionOnHold) if (pressed) hold ? actionOnHold : actionOnTap; return false;
    #define process_double_tap_on_hold(keycode) if (pressed && hold) tap_code16(keycode); if (pressed) tap_code16(keycode); return false;
    switch (keycode) {
        case TH_MINS:
            process_double_tap_on_hold(KC_MINS);
        case TH_EQL:
            process_double_tap_on_hold(KC_EQL);
        case TH_PLUS:
            process_double_tap_on_hold(KC_PLUS);
        case TH_AMPR:
            process_double_tap_on_hold(KC_AMPR);
        case TH_PIPE:
            process_double_tap_on_hold(KC_PIPE);
        case TH_BSLS:
            process_double_tap_on_hold(KC_BSLS);
        case TH_SLSH:
            process_double_tap_on_hold(KC_SLSH);
        case TH_APP1:
            process_tap_and_hold(tap_code16(GO_APP1), tap_code16(S(GO_APP1)));
        case TH_APP2:
            process_tap_and_hold(tap_code16(GO_APP2), tap_code16(S(GO_APP2)));
        case TH_APP3:
            process_tap_and_hold(tap_code16(GO_APP3), tap_code16(S(GO_APP3)));
        case TH_BACK:
            process_tap_and_hold(tap_code16(A(KC_LEFT)), tap_code16(A(KC_RIGHT)));
        case TH_COLON:
            process_tap_and_hold(SEND_STRING(":"), SEND_STRING(":\\"));
        case TH_EXLM:
            process_tap_and_hold(SEND_STRING("!"), SEND_STRING("!="));
        case TH_HOME:
            process_tap_and_hold(tap_code16(KC_HOME), tap_code16(C(KC_HOME)));
        case TH_END:
            process_tap_and_hold(tap_code16(KC_END), tap_code16(C(KC_END)));
        case TH_CLIC2:
            process_tap_and_hold(tap_code16(KC_BTN3), tap_code(KC_BTN2));
        case TH_PGUP:
            process_tap_and_hold(tap_code16(KC_PGUP), tap_code(KC_LGUI));
        case TH_COMM:
            process_tap_and_hold(SEND_STRING(","), SEND_STRING("?"));
        case TH_SCLN:
            process_tap_and_hold(SEND_STRING(";"), SEND_STRING("="));
        case TH_FIND:
            if(pressed){
                if (hold){
                    // BROWSEP
                    SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50));
                    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_P))) SS_DELAY(300));
                    SEND_STRING(SS_PASTE SS_DELAY(10));
                    SEND_STRING(SS_LCTL(SS_TAP(X_A)));
                }else{
                    tap_code16(S(C(KC_P)));
                }
            }
            return false;
        case TH_SELCT:
            if (hold){
                if (pressed) SEND_STRING(SS_DOWN(X_BTN1));
                else SEND_STRING(SS_UP(X_BTN1) SS_DELAY(5) SS_LCTL(SS_TAP(X_C)));
            }else{
                // select hovered text and copy it
                if (pressed) SEND_STRING(SS_TAP(X_BTN1)SS_DELAY(5) SS_TAP(X_BTN1) SS_DELAY(5) SS_LCTL(SS_TAP(X_C)));
            }
            return false;
        case TH_DOT:
            if (shifted){
                if (pressed){
                    clear_shift;
                    SEND_STRING(". ");
                    restore_shift;
                }
            }else{
                process_tap_and_hold(SEND_STRING("."), SEND_STRING("!"));
            }
            return false;

    }

    // special key macros
    if (pressed) {
        switch (keycode) {
            case M_SCRT1:
                SEND_STRING(SECRET1);
                return false;
            case M_SCRT2:
                SEND_STRING(SECRET2);
                return false;
            case SETMAIN:
                // tap_code16(SH_OFF);
                layer_clear();
                clear_keyboard();
                return false;
            case WINTAP:
                SEND_STRING(SS_TAP(X_LGUI));
                return false;
            case M_BB1:
                if (shifted){
                    SEND_STRING(")");
                }else{
                    SEND_STRING("()" SS_BACK);
                }
                return false;
            case M_BB2:
                if (shifted) {
                    SEND_STRING("}");
                }else{
                    SEND_STRING("{}" SS_BACK);
                }
                return false;
            case M_BB3:
                if (shifted) {
                    clear_shift;
                    SEND_STRING("]");
                    restore_shift;
                }else{
                    SEND_STRING("[]" SS_BACK);
                }
                return false;
            case M_BB4:
                if (shifted) {
                    SEND_STRING(">");
                }else{
                    SEND_STRING("<>" SS_BACK);
                }
                return false;
            case M_QUO1:
                if (shifted) {
                    SEND_STRING("\" ");
                }else{
                    SEND_STRING("\"\"" SS_BACK);
                }
                return false;
            case M_QUO2:
                if (shifted) {
                    clear_shift;
                    SEND_STRING("' ");
                    restore_shift;
                }else{
                    SEND_STRING("''" SS_BACK);
                }
                return false;
            case M_QUO3:
                if (shifted) {
                    clear_shift;
                    SEND_STRING("` ");
                    restore_shift;
                }else{
                    SEND_STRING("``" SS_BACK);
                }
                return false;
            case C_MACRO1:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_1) SS_UP(X_F17));
                return false;
            case C_MACRO2:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_2) SS_UP(X_F17));
                return false;
            case C_MACRO3:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_3) SS_UP(X_F17));
                return false;
            case C_MACRO4:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_4) SS_UP(X_F17));
                return false;
            case C_MACRO5:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_5) SS_UP(X_F17));
                return false;
            case ALT_TAB:
                SEND_STRING(SS_ALTTAB);
                return false;
            case ALT_TABB:
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_TAB) SS_DELAY(50) SS_TAP(X_TAB) SS_UP(X_LALT));
                return false;
            case BROWSE:
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50));
                SEND_STRING(SS_LCTL(SS_TAP(X_T)) SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_TAP(X_ENTER));
                return false;
            case BROWSEP:
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50));
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_P))) SS_DELAY(300));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_LCTL(SS_TAP(X_A)));
                return false;
            case BROWSEN:
                SEND_STRING(SS_LCTL(SS_TAP(X_T)) SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_TAP(X_ENTER));
                return false;
            case DT_CPYTO:
                SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(20));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                return false;
            case DT_MOVE:
                SEND_STRING(SS_CUT SS_DELAY(10));
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(20));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                return false;
            case SAVENOTE:
                SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_GOAPP(X_2) SS_DELAY(100));
                SEND_STRING(SS_LALT(SS_TAP(X_1) SS_DELAY(50)));
                SEND_STRING(SS_LCTL(SS_TAP(X_HOME) SS_DELAY(5) SS_TAP(X_V) SS_DELAY(10)));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                return false;
            case AUTOFIX:
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(5) SS_TAP(X_APP) SS_DELAY(200) SS_TAP(X_DOWN) SS_TAP(X_ENTER));
                return false;
            case UP10:
                SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
                return false;
            case DOWN10:
                SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN));
                return false;
            case LEFT10:
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                return false;
            case RIGHT10:
                SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
                return false;
            case M_MSEL:
                SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(5) SS_TAP(X_BTN1) SS_DELAY(5) SS_LCTL(SS_TAP(X_C)));
                return false;
            case M_SELWORD:
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT) SS_LSFT(SS_TAP(X_LEFT))));
                return false;
            case M_CIRC:
                SEND_STRING("^ "); // ^
                return false;
            case M_TILD:
                SEND_STRING("~ "); // ~
                return false;
            case M_DOTSLH:
                SEND_STRING("./"); // ./
                return false;
            case L_QUOM:
                SEND_STRING("' m"); // 'm
                return false;
            case L_QUOT:
                SEND_STRING("' t"); // 't
                return false;
            case L_QUOS:
                SEND_STRING("' s"); // 's
                return false;
            case L_QUOV:
                SEND_STRING("' v"); // 'v
                return false;
            case L_CEDI:
                SEND_STRING(SS_RALT(SS_TAP(X_COMM))); // ç
                return false;
            case L_ACIR:
                SEND_STRING("^a"); // â
                return false;
            case L_ATIL:
                SEND_STRING("~a"); // ã
                return false;
            case L_AGRA:
                SEND_STRING("`a"); // à
                return false;
            case L_AACU:
                SEND_STRING("'a"); // á
                return false;
            case L_OTIL:
                SEND_STRING("~o"); // õ
                return false;
            case L_OCIR:
                SEND_STRING("^o"); // ô
                return false;
            case L_OACU:
                SEND_STRING("'o"); // ó
                return false;
            case L_ECIR:
                SEND_STRING("^e"); // ê
                return false;
            case L_EACU:
                SEND_STRING("'e"); // é
                return false;
            case L_IACU:
                SEND_STRING("'i"); // í
                return false;
            case L_UACU:
                SEND_STRING("'u"); // ú
                return false;
            case M_GOMA:
                SEND_STRING(SS_TAP(X_ENTER));
                layer_off(_NUMBER);
                return false;
            case M_TSTRUN:
                SEND_STRING(SS_LSFT(SS_TAP(X_F5)) SS_LALT(SS_TAP(X_8)) SS_LCTL(SS_TAP(X_T)) SS_LCTL(SS_TAP(X_R)));
                return false;
            case M_TSTDEB:
                SEND_STRING(SS_LSFT(SS_TAP(X_F5)) SS_LALT(SS_TAP(X_8)) SS_LCTL(SS_TAP(X_T)) SS_LCTL(SS_TAP(X_D)));
                return false;
            case M_BRWTB1:
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50) SS_LCTL(SS_TAP(X_1)));
                return false;
            case M_BRWTB2:
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50) SS_LCTL(SS_TAP(X_2)));
                return false;
            case M_BRWTB3:
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50) SS_LCTL(SS_TAP(X_3)));
                return false;
        }
    }
    return true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // accessibility map
    //     11, 5 , 5 , 4 , 4 , 6 ,
    //     8 , 5 , 3 , 1 , 1 , 3 ,
    //     4 , 3 , 2 , 0 , 0 , 2 ,
    //     7 , 4 , 3 , 1 , 1 , 3 ,

    [_QWERTY] = LAYOUT_5x6(
        OS_ADJ  , M_N1  , M_N2  , M_N3  , M_N4  , M_N5  ,           M_N6  , M_N7  , M_N8  , M_N9   , M_N0   ,W_LOCK ,
        KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,           KC_Y  , KC_U  , KC_I  , KC_O   , KC_P   ,KC_ESC ,
        OS_SYM  , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,           KC_H  , KC_J  , KC_K  , KC_L   , OS_LANG,OS_SYM ,
        SETMAIN , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,           KC_N  , KC_M  ,TH_COMM, TH_DOT , TH_SCLN,SETMAIN,
                          KC_WH_U,KC_WH_D,                                         KC_WH_D, KC_WH_U,
                             LT(_NAV, KC_BSPC) ,OSM_SHFT,           LT(_NAV, KC_ENTER), LT(_NAV, KC_SPACE),
                                      OS_ONE   ,TD_ALTAB,           TD_ALTAB, OS_ONE ,
                                      SETMAIN  ,KC_BTN1 ,           KC_BTN1 , SETMAIN
    ),

    [_NAV] = LAYOUT_5x6(
        _______,C_MACRO5,C_MACRO4,C_MACRO3,C_MACRO2,C_MACRO1,       C_MACRO1,C_MACRO2,C_MACRO3,C_MACRO4,C_MACRO5,_______,
        _______,ASK     ,TH_FIND ,TH_PGUP ,TH_BACK ,KC_TAB  ,       DELWORD ,TH_HOME ,KC_UP   ,TH_END  ,GOTO    ,_______,
        KC_ESC ,TD_ALFU ,SFT_NEXT,CT_PGDN ,TD_1SHOT,OS_NUM  ,       KC_BSPC ,KC_LEFT ,KC_DOWN ,KC_RIGHT,QK_LOCK ,_______,
        _______,UNDO    ,CUT     ,COPY    ,PASTE   ,COMMENT ,       KC_DEL  ,TD_ATB  ,TABPREV ,TABNEXT ,KC_APP  ,_______,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                             _______,_______,       _______,TD_THUMBR,
                                             _______,_______,       _______,_______,
                                             _______,_______,       _______,_______
    ),

    [_FUNC] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______ ,       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______,XXXXXXX ,PIPMODE ,BROWSE  ,BROWSEP ,M_BRWTB1,       KC_CAPS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,_______ ,
        KC_ESC ,OSM_ALT ,OSM_SHFT,OSM_CTRL,AUTOFIX ,KC_MYCM ,       XXXXXXX ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,_______ ,
        _______,XXXXXXX ,DT_MOVE ,DT_CPYTO,SAVENOTE,PRINTSCR,       KC_INS  ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______
    ),

    [_SYMBOLS] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______ ,       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______,KC_QUES ,KC_DLR  ,KC_LABK ,KC_RABK ,KC_HASH ,       TH_AMPR ,M_QUO3  ,M_BB3   ,KC_PERC ,KC_RBRC ,_______ ,
        KC_ESC ,TH_EXLM ,TH_MINS ,TH_PLUS ,TH_EQL  ,KC_UNDS ,       TH_PIPE ,M_QUO1  ,M_BB1   ,KC_AT   ,KC_RPRN ,_______ ,
        _______,M_DOTSLH,KC_ASTR ,TH_SLSH ,TH_BSLS ,TH_COLON,       M_TILD  ,M_QUO2  ,M_BB2   ,M_CIRC  ,KC_RCBR ,_______ ,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______ ,
                                           _______ ,_______ ,      _______ ,_______
    ),

    [_MNAV] = LAYOUT_5x6(
        _______ ,W_MIN   ,W_LEFT  ,W_SWTDSP,W_MAX   ,W_RIGHT ,      W_RIGHT ,W_MAX   ,W_SWTDSP,W_LEFT  ,W_MIN   ,_______ ,
        _______ ,CLOSEAPP,TH_CLIC2,KC_MS_U ,TD_CLICK,TH_APP3 ,      TH_APP3 ,TD_CLICK,KC_MS_U ,TH_CLIC2,CLOSEAPP,_______ ,
        KC_ESC  ,TH_SELCT,KC_MS_L ,KC_MS_D ,KC_MS_R ,TH_APP2 ,      TH_APP2 ,KC_MS_L ,KC_MS_D ,KC_MS_R ,TH_SELCT,_______ ,
        _______ ,CLOSETAB,TABPREV ,TABNEXT ,TD_ATB  ,TH_APP1 ,      TH_APP1 ,TD_ATB  ,TABPREV ,TABNEXT ,CLOSETAB,_______ ,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______
    ),

    [_NUMBER] = LAYOUT_5x6(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,KC_QUES ,KC_DLR  ,KC_LABK ,KC_RABK ,KC_HASH ,      DELWORD ,KC_7    ,KC_8    ,KC_9    ,KC_COMM ,_______ ,
        KC_ESC  ,TH_EXLM ,TH_MINS ,TH_PLUS ,TH_EQL  ,KC_UNDS ,      KC_BSPC ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,_______ ,
        _______ ,M_DOTSLH,KC_ASTR ,TH_SLSH ,TH_BSLS ,TH_COLON,      KC_DEL  ,KC_1    ,KC_2    ,KC_3    ,KC_DOT  ,_______ ,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______
    ),

    [_WIN] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______ ,       _______ ,_______ ,_______ ,_______ ,_______ ,_______,
        _______,XXXXXXX ,KC_MNXT ,KC_MPLY ,KC_VOLU ,KC_MUTE ,       KC_MUTE ,KC_VOLU ,KC_MPLY ,KC_MNXT ,XXXXXXX ,_______,
        _______,XXXXXXX ,KC_MPRV ,MDSWI   ,KC_VOLD ,KC_MSEL ,       KC_MSEL ,KC_VOLD ,MDSWI   ,KC_MPRV ,XXXXXXX ,_______,
        _______,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______,
                         _______ ,_______ ,                                           _______ ,_______ ,
                                            _______,_______ ,       _______,_______,
                                            _______,_______ ,       _______,_______,
                                            _______,_______ ,       _______,_______
    ),

    [_LANG] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,L_ATIL ,L_ACIR ,L_EACU ,_______,L_QUOT ,            _______,L_UACU ,L_IACU ,L_OACU ,_______,_______,
        _______,L_AACU ,L_QUOS ,L_ECIR ,_______,_______,            M_SCRT2,M_SCRT1,L_OCIR ,L_OTIL ,_______,_______,
        _______,L_AGRA ,_______,L_CEDI ,L_QUOV ,_______,            _______,L_QUOM ,_______,_______,_______,_______,
                        _______,_______,                                            _______,_______,
                                        _______,_______,            _______,_______,
                                        _______,_______,            _______,_______,
                                        _______,_______,            _______,_______
    ),

    [_ONE] = LAYOUT_5x6(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,SET_NUM ,SET_FUN ,SET_NAV ,_______ ,      _______ ,SET_NAV ,SET_FUN ,SET_NUM ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                          _______ ,_______ ,                                          _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            SETMAIN ,_______ ,      _______ ,SETMAIN ,
                                            _______ ,_______ ,      _______ ,_______
    ),

    [_MODTAP] = LAYOUT_5x6(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,TW(KC_A),TA(KC_S),TC(KC_D),TS(KC_F),_______ ,      _______ ,TS(KC_J),TC(KC_K),TA(KC_L),_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                          _______ ,_______ ,                                          _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______ ,
                                            _______ ,_______ ,      _______ ,_______
    ),

    [_RAISE] = LAYOUT_5x6(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         I_QUOT  ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,I_STOP  ,M_TSTDEB,M_TSTRUN,I_BUILD ,         I_EXPLR ,I_HIDTA ,I_GTEST ,I_GOSCM ,_______ ,_______ ,
                          _______ ,_______ ,                                          _______ ,_______ ,
                                            _______ ,_______ ,         _______ ,_______ ,
                                            _______ ,_______ ,         _______ ,_______ ,
                                            _______ ,_______ ,         _______ ,_______
    ),

    [_GAME] = LAYOUT_5x6(
        _______ , KC_1    , KC_2  , KC_3  , KC_4  , KC_5  ,          KC_6  , KC_7  , KC_8  , KC_9  , KC_0   ,_______ ,
        _______ , KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  ,          KC_T  , KC_Y  , KC_U  , KC_I  , KC_O   ,_______ ,
        KC_ESC  , KC_LCTL , KC_A  , KC_S  , KC_D  , KC_F  ,          KC_G  , KC_H  , KC_J  , KC_K  , KC_L   ,_______ ,
        KC_LALT , KC_LSFT , KC_Z  , KC_X  , KC_C  , KC_V  ,          KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT ,_______ ,
                          _______ ,_______,                                         _______,_______,
                                         KC_SPACE, KC_ENT  ,         _______ , _______ ,
                                         _______ , _______ ,         _______ , _______ ,
                                         _______ , _______ ,         _______ , _______
    ),

    [_HIGHQWERTY] = LAYOUT_5x6(
        _______ , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,            KC_6  , KC_7  , KC_8  , KC_9   , KC_0   ,_______ ,
        KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,            KC_Y  , KC_U  , KC_I  , KC_O   , KC_P   ,_______ ,
        KC_ESC ,  KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,            KC_H  , KC_J  , KC_K  , KC_L   , KC_QUOT,_______ ,
        _______ , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,            KC_N  , KC_M  ,KC_COMM, KC_DOT , KC_SLSH,_______ ,
                        _______, _______,                                           _______, _______,
                                         KC_BSPC , _______ ,           KC_ENT  ,KC_SPACE,
                                         _______ , _______ ,           _______ ,_______ ,
                                         _______ , _______ ,           _______ ,_______
    ),

    [_ADJUST] = LAYOUT_5x6(
        SETMAIN,_______,T_MODTAP,_______,TO(_QWERTY),TO(_GAME),     _______,_______,_______,_______,_______,KC_KB_POWER,
        _______,_______,QK_BOOT,_______,_______,_______,            _______,_______,_______,QK_BOOT,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                        _______,_______,                                            _______,_______,
                                        _______,_______,            _______,_______,
                                        _______,_______,            _______,_______,
                                        _______,_______,            _______,_______
    ),
};

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{5,10}, {4,10}, {3,10}, {2,10}, {1,10}, {0,10}},
    {{5,11}, {4,11}, {3,11}, {2,11}, {1,11}, {0,11}},

    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};

// ============ COMBOS

const uint16_t PROGMEM comboJK[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM comboDF[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM comboCV[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comboMC[] = {KC_M, TH_COMM, COMBO_END};
const uint16_t PROGMEM comboER[] = {KC_E, KC_R, COMBO_END}; // bad combo: easy to mistype when fast typing
const uint16_t PROGMEM comboUI[] = {KC_U, KC_I, COMBO_END}; // bad combo: easy to mistype when fast typing
const uint16_t PROGMEM comboSD[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM comboKL[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM comboXC[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comboCD[] = {TH_COMM, TH_DOT, COMBO_END};
const uint16_t PROGMEM comboWE[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM comboIO[] = {KC_I, KC_O, COMBO_END}; // bad combo: easy to mistype when fast typing
const uint16_t PROGMEM comboMM[] = {KC_WH_U, KC_WH_D, COMBO_END};
const uint16_t PROGMEM comboFJ[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM comboT1[] = {LT(_NAV, KC_BSPC), LT(_NAV, KC_SPACE), COMBO_END};
const uint16_t PROGMEM comboT2[] = {LT(_NAV, KC_BSPC), LT(_NAV, KC_ENTER), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // left hand                                                    // right hand
    COMBO(comboWE, OS_WIN),     /*COMBO(comboER, OS_WIN),*/         /*COMBO(comboUI, OS_WIN),*/ COMBO(comboIO, OS_WIN),
    COMBO(comboSD, OS_ONE),     COMBO(comboDF, OS_SYM),             COMBO(comboJK, OS_SYM),     COMBO(comboKL, OS_ONE),
    COMBO(comboXC, OS_RAIS),    COMBO(comboCV, OS_FUNC),            COMBO(comboMC, OS_FUNC),    COMBO(comboCD, OS_RAIS),

    // other combos
    COMBO(comboMM, SET_MNAV),
    // COMBO(comboFJ, OS_ONE),
    COMBO(comboT1, OS_SYM),
    COMBO(comboT2, OS_SYM),
};
