#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char ** argv){
        int x;
        
        pid_t pid = fork();
        if(!pid){
		x=100;
		printf("(hijo) mi pid es %d y mi X = %d\n", getpid(), x);
	}
	else{
		wait(NULL);
		x=500;
		printf("(padre) m pid es %d y mi X = %d\n", getpid(), x);
	}

return 0;
}
