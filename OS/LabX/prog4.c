#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    FILE *fp = fopen("common_file.txt", "w");
    if (fp == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a fork
    pid = fork();
    if(pid < 0){
        perror("fork error");
        return 1;
    }

    if(pid == 0){
        // The child writes its pid to the common file
        fprintf(fp, "Child pid: %d\n", getpid());
	printf("Data written to file by child.\n");
    }else{
        // The parent writes its pid to the common file
        fprintf(fp, "Parent pid: %d\n", getpid());
	printf("Data written to file by parent.\n");
        wait(NULL);
    }

    if(fclose(fp) != 0){
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}
