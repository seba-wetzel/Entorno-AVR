# Entorno-AVR

Entorno de trabajo con todas las herramientas necesarias para trabajar en C (tool chain) con microcontroladores AVR en sistemas operativos GNU/Linux. Lo unico necesario es tener make instalado.
Cuenta con un Makefile para compilacion y carga del programa en el microcontrolador target.

###Como se usa:
  1. Trabajar sobre el archivos app/src/main.c
  2. Colocar todos los .h creados por el usuario en la carpeta /inc
  3. Abrir una terminal en la carpeta principal o raiz del proyecto
  4. Ejecutar el comando make
  5. Ejecutar "make flash" (sin las comillas) para cargar el programa en el microcontrolador.*


*Hay que modificar el makefile con las configuraciones propias, por ejemplo el puerto serie a utilizar y el programador.
De usar un USBasp primero hay que instalar las reglas con el comando "sudo make install"
de esta manera se crea un puerto especial usbasp. 


## Libreria "simil arduino" en C (Intente seguir la API de arduino hasta donde me parece logico)

Se incluye una libreria para el manejo de los puertos I/O con funciones similares a las de arduino.
La diferencia es que estas funciones son agnosticas a la placa, son de mas bajo nivel, ya que se manejan con el puerto y pin del microcontrolador.

Ej:

|   Arduino                  |  Libreria en C                  | Funcion             |
| ---------------------------| --------------------------------|---------------------|
|  digitalWrite(13,HIGH);    |  digitalWrite(B,5,HIGH);        | Escritura de puerto |
|  digitalRead(6);           |  digitalRead(D,6);              | Lectura de puerto   |
|  pinMode(5,INPUT);         |  pinMode(D,5,INPUT);            | Configuracion de puerto |
