# Entorno-AVR

Entorno de trabajo con todas las herramientas necesarias para trabajar en C (tool chain) con microcontroladores AVR en sistemas operativos GNU/Linux. Lo unico necesario es tener make instalado.
Cuenta con un Makefile para compilacion y carga del programa en el microcontrolador target.

##Como se usa:
  1. Trabajar sobre el archivos /src/main.c
  2. Colocar todos los .h creados por el usuario en la carpeta /inc
  3. Abrir una terminal en la caepta principal o raiz del proyecto
  4. Ejecutar el comando make
  5. Ejecutar "sudo make flash" (sin las comillas) para cargar el programa en el microcontrolador.*
  
  
*Por el momento el Makefile solo cargar el programa en un arduino usando el bootloader integrado.
