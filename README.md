
# Codigos-en-C

En este repositorio se encuentran algunos codigos-ejercicios hechos en clase referentes
a la creacion y la gestion de nuevos procesos creados en tiempo de ejecucion.


#  p2.c
En este programa se crea un nuevo proceso hijo donde se modifica la variable X 
y despues se imprime, garantizando que siempre se imprime la variable del proceso 
hijo por medio de la funcion wait().


#  p3.c
Este programa abre un archivo (con la llamada al sistema open ()) y luego llama
a fork () para crear un nuevo proceso. Donde tanto el hijo como el padre pueden
acceder a el archivo de texto creado como "code-02.txt" y modificarlo para escribir 
ahi tanto su pid como el valor de su x,se puede observar que primero escribe 
el padre y el hijo debe esperar a que el padre termine para poder escribir.


#  p4.c
Este programa usa el llamado a sistema fork () para crear un proceso hijo e imprimir 
"hola" y un proceso padre el cual imprime "adios", usando la funcion waitpid() (tambien 
se podria usar la funcion sleep() pero de ser un programa con un tiempo de ejecucion incierto 
no garantizaria nada) se garantiza que el proceso padre siempre esperara al proceso hijo
para realizar la salida.


#  p5.c
Este programa crea dos hijos,y conecta la salida estándar de uno al estándar
entrada del otro, usando la llamada al sistema pipe ().
