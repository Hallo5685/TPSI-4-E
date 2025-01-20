#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//TERMINA L'ESERCIZIO (mancano delle wait())

//funzione che popola un array con numeri randomici
void popolaArrayNumeriRandom(int array[], int size, int minValue, int maxValue)
{
    srand(time(NULL));
    for(int i=0; i < size; i++)
    {
        array[i] = minValue + (rand() % (maxValue - minValue +1));
    }
}

//funzione che calcola il prodotto dei componenti dell'array
int calcolaProdottoComponentiVettore(int array[], int size)
{
    //
    int prodotto = 1;

    for(int i=0; i < size; i++)
    {
        prodotto *= array[i];
    }

    return prodotto;
}

//funzione che calcola la somma delle componenti dell'array
int sommaComponentiDelVettore(int array[], int size)
{
    int somma = 0;

    for(int i=0; i < size; i++)
    {
        somma += array[i];
    }

    return somma;
}

//funzione che calcola la media delle componenti dell'array
double mediaDelleComponentiDelVettore(int array[], int size)
{
    return (double) sommaComponentiDelVettore(array, size) / size;
}

void stampaComponentiArray(int array[], int size)
{
    for(int i=0; i < size; i++)
    {
        printf("%d\t", &array[i]);
    }
}

int main(int argc, char* argv[])
{   
    int array [3];
    int size = sizeof(array)/sizeof(array[0]);

    popolaArrayNumeriRandom(array, size, 0, 5);

    int p2, p3, p4, p5, p6;
    int numero;
    
    p2 = fork();

    if(p2 > 0) //Dentro P1 che genererà P3
    {   
        p3 = fork();

        if( p3 == 0)//Dentro P3 
        {
            printf("Sono P3 di pid: %d mio padre P1 ha pid: %d \n",getpid(), getppid());
            int aspettaP3;

            p6 = fork();

            if(p6 == 0) //Dentro P6 figlio di p3
            {
                printf("Sono P6 di pid: %d mio padre P3 ha pid: %d \n",getpid(), getppid());
                //P6 esce ritornando il valore della somma
                exit(sommaComponentiDelVettore(array, size));

            }else if (p3 < 0)
            {
                printf("P6 non è nato correttamente \n");
            }

            wait(aspettaP3);
            //printf("\nP3 la somma delle componenti: %d ", WEXITSTATUS(aspettaP3));

            exit(3);

        }else if (p3 < 0)
        {
            printf("P3 non è nato correttamente \n");
        }
        

    }else if (p2 == 0) //Dentro P2 che genererà P4
    {      
        printf("Sono P2 di pid: %d mio padre P1 ha pid: %d \n", getpid(), getppid());

        p4 = fork();

        if(p4 == 0) //Dentro figlio P4 di P2
        {
            printf("Sono P4 di pid: %d mio padre P2 ha pid: %d \n", getpid(), getppid());

            exit(4);

        }else if (p4 < 0)
        {
            printf("P4 non è nato correttamente \n");
        }
        
        p5 = fork();

        if(p5 == 0)//Dentro figlio P5 di P2
        {
            printf("Sono P5 di pid: %d mio padre P2 ha pid: %d \n", getpid(), getppid());
            exit(5);

        }else if (p5 < 0)
        {
            printf("P5 non è nato correttamente \n");
        }

        exit(2);
    }
    


    return 0;    
}