#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;

    // Create a fork
    pid = fork();
    if(pid < 0){
        perror("fork error");
        return 1;
    }

    if(pid == 0){
        // The child waits for signal
	printf("This is the child process\n");
        while(1){
            printf("Waiting to be killed...\n");
	    sleep(1);
        }
    }else{
        // The parent sends the signal
        // Give the child process some time to execute
        printf("This is the parent process. About to kill child.\n");
	sleep(5);
        if(kill(pid, SIGTERM) == -1){
            perror("kill");
            exit(EXIT_FAILURE);
        }
        // Give the child process some time to terminate
        wait(NULL);
        printf("Mission accomplished.");
    }

    return 0;
}
