#!/bin/bash

# Ruta al directorio que contiene las imágenes (carpeta "Walls" en la home)
ruta_imagenes="${HOME}/walls"

# Lista de imágenes numeradas del 1 al 8
imagenes=("1.jpg" "2.jpg" "3.jpg" "4.jpg" "5.jpg" "6.jpg" "7.jpg" "8.jpg")

# Selecciona una imagen aleatoria
imagen_aleatoria="${ruta_imagenes}/${imagenes[RANDOM % ${#imagenes[@]}]}"

# Configura la imagen como fondo de pantalla con Nitrogen
nitrogen --set-zoom-fill --save "$imagen_aleatoria"
