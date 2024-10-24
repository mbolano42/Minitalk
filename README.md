# ***Minitalk***
`
`
_Resumen: El propósito de este proyecto es crear un pequeño programa de intercambio de
datos utilizando señales UNIX._

## Índice general
`
`
- I. Instrucciones específicas
- II. Parte obligatoria
- III. Bonus
`
`
# Capítulo I: Instrucciones específicas.
`
`
- Los ejecutables deben llamarse: `client` y `server`.
- Deberás proporcionar un archivo `Makefile`, que compilará los archivos fuente de yu programa. ***No deberá hacer relink***.
- Debes gestionar los errores con cuidado. Bajo ninguna circunstancia tu programa puede terminar inesperadamente (segfault, bus error, double free, etc).
- Tu programa no puede tener **leaks de memoria**.
- En la parte obligatoria se te permite utilizar las siguientes funciones:

```
◦ write
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit
```
`
`
# Capítulo II: Parte obligatoria.
`
`
- Debes crear un programa de comunicación en la forma de un **cliente** y un **servidor**.
- El servidor debe lanzarse primero, tras lanzarse debe mostrar su **PID**.
- El cliente tomará como parámetros:

```
◦ El PID del servidor.
◦ La cadena de caracteres (string) que debería mandarse.
```
1. - El cliente debe comunicar la string pasada como parámetro al servidor.
2. - Una vez la string se haya recibido, el servidor debe mostrarla.

```
OJO: 1 segundo para mostrar 100 caracteres es ¡muchíiiiisimo!
```
- Tu servidor debe poder recibir strings de distintos clientes consecutivamente, sin necesidad de reiniciar.
- La comunicación entre tu cliente y tu servidor debe hacerse **SOLO** utilizando señales UNIX.
- Solo puedes utilizar estas dos señales: `SIGUSR1` y `SIGUSR2`.

```
Linux no pone en cola señales cuando ya tienes señales pendientes de este tipo.
```
`
`
# Capítulo III: Bonus.
`
`
- El servidor debe confirmar cada señal recibida mandando una señal al cliente.
- El servidor debe ser capaz de interpretar los caracteres **Unicode**.
`
`
`
`