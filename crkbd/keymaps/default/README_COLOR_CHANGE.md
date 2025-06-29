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
    {HSV_RED},      // Capa 0
    {HSV_BLUE},     // Capa 1
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

- **Capa 0**: Escritura normal (Rojo)
- **Capa 1**: Números y funciones (Azul)
- **Capa 2**: Símbolos y navegación (Verde)
- **Capa 3**: Configuración RGB (Púrpura)
- **Capa 4**: Control del mouse (Naranja)
- **Capa 5**: Símbolos especiales (Cian)

## 🔍 Solución de Problemas

### El color no cambia
1. Verifica que RGB Matrix o RGB Light esté habilitado
2. Asegúrate de que el teclado tenga LEDs RGB
3. Revisa que la función `matrix_scan_user` esté siendo llamada

### Colores muy brillantes/tenues
- Ajusta el valor `VAL` en los colores HSV
- Modifica `RGB_MATRIX_MAXIMUM_BRIGHTNESS` en `config.h`

### Efectos no funcionan
- Verifica que los efectos estén habilitados en `config.h`
- Asegúrate de que el teclado soporte RGB Matrix

## 📝 Notas

- El sistema funciona automáticamente sin necesidad de configuración adicional
- Los colores se aplican instantáneamente al cambiar de capa
- Compatible con todos los efectos RGB disponibles
- No interfiere con otras funcionalidades del teclado 