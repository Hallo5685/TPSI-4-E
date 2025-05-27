#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    int p1, p1p0[2];

    // Create a pipe
    if(pipe(p1p0) < 0) 
    {
        perror("pipe failed");
        exit(1);
    }

    p1 = fork();
    

    if(p1 == 0)//P1
    {  
        close(p1p0[0]); // Close read end of the pipe
        int numero = 2; 
        printf("P1: %d \n", getpid());
        close(p1p0[0]);
        // Write the integer to the pipe
        write(p1p0[1], &numero, sizeof(numero));
        close(p1p0[1]); // Close write end of the pipe
        exit(0);
    }
    else if(p1 < 0) // fork failed
    {
        perror("fork failed");
        exit(1);
    }

    close(p1p0[1]); // Close write end of the pipe in parent
    int numero;
    // Read the integer from the pipe
    read(p1p0[0], &numero, sizeof(numero));
    close(p1p0[0]); // Close read end of the pipe
    printf("P0: %d mio figlio P1 è: %d\n", getpid(), p1);
    printf("Read integer: %d\n", numero);

    return 0;  
}