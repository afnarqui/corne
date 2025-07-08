#include QMK_KEYBOARD_H
#include "logo.h"
#include "quantum.h"
#include <stdio.h>


#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif


enum custom_keycodes {
    M_C_SMART_C = SAFE_RANGE,
    M_C_SMART_V,
    M_C_SMART_X,
    M_C_SMART_Z,
    M_C_SMART_D,
    M_C_SMART_E,
    M_C_SMART_A,
    M_C_SMART_S,
    M_UNDERSCORE,
    M_N_TILDE,
    M_ALT_164, // <--- Agregado para Alt+164
    ALT_TAB,
    R_CTRL_SHIFT,
    RESET_TIME,
};

// 🎹 Mis capas afn personalizadas
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_Q, KC_W, KC_F, KC_P, KC_B, KC_M,          KC_Y, KC_L, KC_H, KC_ESC, KC_CAPS, KC_BSPC,
        R_CTRL_SHIFT, M_C_SMART_S, KC_T, LT(5, KC_N),  M_C_SMART_C, M_C_SMART_D,          M_C_SMART_A, M_C_SMART_E, KC_I, KC_O, KC_U, KC_LALT,
        M_C_SMART_Z, M_C_SMART_X, KC_G, M_C_SMART_V, LCTL_T(KC_J), LSFT_T(KC_K), RSFT(KC_NO), LCTL_T(KC_WSCH), KC_TAB, KC_RALT, KC_RGUI, KC_APP,
                                           MO(2), MO(1),LT(4, KC_SPC),   LT(5, KC_ENT) , MO(1), MO(2)
    ),
    [1] = LAYOUT_split_3x6_3(
        ALT_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,          KC_LALT, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_BSPC,
        LALT(KC_TAB), KC_6, KC_7, KC_8, KC_9, KC_0,    KC_END, KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_LSFT), KC_RCTL,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,KC_F6,            KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,KC_F12,
                                            KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TAB, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,    KC_NO, KC_NO, S(KC_UP), KC_INS,KC_DEL,  KC_BSPC,
        KC_PSCR,KC_GRV, KC_BSLS, M_UNDERSCORE, KC_AT, KC_QUOT,           KC_NO, S(KC_LEFT), S(KC_DOWN), S(KC_RGHT),KC_SLSH, KC_RCTL,
        KC_CIRC,KC_PIPE, KC_SCLN,KC_COMM , KC_DOT,KC_MINS,          KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
                                               KC_TRNS, MO(3), KC_SPC, KC_ENT, KC_TRNS, KC_RALT
    ),
    [3] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT
    ),
    [4] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,    KC_WH_L,    KC_MS_U,    KC_WH_R,    KC_NO,    KC_ACL0,
        KC_NO,    KC_NO,    KC_NO, M_ALT_164, KC_NO, KC_NO,      KC_NO,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,  KC_ACL1,
        KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO,     KC_LCTL, KC_WH_U,    KC_BTN3,    KC_WH_D,       KC_NO,    KC_ACL2,
                            KC_NO, KC_BTN1, KC_NO, KC_BTN1, KC_BTN2, KC_NO
    ),
[5] = LAYOUT_split_3x6_3(
    KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,     KC_LT, KC_GT, KC_PIPE,KC_NO,KC_NO,KC_NO,
    KC_SLSH, KC_COLN, KC_EXLM, KC_DQUO, KC_COMM, KC_DOT,       LCTL(KC_TAB), LCTL(LSFT(KC_TAB)), LALT(KC_UP), LALT(KC_DOWN), LCTL(KC_P), KC_RCTL,
    KC_NO, KC_QUES, KC_HASH, KC_DLR, KC_PERC,KC_NO,      KC_AMPR, KC_ASTR, KC_EQL, KC_MINS, KC_GRV, RESET_TIME,
                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

static uint16_t c_timer;


// Variables globales para ALT+TAB
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Variables globales para detectar si se mantuvo presionada la tecla personalizada
bool r_ctrl_shift_pressed = false;
uint16_t r_ctrl_shift_timer = 0;

// Variables para el cambio de color por capa
uint8_t current_layer = 0;
uint8_t previous_layer = 0; // Nueva variable para rastrear la capa anterior
uint32_t last_time_update = 0; // Variable para controlar actualización de hora
uint32_t time_offset = 0; // Variable para controlar el tiempo base

// Colores para cada capa (HSV: HUE, SAT, VAL)
const HSV layer_colors[] = {
    {HSV_BLUE},      // Capa 0: Azul
    {HSV_RED},     // Capa 1: Rojo
    {HSV_GREEN},    // Capa 2: Verde
    {HSV_PURPLE},   // Capa 3: Púrpura
    {HSV_ORANGE},   // Capa 4: Naranja
    {HSV_CYAN},     // Capa 5: Cian
};

// Declaración de función para obtener nombre de capa
const char *get_layer_name(uint8_t layer);

// Función para obtener la hora real del sistema
void get_time_string(char* time_str) {
    // Obtener hora real del sistema usando comunicación con el host
    // Esta es una implementación básica que puede no funcionar en todos los casos

    // Intentar obtener la hora del sistema
    uint32_t system_time = timer_read32();

    // Para obtener la hora real, necesitaríamos implementar comunicación con el host
    // Por ahora, mostramos el tiempo transcurrido desde el inicio
    uint32_t uptime = (system_time - time_offset) / 1000; // Segundos desde el reinicio

    uint8_t hours = (uptime / 3600) % 24;
    uint8_t minutes = (uptime / 60) % 60;
    uint8_t seconds = uptime % 60;

    snprintf(time_str, 9, "%02d:%02d:%02d", hours, minutes, seconds);
}

// Función para cambiar el color según la capa activa
void change_layer_color(uint8_t layer) {
    if (layer < sizeof(layer_colors) / sizeof(layer_colors[0])) {
#ifdef RGB_MATRIX_ENABLE
        rgb_matrix_sethsv(layer_colors[layer].h, layer_colors[layer].s, layer_colors[layer].v);
#endif
#ifdef RGBLIGHT_ENABLE
        rgblight_sethsv(layer_colors[layer].h, layer_colors[layer].s, layer_colors[layer].v);
#endif
    }
}


void matrix_scan_user(void) {
 // Detectar cambios de capa y cambiar color
    uint8_t active_layer = get_highest_layer(layer_state);
    if (active_layer != current_layer) {
        current_layer = active_layer;
        change_layer_color(current_layer);
    }

    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    if (r_ctrl_shift_pressed && timer_elapsed(r_ctrl_shift_timer) >= TAPPING_TERM) {
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      r_ctrl_shift_pressed = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_UNDERSCORE:
            tap_code16(LSFT(KC_MINS));
            return false;

        case M_N_TILDE:
            send_string_with_delay_P(PSTR("ñ"), 0);
            return false;
        case M_ALT_164:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_1);
                tap_code(KC_KP_6);
                tap_code(KC_KP_4);
                unregister_code(KC_LALT);
            }
            return false;

        case M_C_SMART_C:
        case M_C_SMART_V:
        case M_C_SMART_X:
        case M_C_SMART_Z:
        case M_C_SMART_D:
        case M_C_SMART_E:
        case M_C_SMART_A:
        case M_C_SMART_S: {
            if (record->event.pressed) {
                c_timer = timer_read(); // comenzamos a contar
            } else {
                uint16_t elapsed = timer_elapsed(c_timer);
                uint16_t key;

                // Determinar qué letra usar
                switch (keycode) {
                    case M_C_SMART_C: key = KC_C; break;
                    case M_C_SMART_V: key = KC_V; break;
                    case M_C_SMART_X: key = KC_X; break;
                    case M_C_SMART_Z: key = KC_Z; break;
                    case M_C_SMART_D: key = KC_D; break;
                    case M_C_SMART_E: key = KC_E; break;
                    case M_C_SMART_A: key = KC_A; break;
                    case M_C_SMART_S: key = KC_S; break;
                    default: return true;
                }

                if (elapsed > 150) {
                    // Manda Ctrl + tecla si fue sostenida
                    register_code(KC_LCTL);
                    tap_code(key);
                    unregister_code(KC_LCTL);
                } else {
                    // Si solo fue un toque rápido, manda la letra normal
                    tap_code(key);
                }
            }
            return false;
        }

        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);  // Mantiene Alt presionado
                }
                alt_tab_timer = timer_read();  // Reinicia el temporizador
                tap_code(KC_TAB);             // Toca Tab
            }
            return false; // Evita que QMK procese ALT_TAB como keycode normal

              case R_CTRL_SHIFT:
            if (record->event.pressed) {
                r_ctrl_shift_pressed = true;
                r_ctrl_shift_timer = timer_read();
            } else {
                if (timer_elapsed(r_ctrl_shift_timer) < TAPPING_TERM) {
                    tap_code(KC_R); // Tap rápido = letra R
                } else {
                    unregister_code(KC_LSFT); // Hold = suelta Shift
                    unregister_code(KC_LCTL); // Hold = suelta Ctrl
                }
                r_ctrl_shift_pressed = false;
            }
            return false;

        case RESET_TIME:
            if (record->event.pressed) {
                time_offset = timer_read32(); // Reiniciar el tiempo
            }
            return false;
    }
    return true;
}



// 🖼️ OLED
bool oled_task_user(void) {
    uint8_t active_layer = get_highest_layer(layer_state);
    uint32_t current_time = timer_read32();

    // Actualizar si la capa cambió o cada segundo para la hora
    if (active_layer != previous_layer || (current_time - last_time_update) > 1000) {
        oled_clear(); // Limpiar pantalla
        oled_render_logo();  // Muestra el logo con la nueva capa
        previous_layer = active_layer;
        last_time_update = current_time;
    }

    return false;
}

// Función para inicializar la pantalla OLED
void keyboard_post_init_user(void) {
    // Inicializar la pantalla OLED con rotación normal (funciona en ambos lados)
    oled_init(OLED_ROTATION_0);
    oled_clear();
    oled_render_logo();
}

void oled_render_logo(void) {
    oled_write_raw_P(logo, logo_size);

    // Línea 1: Capa
    oled_set_cursor(10, 1);
    uint8_t layer = get_highest_layer(layer_state);
    oled_write_P(PSTR("C: "), false);
    oled_write(get_layer_name(layer), false);

    // Línea 2: Tiempo transcurrido
    oled_set_cursor(10, 2);
    char time_str[9];
    get_time_string(time_str);
    oled_write_P(PSTR("T: "), false);
    oled_write(time_str, false);
}

const char *get_layer_name(uint8_t layer) {
    switch (layer) {
        case 0: return "Base";
        case 1: return "Num";
        case 2: return "Simbolos";
        case 3: return "RGB";
        case 4: return "Mouse";
        case 5: return "Extra";
        default: return "Desconocida";
    }
}



