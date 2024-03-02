rutaImagenes = "${HOME}/walls"

imagenes = ("1.jpg" "2.jpg" "3.jpg")

imagenEscogida = "${rutaImagenes}/${imagenes[RANDOM] % ${#imagenes[@]}]}"

nitrogen --set-zoom-fill --save "${imagenEscogida}"