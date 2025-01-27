#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{   
    //Dichiarazioni delle variabili
    int p2, p3, p4, p5, p6;
    int n;

    //inserimento di un numero tra 0 e 10 (compresi)
    do
    {
        printf("Inserire un numero compreso tra 0 e 10: \n");
        scanf("%d",&n);

    } while (n < 0 || n > 10);

    p2 = fork();

    if(p2 > 0) //Dentro P1
    {
        printf("P1 di pid: %d Mio figli P2 è: %d \n",getpid(), p2);

        p3 = fork();

        if(p3 == 0)//Dentro P3
        {
            printf("P3 di pid: %d Mio padre P1 è: %d \n",getpid(), getppid());

            p6 = fork();

            if(p6 == 0)//Dentro P6
            {
                printf("P6 di pid: %d Mio padre P3 è: %d \n",getpid(), getppid());
                printf("P6: %d \n",getpid());
                n = n*n;

                exit(n);
            }
            else if (p6 < 0)//generazione errata p6
            {
                printf("P6 è stato generato in modo sbagliato \n");
            }
            
            int aspettaP6;
            wait(&aspettaP6);

            printf("P3: %d Valore di n al quadrato: %d \n",getpid(), WEXITSTATUS(aspettaP6));

            exit(3);
        }
        else if (p3 < 0)//generazione errata p3
        {
            printf("P3 è stato generato in modo sbagliato \n");
        }
        
    }
    else if (p2 == 0)//Dentro P2
    {
        printf("P2 di pid: %d Mio padre P1 è: %d \n",getpid(), getppid());

        p4 = fork();

        if(p4 == 0)//Dentro P4
        {
            printf("P4 di pid: %d Mio padre P2 è: %d \n",getpid(), getppid());

            //conto alla rovescia da n a 0
            printf("P4:%d ", getpid());
            for(int i=n; i > 0; i--)
            {
                sleep(1);
                printf("%d ", i);
            }
            printf("\n");

            exit(4); //termina P4
        }
        else if (p4 < 0)//generazione errata P4
        {
            printf("P4 è stato generato in modo sbagliato \n");
        }
        
        p5 = fork();

        if(p5 == 0)//Dentro P5
        {
            printf("P5 di pid: %d Mio Padre P2 è: %d \n",getegid(), getppid());

            //ciclo crescente da 0 a n
            printf("P5:%d ", getpid());
            for(int i=0; i < n; i++)
            {
                sleep(1);
                printf("%d ",i+1);
            }

            exit(5);
        }
        else if (p5 < 0)//generazione errata p5
        {
            printf("P5 è stato generato in modo sbagliato \n");
        }
        
        /*int aspettaP4;
        wait(&aspettaP4);

        int aspettaP5;
        wait(&aspettaP5);
*/
        exit(2);

    }
    else //generazione errata P2
    {
        printf("P2 è stato generato in modo sbagliato \n");
    }


    return 0;
}