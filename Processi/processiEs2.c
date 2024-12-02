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

    int p2; 

    printf("Io sono il padre P1: %d\n", getpid());

    p2 = fork();

    if (p2 == 0) //FIGLIO P2
    {
        printf("Sono il processo figlio: %d mio padre è: %d\n", getpid(), getppid());

        int p4 = fork();

        if(p4 == 0) //FIGLIO P4 di P2
        {
            printf("Sono il figlio P4 di PID: %d Mio padre P2 ha PID: %d\n", getpid(), getppid());
        }
        else if(p4 > 0) //PADRE P2
        {
            printf("Sono il padre P2-PID: %d Mio figlio P4 ha PID: %d\n",getpid(), p4);
        }
        else
        {
            printf("Figlio non generato correttamente \n");
        }

    }
    else if (p2 > 0) // Sono dentro il padre P1
    {
        int p3 = fork();

        if (p3 == 0) //FIGLIO P3 di P1
        {
            printf("Sono il figlio P3-PID: %d Mio padre ha PID: %d\n", getpid(), getppid());
            int p5 = fork();

            if(p5 == 0)//FIGLIO P5 di P3
            {
                printf("Sono il figlio P5 di PID: %d Mio padre P3 ha PID: %d\n", getpid(), getppid());
            }
            else if(p5 > 0)//PADRE P3 di P5
            {
                printf("Sono il padre P3-PID: %d Mio figlio P5 ha PID: %d \n",getpid(), p5);
            }

        }
    }
    else
    {
        printf("P3 non è stato generato correttamente ");
    }

    /*p3 = fork();

    if(p3 == 0)
    {
        printf("Sono il processo figlio: %d mio padre è: %d\n", getpid(), getppid());
        exit(0);
    }

    p4 = fork();

    if(p4 == 0)
    {
        printf("Sono il processo figlio: %d mio padre è: %d\n", getpid(), getppid());
        exit(0);
    }
*/
    return 0;
}
