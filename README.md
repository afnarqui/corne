 
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