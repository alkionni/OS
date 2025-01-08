#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid[3];

    // create 3 forks
    for(int i=0; i<3; i++){
        pid[i] = fork();
        if (pid[i] < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("The processes PID is %d\n", getpid()); 
    return 0;
}
