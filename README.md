 
# ⌨️ Configuración personalizada del teclado Corne (QMK)

![Visual de la configuración del teclado](https://s3.us-east-1.amazonaws.com/afnarqui.com/archivosnotions/corne.jpeg)

## 📝 Descripción general

Esta configuración está diseñada para un teclado dividido tipo Corne, optimizada para programación, navegación y productividad. Utiliza múltiples capas con combinaciones inteligentes de teclas, permitiendo funciones avanzadas sin perder velocidad al escribir.

### 🔧 Tecnologías usadas

- [QMK Firmware](https://qmk.fm)
- C macros para teclas personalizadas
- Mapeo visual en capas (layers)
- Teclas "inteligentes" que reaccionan diferente si se presionan o mantienen

---


## 🧩 Leyenda de símbolos

| Símbolo | Significado     |
|---------|------------------|
| ⌃       | Ctrl             |
| ⇧       | Shift            |
| ⌥       | Alt              |
| ⌘       | GUI (Windows/Command) |
| ⌫       | Backspace        |
| ⏎       | Enter            |
| MENU    | KC_APP (Menú contextual) |
| WSCH    | KC_WSCH (Buscar) |
| MO(x)   | Cambiar temporalmente a capa x |
| LT(x, Y)| Mantener = capa x, tocar = tecla Y |

---

## 🎹 Capa 0 – Escritura principal (teclas inteligentes)
```
 Q    W    F    P    B    M        Y    L    H    ESC  CAPS  ⌫
⌃⇧R  ⌃S    T   ⌃N   ⌃C   ⌃D       ⌃A   ⌃E    I     O     U    ⌥
 Z   ⌃X    G   ⌃V   ⌃J   ⇧K       ⇧     ⌃WSCH TAB   ⌥     ⌘   MENU

           [MO(2)] [MO(1)]     SPACE    ⏎    [MO(1)] [MO(2)]
```

## 🧭 Capa 1 – Navegación y funciones
```
ALT+TAB   1    2    3    4    5       ⌥    PgUp   ↑   PgDn   ⛔     ⌫
ALT+TAB   P6   P7   P8   P9   P0      End   ←    ↓    →    ⌃⇧    ⌃
 F1    F2   F3   F4   F5   F6         F7    F8    F9    F10   F11   F12

           ⌘     [MO(1)]     SPACE    ⏎    [MO(1)]   ⌥
```

## 🔣 Capa 2 – Símbolos y signos especiales
```
 TAB    +    -    *    /    =       ⛔    ⛔   ⇧↑    ⛔    ⛔     ⌫
PRTSC  `    \   _    @     "        ⛔   ⇧←   ⇧↓   ⇧→     /     ⌃
 ^     |    ;    ,    .    ⛔        ⛔    ⛔    ⛔    ⛔     ⛔     ⛔

          [MO(3)] [MO(2)]   SPACE    ⏎    [MO(3)]   ⌥
```

## 🌈 Capa 3 – Configuración RGB
```
 QK_BOOT ⛔   ⛔   ⛔   ⛔   ⛔       ⛔     ⛔    ⛔    ⛔    ⛔    ⛔
RGB TOG  HUE+ SAT+ VAL+ ⛔   ⛔       ⛔     ⛔    ⛔    ⛔    ⛔    ⛔
RGB NEXT HUE- SAT- VAL- ⛔   ⛔       ⛔     ⛔    ⛔    ⛔    ⛔    ⛔

           ⌘     ⌥         SPACE    ⏎    ⌥        ⌘
```

## 🖱️ Capa 4 – Mouse y ñ
```
 ⛔   ⛔   ⛔   ⛔   ⛔   ⛔        ⛔   WH_L  MS↑   WH_R  ⛔   ACL0
 ⛔   ⛔   ⛔   ñ    ⛔   ⛔        ⛔   MS←  MS↓   MS→   ⛔   ACL1
 ⛔   ⛔   ⛔   ⛔   ⛔   ⛔        ⛔   WH↑   MBtn3 WH↓   ⛔   ACL2

           ⛔   MBtn1      ⛔       MBtn1   MBtn2   ⛔
```

## 🧼 Capa 5 – Símbolos extendidos y navegación avanzada
```
 {     }     [     ]     (     )      <     >     |     ⛔     ⛔     ⛔
 /    :     !     "     ,     .      ⌃Tab ⌃⇧Tab  ⌥↑    ⌥↓    ⌃P    ⌃
 ⛔    ?     #     $     %     ⛔      &     *     =     -     `     ⛔

          ⌘     ⌥         ⌘         ⌥        ⌘       ⌥
```

---

## 🧠 Teclas inteligentes (SMART KEYS)

| Tecla           | Tap rápido | Hold (>150ms)          |
|-----------------|-------------|------------------------|
| `M_C_SMART_C`   | `c`         | `Ctrl + C` (copiar)    |
| `M_C_SMART_V`   | `v`         | `Ctrl + V` (pegar)     |
| `M_C_SMART_X`   | `x`         | `Ctrl + X` (cortar)    |
| `M_C_SMART_Z`   | `z`         | `Ctrl + Z` (deshacer)  |
| `M_C_SMART_A`   | `a`         | `Ctrl + A` (seleccionar todo) |
| `M_C_SMART_E`   | `e`         | `Ctrl + E`             |
| `M_C_SMART_S`   | `s`         | `Ctrl + S` (guardar)   |
| `M_C_SMART_D`   | `d`         | `Ctrl + D`             |

---

## 🚀 Teclas personalizadas destacadas

- `ALT_TAB`: simula Alt + Tab y mantiene presionado Alt automáticamente mientras se navega.
- `R_CTRL_SHIFT`: si se presiona rápido envía la letra `R`, si se mantiene activa `Ctrl + Shift`.

---

## 🧩 Caracteres especiales adaptados a teclado en inglés

- `M_UNDERSCORE`: envía `_` sin importar el layout.
- `M_N_TILDE`: envía la letra `ñ` directamente.

---


## 🔁 Comportamiento visual y OLED

- Muestra el logo personalizado con `oled_render_logo`.
- Apaga combinaciones cuando se detecta inactividad.

---


# 🎨 Sistema de Cambio de Color por Capa

## 📋 Descripción

Este sistema permite que el teclado cambie automáticamente de color RGB cuando cambias entre diferentes capas, proporcionando una retroalimentación visual inmediata sobre la capa activa.

## 🎯 Funcionalidad

### Colores por Capa
- **Capa 0 (Base)**: 🔴 Rojo
- **Capa 1 (Lower)**: 🔵 Azul  
- **Capa 2 (Raise)**: 🟢 Verde
- **Capa 3 (Adjust)**: 🟣 Púrpura
- **Capa 4 (Mouse)**: 🟠 Naranja
- **Capa 5 (Symbols)**: 🔵 Cian

### Cómo Funciona
1. El sistema detecta automáticamente cuando cambias de capa
2. Aplica el color correspondiente a la nueva capa activa
3. Mantiene el color hasta que cambies a otra capa

## ⚙️ Configuración

### RGB Matrix (Recomendado)
- Habilitado en `config.h` con `#define RGB_MATRIX_ENABLE`
- Mejor rendimiento y más efectos disponibles
- Compatible con teclados más nuevos

### RGB Light (Alternativo)
- Habilitado en `config.h` con `#define RGBLIGHT_ENABLE`
- Compatible con teclados más antiguos
- Menos efectos pero más simple

## 🔧 Personalización

### Cambiar Colores
Para cambiar los colores de las capas, edita el array `layer_colors` en `keymap.c`:

```c
const HSV layer_colors[] = {
    {HSV_BLUE},      // Capa 0
    {HSV_RED},     // Capa 1
    {HSV_GREEN},    // Capa 2
    {HSV_PURPLE},   // Capa 3
    {HSV_ORANGE},   // Capa 4
    {HSV_CYAN},     // Capa 5
};
```

### Colores Disponibles
- `HSV_RED`, `HSV_BLUE`, `HSV_GREEN`
- `HSV_PURPLE`, `HSV_ORANGE`, `HSV_CYAN`
- `HSV_YELLOW`, `HSV_PINK`, `HSV_WHITE`
- O usar valores personalizados: `{HUE, SAT, VAL}`

### Ejemplo de Color Personalizado
```c
{120, 255, 255}  // Verde brillante
{0, 255, 128}    // Rojo medio
{180, 255, 255}  // Cian brillante
```

## 🚀 Compilación

1. Asegúrate de que RGB Matrix o RGB Light esté habilitado en `config.h`
2. Compila el firmware: `qmk compile -kb crkbd -km default`
3. Flashea el firmware a tu teclado

## 🎮 Uso

- **Capa 0**: Escritura normal (Azul)
- **Capa 1**: Números y funciones (Rojo)
- **Capa 2**: Símbolos y navegación (Verde)
- **Capa 3**: Configuración RGB (Púrpura)
- **Capa 4**: Control del mouse (Naranja)
- **Capa 5**: Símbolos especiales (Cian)

## 🔍 Solución de Problemas

### El color no cambia
1. Verifica que RGB Matrix o RGB Light esté habilitado
2. Asegúrate de que el teclado tenga LEDs RGB
3. Revisa que la función `matrix_scan_user` esté siendo llamada

## 📝 Notas

- El sistema funciona automáticamente sin necesidad de configuración adicional
- Los colores se aplican instantáneamente al cambiar de capa
- Compatible con todos los efectos RGB disponibles
- No interfiere con otras funcionalidades del teclado


## 🧪 Compilación e instalación

Para compilar y flashear esta configuración en tu teclado Corne:

```sh
git clone https://github.com/afnarqui/corne.git
cd corne
rm -rf .build

qmk clean

qmk compile -kb crkbd/rev1 -km default

qmk flash -kb crkbd/rev1 -km default
```

> Asegúrate de tener [QMK configurado correctamente](https://docs.qmk.fm/#/newbs) antes de comenzar.

---

¿Dudas, sugerencias o mejoras? ¡Son bienvenidas!



## 📌 Consideraciones finales

Este archivo README sirve como guía para ti o cualquier persona que quiera entender y usar tu layout.