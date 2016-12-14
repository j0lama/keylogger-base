# keylogger-base
Sencillo keylogger escrito en C y destinado a Linux.

NOTA: Solamente funciona para teclados conectados por USB (no para los teclados de portatiles).

**Compilación**

Comando: *gcc keylogger.c -o keylogger*

**Uso**

Comando: *./keylogger "Keyboard descriptor path" "Log file"*

En el caso de no ser usuario root ejecutalo con la opción sudo: *sudo ./keylogger "Keyboard descriptor path "Log file"*

NOTA: Para saber el "Keyboard descriptor path" usa el comando *ls /dev/input/by-id/* e identifica cual corresponde con el teclado USB.

**Funcionamiento**

El programa lee del archivo temporal creado en /dev/input/by-id/ y usando una estructura tipo input_event y una tabla de valores que asocia el código del evento a la tecla pulsada crea un log donde almacena todo el registro de pulsaciones.
