#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int add(int *a, int *b, int *c){
    return (*a + *b + *c);
}

int main(){
    int a = 2;
    int b = 7;
    int c = 1;

    printf("The three integers: %d %d %d\n", a, b, c);
    int sum = add(&a, &b, &c);
    printf("The addition of them: %d\n", sum);
    
    return 0;
}
