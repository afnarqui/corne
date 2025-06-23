 
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

## 🎹 Capas del teclado

### Capa 0 – Escritura principal

- Teclas comunes (`QWERTY` modificado)
- Teclas SMART (`Ctrl + tecla` si se mantiene)
- Accesos rápidos a funciones frecuentes (`Tab`, `Borrar`, `Espacio`, etc.)

### Capa 1 – Navegación y funciones

- Números, funciones (`F1` a `F12`)
- Movimiento de cursor (flechas, `PgUp`, `PgDn`, `End`)
- Alternador de ventanas (`Alt + Tab`)

### Capa 2 – Símbolos y signos especiales

- Paréntesis, corchetes, llaves
- Operadores (`+`, `-`, `*`, `/`, `=`)
- Combinaciones con `Shift` (flechas seleccionando texto)

### Capa 3 – Configuración del teclado

- Reset del firmware (`QK_BOOT`)
- Control de RGB (`hue`, `saturación`, `valor`)
- Atajos internos

### Capa 4 – Control de mouse y entrada de ñ

- Movimiento del mouse (`KC_MS_U`, `KC_MS_D`, etc.)
- Clicks y scroll
- Entrada directa de la letra ñ incluso en teclado inglés

### Capa 5 – Navegación avanzada y símbolos extendidos

- Accesos directos a pestañas de navegador
- Símbolos complejos como `|`, `&`, `^`, `%`, `~`, etc.

---

## 🧠 Teclas inteligentes (SMART KEYS)

Estas teclas detectan si las presionas rápido (tap) o si las mantienes (hold). Ejecutan una acción distinta según el caso:

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

````sh
git clone https://github.com/afnarqui/corne.git
cd corne
rm -rf .build

qmk clean

qmk compile -kb crkbd/rev1 -km default

qmk flash -kb crkbd/rev1 -km default
````

## 📌 Consideraciones finales

Este archivo README sirve como guía para ti o cualquier persona que quiera entender y usar tu layout. Solo reemplaza la URL de la imagen superior por el enlace de AWS S3 una vez lo subas:

```markdown
![Visual de la configuración del teclado](https://s3.us-east-1.amazonaws.com/afnarqui.com/archivosnotions/corne.jpeg)

