#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int cercaNumeri(int listaNumeri [], int numeroDaCercare)
{


}


int main(int argc, char *argv[])
{
    int p2, status, numeroDaCercare,listaNumeri = {0,1,2,3,4,5,6,7,8,9};

    p2 = fork();

    if(p2 == 0) //figlio p2
    {
        printf("Inserire il numero da cercare nell'array: \n");
        scanf("%d", &numeroDaCercare);



        exit(2);
    }
    else
    {
        wait(&status);

    }

    return 0;
}