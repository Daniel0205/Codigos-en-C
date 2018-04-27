
/**Enunciado: "Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child and parent
access the file descriptor returned by open()? What happens when they are
writing to the file concurrently, i.e., at the same time?"

Author:
* Daniel Diaz Ocampo - 201629338
* Jem pool Suarez - 1630536
Date:27/04/2018
*/

// Incluir archivos de cabecera para las funciones que requiere para
// solucionar el enunciado
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char **argv) {
	
	// Usar estas variables
	int x;
	pid_t pid;
	char *filename="code-02.txt";
	int fd;
	
	//
	// Instrucciones para abrir archivo de lectura/escritura)
	//
	fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); 
	 
	x = 100;
	pid = fork();
	if (pid == 0) {
		x++;
		dprintf(fd, "(hijo) mi PID es %d y mi x = %d\n", getpid(), x);    
	} 
	else{
		x+=2;
		dprintf(fd, "(padre) mi PID es %d y mi x = %d\n", pid, x);   
	}

  close(fd);  
}

