#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    int p[2];
    char msg[] = "This is a message!";
    char buffer[50];

    pid_t pid;

    // Create a pipe
    if(pipe(p) == -1){
        perror("pipe error");
        return 1;
    }
    // Create a fork
    pid = fork();
    if(pid < 0){
        perror("fork error");
        return 1;
    }
    // Handle communication through the pipe
    if(pid == 0){
        // The child sends the message
        close(p[0]);
        write(p[1], msg, strlen(msg)+1);
        close(p[1]);
        wait(NULL);
    }else{
        // The parent reads the message
        close(p[1]);
        read(p[0], buffer, sizeof(buffer));
        printf("The parent received: %s\n", buffer);
        close(p[0]);
    }

    return 0;
}
