#!/bin/bash

ruta_imagenes="${HOME}/walls"

imagenes=("1.jpg" "2.jpg" "3.jpg" "4.jpg" "5.PNG" "6.PNG" "7.PNG" "8.PNG" "9.jpg")

imagen_aleatoria="${ruta_imagenes}/${imagenes[RANDOM % ${#imagenes[@]}]}"

nitrogen --set-zoom-fill --save "$imagen_aleatoria"
