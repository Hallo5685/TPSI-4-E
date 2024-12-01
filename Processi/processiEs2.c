#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    /*
        Scrivi il codice sorgente di un programma in cui il processo padre genera tre processi figli.
        Ciascun processo deve visualizzare sullo schermo, rispettivamente

        -Sono il processo padre , il mio PID=... mio figlio...ha PID=...
        -Sono un processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Qui"
        -Sono un processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Quo"
        -Sono unl processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Qua"
    */

    int p1, p2, p3; 

    p1 = fork();

    if(p1 == 0)
    {
        printf("Sono il processo figlio: %d mio padre è: %d", getpid(), getppid());
        exit(0);
    }

    p2 = fork();

    if(p2 == 0)
    {
        printf("Sono il processo figlio: %d mio padre è: %d", getpid(), getppid());
        exit(0);
    }

    p3 = fork();

    if(p3 == 0)
    {
        printf("Sono il processo figlio: %d mio padre è: %d", getpid(), getppid());
        exit(0);
    }

    return 0;
}
