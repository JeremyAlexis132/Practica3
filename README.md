# Practica_3

¿Qué hicimos?

Desarrollamos un algoritmo basado en el cifrado llamado Playfair, utilizando una tabla de 5x5 para organizar todas las letras del abecedario sin contar la ñ, y haciendo que la i y la j sean el mismo carácter para cubrir y justificar las 26 letras del alfabeto.

¿Cómo lo hicimos?

Lo hicimos a través de un algoritmo que crea una matriz de 5x5, lee la llave introducida por el usuario y se rellenan los espacios de la matriz primero con la llave (sin repetir letras del alfabeto) y después el resto de la matriz se rellena en orden normal con las letras faltantes del alfabeto sin repetir. Posteriormente se emplean un conjunto de métodos que, a partir de las posiciones de las letras en la matriz, se van formando desplazamientos, lo que permite encriptar el mensaje, para desencriptarlo, solo hace falta aplicar las funciones a la inversa.

¿Para qué lo hicimos?

Hicimos este algoritmo para observar el funcionamiento de este método de encriptación, entender de qué manera funciona a nivel algoritmo, e ir conociendo nuevos métodos de cifrado que se han seguido usando a base del cifrado de Cesar.

