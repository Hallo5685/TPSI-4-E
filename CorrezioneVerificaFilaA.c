//manpages-dev per installare open.2 a casa
#include <sys/types.h>
#include <sys/stat.h>       
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wait.h>

int sommaComponenti(int array[])
{
    int somma = 0;

    for (int i = 0; i < 3; i++)
    {
        somma += array[i];
    }

    return somma;
}

int calcolaProdrottoArray(int array[])
{
    int prodotto;

    for(int i=0; i < 3; i++)
    {
        prodotto *= array[i]; 
    }

    return prodotto;
}

double calcolaMediaArray(int array[])
{
    return (double)sommaComponenti(array) / 3;
}

int main(int argc, char * argv[])
{   
    int p2, p3, p4, p5, p6;
    int valoreMin, valoreMax;


    //ricordati di creare una funzione random che gestisca l'inserimento dei valori dato un valore minimo e massimo compresi
    int array [3] = {1,5,2};

    p2 = fork();

    if(p2 > 0) //Dentro padre P1 
    {
        printf("Sono P1: %d mio figlio P2 è: %d\n",getpid(), p2);
        
        p3 = fork();

        if(p3 == 0) //Dentro P3 figlio di P1
        {
            printf("Sono P3: %d figlio di P1: %d\n", getpid(), getppid());

            p6 = fork();

            if(p6 == 0) //Dentro P6 figlio di P3
            {
                printf("Sono P6: %d figlio di P3: %d\n", getpid(), getppid());
                
                //Uscita di P6
                exit(6);
            }

            int aspettaP6;
            //P3 aspetta P6
            wait(&aspettaP6);

            //uscita di P3
            exit(3);
        }
        else if (p3 < 0)
        {
            printf("Processo P3 è nato in maniera errata: \n");
        }
        
        int aspetta3;
        //P1 Aspetta P3
        wait(&aspetta3);


    }
    else if( p2 == 0) //Dentro Figli P2 di padre P1 
    {
        printf("Sono P2: %d mio padre P1 è: %d\n", getpid(), getppid());

        p4 = fork();

        if(p4 == 0) //Dentro P4 figlio di P2
        {
            printf("Sono P4: %d figlio di P2: %d\n", getpid(), getppid());
            //questo pezzo è da sistemare
            printf("P4: %d Ecco il prodotto dei valori nell'array %d\n\n",getpid() ,calcolaProdrottoArray(array));    

            //Escita Processo 4
            exit(4);
        }
        else if(p4 < 0)
        {
            printf("Processo P4 è nato in maniera errata: \n");
        }

        p5 = fork();

        if(p5 == 0) //Dentro P5 figlio di P2
        {
            printf("Sono P5: %d figlio di P2: %d\n", getpid(), getppid());
            printf("P5: %d ecco la media degli argomenti dell'array %.2f\n\n", getpid(), calcolaMediaArray(array));
            exit(5);
        }

        int aspettaP4, aspettaP5;
        //P2 aspetta la terminazione dei figli 
        wait(&aspettaP4);
        wait(&aspettaP5);

        //Uscita di P2  
        exit(2);
    }

    return 0;
}