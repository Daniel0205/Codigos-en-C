/*
Enunciado: Write a program that creates two children,
and connects the standard output of one to the standard
input of the other, using the pipe() system call 

Author:
* Daniel Diaz Ocampo - 201629338
* Jem pool Suarez - 1630536
Date:25/04/2018
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


#define buffer 32


int main(int argc, char *argv[]){
    
    char buff[buffer];
    int p[2];
       
    if (pipe(p) < 0){
        exit(1);
    }
    
    pid_t frk = fork();
    
    if (frk < 0) {
        fprintf(stderr, "fallo fork 1\n");
        exit(1);
        
    } else if (frk == 0) {
        // Hijo #1
        printf("Child 1 \n");
        close(p[0]);
        dup2(p[1], 1);
        printf("Esto sera enviado al Pipe\n");
        
    } else{
        int frk2 = fork();
        if (frk2 < 0) {
            fprintf(stderr, "fallo fork 2\n");
            exit(1);
        } else if (frk2 == 0) {
            // Hijo 2
            printf("Child 2 \n");
            
            dup2(p[0], 0);
            close(p[1]);
            
            char buf[512];

            read(STDIN_FILENO, buf, 512);
            printf("%s\n", buf);
            
        } else {
            
            int wp = waitpid(frk2, NULL, 0);
            
            printf("Fin\n");
        }
    }
    return 0;
}

