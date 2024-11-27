#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{   
    /*
    Scrivi il codice sorgente di un programma che permette al processo padre di generare un processo figlio:
    -sia padre che figlio visualizzano il proprio PID e il PID del proprio parente
    -padre conta da 0 a 19 (visualizza i numeri da 0 a 19) 
    -figlio conta da 0 a 9 (visualizza i numeri da 0 a 9)
    Manda in esecuzione più volte e descrivi il comportamento del programma.

    */

    int p1 = fork();

    if (p1 > 0)
    {
        printf("Sono il processo padre: %d \n", getpid());
        printf("Mio figlio è: %d \n",p1);

        for (int i = 0; i < 20; i++)
        {
            printf("%d ", i);
        }
    }

    if (p1 == 0)
    {
        printf("\nSono il processo figlio %d ", getpid());
        printf("\nMio padre è il processo: %d ",getppid());

        for (int i = 0; i < 10; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}