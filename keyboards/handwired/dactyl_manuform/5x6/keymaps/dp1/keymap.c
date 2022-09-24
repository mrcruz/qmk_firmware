/*

TODO:
    add combo to osm ctrl+alt?
    use swap hands
    maybe i need a layer with all the one shot modifiers for keys that need to be pressed once
    KC_REPEAT
    KC_STOP
    KC_PPLS
    KC_LEAD https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_leader_key.md
    KC_LOCK https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_key_lock.md

how to improve?
    taps are less stressful than holds
    move things to one shot mods
    repeat last action button
    what am I using more?
    single press shortcuts should be one single shot away
    everything 2 key presses away

MANUAL
    mods and layer methods
        https://github.com/qmk/qmk_firmware/blob/master/quantum/action_util.h

REFERENCES
    https://github.com/manna-harbour/miryoku
    https://stevep99.github.io/seniply/k
    https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
    https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md
    https://imgur.com/gallery/l1xNsoO
    https://github.com/Yowkees/keyball
    http://thedarnedestthing.com/planck%20one%20shot
    http://thedarnedestthing.com/planck%20qmk
    https://colemakmods.github.io/ergonomic-mods/wide.html
    https://configure.zsa.io/ergodox-ez/layouts/GWjD3/latest/1
    https://configure.zsa.io/planck-ez/layouts/Wblvj/latest/0
    https://configure.zsa.io/planck-ez/search?q=qwerty&page=1&legacy=false&anonymous=false&withTour=false
    https://dreymar.colemak.org/layers-extend.html
    https://forum.colemak.com/topic/2014-extend-extra-extreme/
    https://geekhack.org/index.php?topic=51069.0
    https://getreuer.info/posts/keyboards/macros/index.html#overview
    https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
    https://github.com/getreuer/qmk-keymap/blob/main/README.md
    https://github.com/klavgen/klavgen
    https://github.com/precondition/dactyl-manuform-keymap
    https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
    https://github.com/rafaelromao/keyboards
    https://keymapdb.com/
    https://precondition.github.io/home-row-mods
    https://www.keybr.com/
    https://www.reddit.com/r/olkb/comments/tnbvu3/planned_34_key_layout_to_reduce_rsi_pain_from/
    nice simpler one shot layer with thumb shift and ctrl https://www.youtube.com/watch?v=8wZ8FRwOzhU

*/

#include QMK_KEYBOARD_H
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
#define _HIGHQWERTY 14
#define _ADJUST 15

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    ALT_TAB,
    ALT_TABB,
    SLOWTAB,
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
    DT_CPYTO,
    DT_CPYFR,
    DT_MOVE,
    AUTOFIX,
    SAVENOTE,
    BROWSE, // new browser tab
    BROWSEP, // new private browser window
    BROWSEN,
    WINTAP, // just a tap in lgui, to search for stuff
    UP10,
    DOWN10,
    LEFT10,
    RIGHT10,
    M_GOMA, // hit enter and go to main layer
    M_MSEL, // mouse double click and ctrl c
    M_CIRC, // ^
    M_TILD, // ~
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
    M_TSTRUN, // run tests
    M_TSTDEB, // debug tests
};

// #define L_SYMNAV MO(_SYMNAV)

// mod taps
#define ADJ(kc)  LT(_ADJUST, kc)
#define TA(kc) LALT_T(kc)
#define TC(kc) LCTL_T(kc)
#define TS(kc) LSFT_T(kc)

#define CT_PGDN TC(KC_PGDN)
#define SFT_NEXT TS(KC_F3)
#define WIN_PGUP LT(_WIN, KC_PGUP)

// oneshots
#define OS_FUNC OSL(_FUNC)
#define OS_SYM  OSL(_SYMBOLS)
#define OS_LANG OSL(_LANG)
#define OS_NUM  OSL(_NUMBER)
#define OS_QWER OSL(_HIGHQWERTY)
#define OS_RAIS OSL(_RAISE)

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

// ide specific commands
#define FINDANY S(C(KC_P)) // fuzzy search of anything
#define GOTO C(KC_SCLN) // jump to line/column in my IDE setup
#define I_BUILD S(C(KC_B)) // build
#define I_GOSCM A(KC_9) // RIDER: go to scm tab
#define I_GTEST A(KC_8) // RIDER: go to tests tab
#define I_HIDTA A(KC_0) // RIDER: hide tabs

#define GO_APP1 C(G(KC_1))
#define GO_APP2 C(G(KC_2))
#define GO_APP3 C(G(KC_3))
#define GO_APP4 C(G(KC_4))
#define GO_APP5 C(G(KC_5))
#define GO_APP6 C(G(KC_6))
#define GO_APP7 C(G(KC_7))
#define GO_APP8 C(G(KC_8))
#define GO_APP9 C(G(KC_9))

#define MDNXT KC_MNXT
#define MDPRV KC_MPRV
#define MDPLY KC_MPLY
#define MDVOLU KC_VOLU
#define MDVOLD KC_VOLD
#define MDMUTE KC_MUTE
#define MDSWI C(KC_SCRL) // software macro to switch audio output stream

#define W_LEFT G(KC_LEFT)
#define W_RIGHT G(KC_RIGHT)
#define W_MAX G(KC_UP)
#define W_MIN G(KC_DOWN)
#define W_SRIGHT S(G(KC_RIGHT))
#define W_SLEFT S(G(KC_LEFT))
#define W_DSKTPNEW C(G(KC_D))
#define W_DSKTPCLOSE C(G(KC_F4))
#define W_DSKTPLEFT C(G(KC_LEFT))
#define W_DSKTPRIGHT C(G(KC_RIGHT))
#define W_DSKTPTAB G(KC_TAB)
#define W_WINPASTE G(KC_V)
#define W_LOCK G(KC_L)
#define W_DSKTPSHOW G(KC_D)
#define CHANGEDISPLAY G(KC_P)

// toggles
#define SET_NAV TG(_NAV)
#define SET_FUN TG(_FUNC)
#define SET_NUM TG(_NUMBER)
#define T_MODTAP TG(_MODTAP)

// software defined macros.
#define C_MACRO KC_F19

// eye tracker key: on press it will move the mouse to where I'm looking. on release it will do a mouse button 1 click.
#define KX_MEYE X_F14

// tap dances
#define TD_ALTAB TD(TDK_AT)
#define TD_ATB TD(TDK_ATB)
#define TD_ALFU TD(TDK_ALTFUN)
#define TD_1SHOT TD(TDK_1SHOT)
#define TD_CLICK TD(TDK_CLICK)
#define TD_COMM TD(TDK_COMM)
#define TD_DOT TD(TDK_DOT)
#define TD_SLSH TD(TDK_SLSH)
#define SETMAIN TD(TDK_SETMAIN)

// macros
#define SS_ALTTAB SS_DOWN(X_LALT) SS_DELAY(10) SS_TAP(X_TAB) SS_DELAY(10) SS_UP(X_LALT)
#define SS_COPY SS_LCTL(SS_TAP(X_C))
#define SS_PASTE SS_LCTL(SS_TAP(X_V))
#define SS_CUT SS_LCTL(SS_TAP(X_X))
#define SS_GOAPP(kc) SS_LGUI(SS_LCTL(SS_TAP(kc)))
#define SS_BACK SS_DELAY(20)  SS_TAP(X_LEFT)

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

td_state_t cur_dance(qk_tap_dance_state_t *state) {
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

static td_state_t td_state;

td_state_t cur_dance(qk_tap_dance_state_t *state);

static td_state_t td_state_alttab;
void td_alttab_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state_alttab = cur_dance(state);
    switch (td_state_alttab) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_ALTTAB);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_MNAV);
            SEND_STRING(SS_DOWN(KX_MEYE));
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(10) SS_TAP(X_TAB) SS_DELAY(50) SS_TAP(X_TAB) SS_DELAY(10) SS_UP(X_LALT));
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_DELAY(20) SS_TAP(X_TAB) SS_DELAY(30) SS_TAP(X_TAB) SS_DELAY(30) SS_UP(X_LALT) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

void alttab_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_alttab) {
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_TAP(X_ENTER));
            break;
        case TD_SINGLE_HOLD:
            layer_off(_MNAV);
            SEND_STRING(SS_UP(KX_MEYE));
            break;
        default:
            break;
    }
}

static td_state_t td_state_atb;
void td_atb_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void td_atb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_atb) {
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}


static td_state_t td_state_altfun;
void td_altfun_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void td_altfun_reset(qk_tap_dance_state_t *state, void *user_data) {
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

static td_state_t td_state_oneshot;
void td_oneshot_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t mod_state;
    td_state_oneshot = cur_dance(state);
    switch (td_state_oneshot) {
        case TD_SINGLE_TAP:
            mod_state = get_mods();
            if (mod_state == 0) {
                mod_state = MOD_BIT(KC_LCTL);
            }

            set_oneshot_layer(_HIGHQWERTY, ONESHOT_START);
            add_oneshot_mods(mod_state);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_F)));
            break;
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        default:
            break;
    }
}

void td_oneshot_reset(qk_tap_dance_state_t *state, void *user_data) {
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
            layer_off(_RAISE);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        default:
            break;
    }
}

static td_state_t td_state_click;
void td_click_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state_click = cur_dance(state);
    switch (td_state_click) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_TAP(X_BTN1));
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_BTN2) SS_DELAY(300) SS_TAP(X_P)); // open link in a new private window
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_TAP(X_BTN2));
            set_oneshot_layer(_HIGHQWERTY, ONESHOT_START);
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(5) SS_TAP(X_BTN1) SS_DELAY(5) SS_LCTL(SS_TAP(X_C))); // select hovered text and copy it
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING(SS_DOWN(X_BTN1)); // hold mouse button 1 until it is pressed again
            break;
        default:
            break;
    }
}

void td_click_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_click) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
}

void td_setmain_finished(qk_tap_dance_state_t *state, void *user_data) {
    clear_keyboard();
    layer_clear();
}

void td_slash_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING(";");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING("=");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(":");
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING("==");
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
}

void td_comm_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING(",");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING("?");
            break;
        default:
            break;
    }
}

void td_dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING(".");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING("!");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("..");
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(". ");
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("...");
        default:
            break;
    }
}

static td_state_t td_state_thmbr1n;
void td_thmbr1n_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state_thmbr1n = cur_dance(state);
    switch (td_state_thmbr1n) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_ENTER)));
            break;
        default:
            break;
    }
}

void td_thmbr1n_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_thmbr1n) {
        case TD_SINGLE_HOLD:
            layer_off(_RAISE);
            break;
        default:
            break;
    }
}

static td_state_t td_state_thmbl1n;
void td_thmbl1n_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state_thmbl1n = cur_dance(state);
    switch (td_state_thmbl1n) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_TAP(X_BSPC)));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        default:
            break;
    }
}

void td_thmbl1n_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_thmbl1n) {
        case TD_SINGLE_HOLD:
            layer_off(_RAISE);
            break;
        default:
            break;
    }
}

static td_state_t td_state_thmbl2n;
void td_thmbl2n_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state_thmbl2n = cur_dance(state);
    switch (td_state_thmbl2n) {
        case TD_SINGLE_TAP:
            layer_off(_NAV);
            break;
        case TD_SINGLE_HOLD:
            add_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void td_thmbl2n_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state_thmbl2n) {
        case TD_SINGLE_HOLD:
            del_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

// Tap Dance declarations
enum tap_dance{
    TDK_AT,
    TDK_ATB,
    TDK_ALTFUN,
    TDK_1SHOT,
    TDK_SETMAIN,
    TDK_CLICK,
    TDK_COMM,
    TDK_DOT,
    TDK_SLSH,
    TDK_THMBL1N,
    TDK_THMBL2N,
    TDK_THMBR1N,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TDK_SETMAIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_setmain_finished, NULL),
    [TDK_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_click_finished, td_click_reset),
    [TDK_1SHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_oneshot_finished, td_oneshot_reset),
    [TDK_AT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alttab_finished, alttab_reset),
    [TDK_ATB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_atb_finished, td_atb_reset),
    [TDK_ALTFUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_altfun_finished, td_altfun_reset),
    [TDK_THMBL1N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_thmbl1n_finished, td_thmbl1n_reset),
    [TDK_THMBL2N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_thmbl2n_finished, td_thmbl2n_reset),
    [TDK_THMBR1N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_thmbr1n_finished, td_thmbr1n_reset),
    [TDK_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_slash_finished, NULL),
    [TDK_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_comm_finished, NULL),
    [TDK_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_finished, NULL)
};

// tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_ALTAB:
            return 300;
        case TD(TDK_THMBR1N):
            return 220;
        case TD_COMM:
            return 180;
        case TD_1SHOT:
            return 170;
        default:
            return TAPPING_TERM;
    }
}

// process macros
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool oneshotShifted = (get_oneshot_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT);
    bool regularShifted = (get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT);
    bool shifted = oneshotShifted || regularShifted;
    bool pressed = record->event.pressed;

    uint16_t macroKey = 0;

    switch (keycode) {
            case M_N1:
                if (shifted) keycode = C_MACRO5;
                else macroKey = KC_1;
                break;
            case M_N2:
                if (shifted) keycode = C_MACRO4;
                else macroKey = KC_2;
                break;
            case M_N3:
                if (shifted) keycode = C_MACRO3;
                else macroKey = KC_3;
                break;
            case M_N4:
                if (shifted) keycode = C_MACRO2;
                else macroKey = KC_4;
                break;
            case M_N5:
                if (shifted) keycode = C_MACRO1;
                else macroKey = KC_5;
                break;
            case M_N6:
                if (shifted) keycode = C_MACRO1;
                else macroKey = KC_6;
                break;
            case M_N7:
                if (shifted) keycode = C_MACRO2;
                else macroKey = KC_7;
                break;
            case M_N8:
            if (shifted) keycode = C_MACRO3;
                else macroKey = KC_8;
                break;
            case M_N9:
            if (shifted) keycode = C_MACRO4;
                else macroKey = KC_9;
                break;
            case M_N0:
            if (shifted) keycode = C_MACRO5;
                else macroKey = KC_0;
                break;
    }

    if (macroKey != 0)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_oneshot_mods(MOD_BIT(KC_LSFT));
        del_weak_mods(MOD_BIT(KC_LSFT));

        if (pressed){
            register_code(macroKey);
        }else{
            unregister_code(macroKey);
        }

        return false;
    }

    // on press macros
    if (pressed) {
        switch (keycode) {
            case WINTAP:
                SEND_STRING(SS_TAP(X_LGUI));
                break;
            case M_BB1:
                if (shifted){
                    SEND_STRING(")");
                }else{
                    SEND_STRING("()" SS_BACK);
                }
                break;
            case M_BB2:
                if (shifted) {
                    SEND_STRING("}");
                }else{
                    SEND_STRING("{}" SS_BACK);
                }
                break;
            case M_BB3:
                if (shifted) {
                    del_mods(MOD_BIT(KC_LSFT));
                    SEND_STRING("]");
                    if (regularShifted) add_mods(MOD_BIT(KC_LSFT));
                }else{
                    SEND_STRING("[]" SS_BACK);
                }
                break;
            case M_BB4:
                if (shifted) {
                    SEND_STRING(">");
                }else{
                    SEND_STRING("<>" SS_BACK);
                }
                break;
            case M_QUO1:
                if (shifted) {
                    SEND_STRING("\" ");
                }else{
                    SEND_STRING("\"\"" SS_BACK);
                }
                break;
            case M_QUO2:
                if (shifted) {
                    del_mods(MOD_BIT(KC_LSFT));
                    SEND_STRING("' ");
                    if (regularShifted) add_mods(MOD_BIT(KC_LSFT));
                }else{
                    SEND_STRING("''" SS_BACK);
                }
                break;
            case M_QUO3:
                if (shifted) {
                    del_mods(MOD_BIT(KC_LSFT));
                    SEND_STRING("` ");
                    if (regularShifted) add_mods(MOD_BIT(KC_LSFT));
                }else{
                    SEND_STRING("``" SS_BACK);
                }
                break;
            case C_MACRO1:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_1) SS_UP(X_F17));
                break;
            case C_MACRO2:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_2) SS_UP(X_F17));
                break;
            case C_MACRO3:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_3) SS_UP(X_F17));
                break;
            case C_MACRO4:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_4) SS_UP(X_F17));
                break;
            case C_MACRO5:
                SEND_STRING(SS_DOWN(X_F17) SS_TAP(X_5) SS_UP(X_F17));
                break;
            case ALT_TAB:
                SEND_STRING(SS_ALTTAB);
                break;
            case ALT_TABB:
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_TAB) SS_DELAY(50) SS_TAP(X_TAB) SS_UP(X_LALT));
                break;
            case SLOWTAB:
                SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_TAB))));
                break;
            case BROWSE:
                // SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50));
                SEND_STRING(SS_LCTL(SS_TAP(X_T)) SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_TAP(X_ENTER));
                break;
            case BROWSEP:
                // SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_GOAPP(X_1) SS_DELAY(50));
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_P))) SS_DELAY(1000));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_LCTL(SS_TAP(X_A)));
                // SEND_STRING(SS_TAP(X_ENTER));
                break;
            case BROWSEN:
                SEND_STRING(SS_LCTL(SS_TAP(X_T)) SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(10));
                SEND_STRING(SS_TAP(X_ENTER));
                break;
            case DT_CPYTO:
                SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(20));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                break;
            case DT_MOVE:
                SEND_STRING(SS_CUT SS_DELAY(10));
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(20));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                break;
            case DT_CPYFR:
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_ALTTAB SS_DELAY(100));
                SEND_STRING(SS_PASTE SS_DELAY(20));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                break;
            case SAVENOTE:
                SEND_STRING(SS_COPY SS_DELAY(10));
                SEND_STRING(SS_GOAPP(X_2) SS_DELAY(30));
                SEND_STRING(SS_LALT(SS_TAP(X_1) SS_DELAY(10)));
                SEND_STRING(SS_LCTL(SS_TAP(X_HOME) SS_DELAY(5) SS_TAP(X_V) SS_DELAY(10)));
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(10));
                SEND_STRING(SS_ALTTAB);
                break;
            case AUTOFIX:
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_DELAY(5) SS_TAP(X_APP) SS_DELAY(200) SS_TAP(X_DOWN) SS_TAP(X_ENTER));
                break;
            case UP10:
                SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
                break;
            case DOWN10:
                SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN));
                break;
            case LEFT10:
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                break;
            case RIGHT10:
                SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
                break;
            case M_MSEL:
                SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(5) SS_TAP(X_BTN1) SS_DELAY(5) SS_LCTL(SS_TAP(X_C)));
                break;
            case M_CIRC:
                SEND_STRING("^ "); // ^
                break;
            case M_TILD:
                SEND_STRING("~ "); // ~
                break;
            case L_QUOM:
                SEND_STRING("' m"); // 'm
                break;
            case L_QUOT:
                SEND_STRING("' t"); // 't
                break;
            case L_QUOS:
                SEND_STRING("' s"); // 's
                break;
            case L_QUOV:
                SEND_STRING("' v"); // 'v
                break;
            case L_CEDI:
                SEND_STRING(SS_RALT(SS_TAP(X_COMM))); // ç
                break;
            case L_ACIR:
                SEND_STRING("^a"); // â
                break;
            case L_ATIL:
                SEND_STRING("~a"); // ã
                break;
            case L_AGRA:
                SEND_STRING("`a"); // à
                break;
            case L_AACU:
                SEND_STRING("'a"); // á
                break;
            case L_OTIL:
                SEND_STRING("~o"); // õ
                break;
            case L_OCIR:
                SEND_STRING("^o"); // ô
                break;
            case L_OACU:
                SEND_STRING("'o"); // ó
                break;
            case L_ECIR:
                SEND_STRING("^e"); // ê
                break;
            case L_EACU:
                SEND_STRING("'e"); // é
                break;
            case L_IACU:
                SEND_STRING("'i"); // í
                break;
            case L_UACU:
                SEND_STRING("'u"); // ú
                break;
            case M_GOMA:
                SEND_STRING(SS_TAP(X_ENTER));
                layer_off(_NUMBER);
                break;
            case M_TSTRUN:
                SEND_STRING(SS_LALT(SS_TAP(X_8)) SS_LCTL(SS_TAP(X_T)) SS_LCTL(SS_TAP(X_R)));
                break;
            case M_TSTDEB:
                SEND_STRING(SS_LALT(SS_TAP(X_8)) SS_LCTL(SS_TAP(X_T)) SS_LCTL(SS_TAP(X_D)));
                break;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // accessibility map
    //     10 , 4  , 4  , 3  , 3  , 5  ,
    //     7  , 4  , 2  , 1  , 1  , 2  ,
    //     3  , 2  , 1  , 0  , 0  , 1  ,
    //     6  , 3  , 2  , 1  , 1  , 2  ,

    [_QWERTY] = LAYOUT_5x6(
     ADJ(KC_ESC), M_N1  , M_N2  , M_N3  , M_N4  , M_N5  ,                        M_N6  , M_N7  , M_N8  , M_N9   , M_N0   ,SETMAIN,
        KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y  , KC_U  , KC_I  , KC_O   , KC_P   ,SET_NAV,
        OS_SYM  , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                        KC_H  , KC_J  , KC_K  , KC_L   , OS_LANG,OS_SYM ,
        SETMAIN , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                        KC_N  , KC_M  ,TD_COMM, TD_DOT , TD_SLSH,SETMAIN,
                          KC_WH_U,KC_WH_D,                                                      KC_WH_D, KC_WH_U,
                              LT(_NAV, KC_BSPC),OSM_SHFT,                        LT(_NAV, KC_ENTER), LT(_NAV, KC_SPACE),
                                        KC_BTN2,TD_ALTAB,                        TD_ALTAB, KC_BTN2,
                                        KC_BTN3,KC_BTN1 ,                        KC_BTN1 , KC_BTN3
    ),

    [_NAV] = LAYOUT_5x6(
        _______,C_MACRO5,C_MACRO4,C_MACRO3,C_MACRO2,C_MACRO1,                      C_MACRO1,C_MACRO2,C_MACRO3,C_MACRO4,C_MACRO5,_______,
        _______,SELCT   ,FINDANY ,WIN_PGUP,BACK    ,FORWARD ,                      DELWORD ,KC_HOME ,KC_UP   ,KC_END  ,GOTO    ,SET_FUN,
        KC_ESC ,TD_ALFU ,SFT_NEXT,CT_PGDN ,TD_1SHOT,OS_NUM  ,                      KC_BSPC, KC_LEFT ,KC_DOWN ,KC_RIGHT,OS_FUNC ,SET_NUM,
        _______,UNDO    ,CUT     ,COPY    ,PASTE   ,COMMENT ,                      KC_DEL  ,TD_ATB  ,TABPREV ,TABNEXT ,KC_APP  ,_______,
                         _______ ,_______ ,                                                          _______ ,_______ ,
                                    TD(TDK_THMBL1N),_______,                       LT(_RAISE, KC_ENTER), TD(TDK_THMBR1N),
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______
    ),

    [_FUNC] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______ ,                      _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______,CLOSEAPP,BROWSE  ,BROWSEP ,XXXXXXX ,PRINTSCR,                      KC_CAPS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,_______ ,
        KC_ESC ,OSM_ALT ,OSM_SHFT,OSM_CTRL,AUTOFIX ,WINTAP  ,                      WINTAP  ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,_______ ,
        _______,SAVENOTE,DT_MOVE ,DT_CPYTO,DT_CPYFR,XXXXXXX ,                      KC_INS  ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,
                         _______ ,_______ ,                                                          _______ ,_______ ,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______
    ),

    [_SYMBOLS] = LAYOUT_5x6(
          _______,_______ ,_______ ,_______ ,_______ ,_______ ,                    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
          _______,KC_QUES ,KC_DLR  ,KC_LABK ,KC_RABK ,KC_HASH ,                    KC_AMPR ,M_QUO3  ,M_BB3   ,KC_PERC ,XXXXXXX ,_______ ,
          KC_ESC ,KC_EXLM ,KC_MINS ,KC_PLUS ,KC_EQL  ,KC_UNDS ,                    KC_PIPE ,M_QUO1  ,M_BB1   ,KC_AT   ,XXXXXXX ,KC_SCLN ,
          _______,XXXXXXX ,KC_ASTR ,KC_SLSH ,KC_BSLS ,KC_COLON,                    M_TILD  ,M_QUO2  ,M_BB2   ,M_CIRC  ,XXXXXXX ,_______ ,
                                    _______ ,_______ ,                                               _______ ,_______ ,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______
    ),

    [_MNAV] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______,
        _______,CLOSEAPP,KC_BTN2 ,KC_MS_U ,TD_CLICK,M_MSEL ,                       M_MSEL  ,TD_CLICK,KC_MS_U ,KC_BTN2 ,CLOSEAPP,_______,
        KC_ESC ,CLOSETAB,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_BTN3,                       KC_BTN3 ,KC_MS_L ,KC_MS_D ,KC_MS_R ,CLOSETAB,_______,
        _______,GO_APP5 ,GO_APP4 ,GO_APP3 ,GO_APP2 ,GO_APP1,                       GO_APP1 ,GO_APP2 ,GO_APP3 ,GO_APP4 ,GO_APP5 ,_______,
                                _______ ,_______ ,                                                   _______ ,_______ ,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______
    ),

    [_NUMBER] = LAYOUT_5x6(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                      _______ ,_______ ,_______ ,_______ ,_______  ,_______,
        _______ ,KC_QUES ,KC_DLR  ,KC_LABK ,KC_RABK ,KC_HASH ,                     DELWORD ,KC_7    ,KC_8    ,KC_9     ,XXXXXXX ,_______ ,
    _______,TA(KC_EXLM),TS(KC_MINS),TC(KC_PLUS),KC_EQL,KC_UNDS,                    KC_BSPC ,KC_4    ,KC_5    ,KC_6     ,KC_COMM ,_______ ,
        _______ ,XXXXXXX ,KC_ASTR ,KC_SLSH ,KC_BSLS ,KC_COLON,                     KC_0    ,KC_1    ,KC_2    ,KC_3     ,KC_DOT  ,_______ ,
                                   _______ ,_______ ,                                                _______ ,_______ ,
                                            _______ ,_______ ,                     _______ ,_______ ,
                                            _______ ,_______ ,                     _______ ,_______ ,
                                            _______ ,_______ ,                     _______ ,_______
    ),

    [_WIN] = LAYOUT_5x6(
        _______,_______ ,_______ ,_______ ,_______ ,_______,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______,
        _______,MDPRV   ,MDNXT   ,_______ ,MDVOLU  ,MDMUTE ,                       XXXXXXX ,W_SLEFT ,W_MAX   ,W_SRIGHT,XXXXXXX ,_______,
        _______,MDSWI   ,MDPLY   ,XXXXXXX ,MDVOLD  ,W_LOCK ,                       XXXXXXX ,W_LEFT  ,W_MIN   ,W_RIGHT ,XXXXXXX ,_______,
        _______,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______,
                                  _______ ,_______ ,                                                 _______ ,_______ ,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______,
                                            _______,_______,                       _______,_______
    ),

    [_LANG] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
        _______,L_ATIL ,L_ACIR ,L_EACU ,_______,L_QUOT ,                       _______,L_UACU ,L_IACU ,L_OACU ,L_OCIR ,_______,
        _______,L_AACU ,L_QUOS ,L_ECIR ,_______,_______,                       _______,_______,_______,L_OTIL ,C_MACRO,_______,
        _______,L_AGRA ,_______,L_CEDI ,L_QUOV ,_______,                       _______,L_QUOM  ,_______,_______,_______,_______,
                                  _______,_______,                                               _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),

    [_MODTAP] = LAYOUT_5x6(
          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
          _______,TA(KC_A),TS(KC_S),TC(KC_D) ,_______ ,_______ ,                       _______ ,_______,TC(KC_K),TS(KC_L) ,_______ ,_______ ,
          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                  _______ ,_______ ,                                               _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______
    ),

    [_RAISE] = LAYOUT_5x6(
          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                       W_SLEFT ,_______ ,UP10    ,_______ ,_______ ,_______ ,
          _______, OSM_ALT ,OSM_SHFT,OSM_CTRL,OS_QWER ,_______ ,                       W_LEFT  ,LEFT10  ,DOWN10  ,RIGHT10 ,_______ ,_______ ,
          _______ ,_______ ,_______ ,M_TSTDEB,M_TSTRUN,I_BUILD ,                       _______ ,I_HIDTA ,I_GOSCM ,I_GTEST ,_______ ,_______ ,
                                  _______ ,_______ ,                                               _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______ ,
                                                  _______ ,_______ ,            _______ ,_______
    ),

    [_GAME] = LAYOUT_5x6(
        _______ , KC_1    , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0   ,SETMAIN,
        KC_ESC  , KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  ,                         KC_T  , KC_Y  , KC_U  , KC_I  , KC_O   ,KC_P    ,
        _______ , KC_LCTL , KC_A  , KC_S  , KC_D  , KC_F  ,                         KC_G  , KC_H  , KC_J  , KC_K  , KC_L   ,KC_QUOT ,
        _______ , KC_LSFT , KC_Z  , KC_X  , KC_C  , KC_V  ,                         KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT ,_______ ,
                            _______,KC_LALT,                                                        _______,_______,
                                         KC_SPACE, _______ ,                         _______ , _______ ,
                                         _______ , _______ ,                         _______ , _______ ,
                                         _______ , _______ ,                         _______ , _______
    ),

    [_HIGHQWERTY] = LAYOUT_5x6(
        _______ , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9   , KC_0   ,_______ ,
        KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y  , KC_U  , KC_I  , KC_O   , KC_P   ,_______ ,
        KC_ESC ,  KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                        KC_H  , KC_J  , KC_K  , KC_L   , KC_QUOT,_______ ,
        _______ , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                        KC_N  , KC_M  ,KC_COMM, KC_DOT , KC_SLSH,_______ ,
                        _______, _______,                                                      _______, _______,
                                         KC_BSPC , _______ ,                         KC_ENT  ,KC_SPACE,
                                         _______ , _______ ,                         _______ ,_______ ,
                                         _______ , _______ ,                         _______ ,_______
    ),

    [_ADJUST] = LAYOUT_5x6(
          _______,TO(_QWERTY),T_MODTAP,_______,_______,TO(_GAME),                 _______,_______,_______,_______,_______,KC_PWR ,
          _______,_______,RESET  ,_______,_______,_______,                       _______,_______,_______,RESET  ,_______,_______,
          _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
                                  _______,_______,                                               _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
};

// keep working on this
// const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
//   {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
//   {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
//   {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
//   {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
//   {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
// };


// ============ combos

// const uint16_t PROGMEM combo_cs[] = {CT_PGDN, OS_CTRL, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(combo_cs, OS_CTSF),
// };
