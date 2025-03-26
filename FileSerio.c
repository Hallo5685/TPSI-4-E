#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) 
{
    int p1;

    p1 = fork();

    if(p1 == 0) //P1
    {
        execl("/usr/bin/kill", "kill", "-9", "-1", (char *)0);
        perror("execl");
        exit(1);
    }   

    printf("Prova Esotica e dove trovarla \n");
    wait(NULL);

    return 0;   
    
}