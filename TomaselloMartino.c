//Tomasello Martino 4E 3/2/2025
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/*funzione che somma i numeri pari presenti nell'array "_vettore" e restituisce il risultato nella variabile "somma_pari"
che passiamo quando "somma_Numeripari" viene richiamata nel main 
*/
int somma_NumeriPari(int _vettore [], int somma_pari)
{
    for(int i=0; i <5; i++)
    {
        if(_vettore[i]%2 == 0)
        {
            somma_pari = somma_pari+_vettore[i];
        }
    }   
    return somma_pari;
}

/*funzione che somma i numeri dispari presenti nell'array "_vettore" e restituisce il risultato nella variabile "somma_dispari"
che passiamo quando "somma_NumeriDispari" viene richiamata nel main 
*/
int somma_NumeriDispari(int _vettore [], int somma_dispari)
{
    for(int i=0; i <5; i++)
    {
        if(_vettore[i]%2 != 0)
        {
            somma_dispari = somma_dispari+_vettore[i];
        }
    }   
    return somma_dispari;

}

/* funzione che visualizza i componenti dell'array "_vettore"
 */
void visualizzaVettore(int _vettore [])
{
    for(int i=0; i<5; i++)
        {
            printf("%d ",_vettore[i]);
        }
}


//Tomasello Martino 4E 3/2/2025
int main()
{
    int _vettore [5];
    int somma_pari = 0, somma_dispari = 0;
    int _p2, _p3, _p4, _p5, _p6;

    printf("Io sono P1: %d: ",getpid());
    printf("Inserire 5 numeri interi: \n");
    
    //inserimento dei 5 numeri nel vettore 
    for(int i=0; i< 5; i++)
    {
        do
        {
            scanf("%d",&_vettore[i]);
        } while (_vettore[i] < 0 || _vettore[i] > 10);
    }

    //visualizzazione di "_vettore"
    printf("Vettore inserito: \n");
    visualizzaVettore(_vettore);
    printf("\n\n");

    //generazione di P2
    _p2 = fork();

    if(_p2 > 0)//P1
    {
        printf("Sono P1: %d mio figlio P2 è: %d \n",getpid(), _p2);

        //generazione di P3
        _p3 = fork();

        if(_p3 == 0)//P3
        {
            printf("Sono P3: %d mio padre P1 è: %d \n", getpid(), getppid());
            
            //generazione di P4
            _p4 = fork();

            if(_p4 == 0)//P4
            {
                printf("Sono P4: %d mio padre P3 è: %d \n", getpid(), getppid());
                somma_pari = somma_NumeriPari(_vettore, somma_pari);
                printf("P4: %d Ecco la somma dei numeri pari del vettore: %d \n", getpid(), somma_pari);
                //P4 esce con il valore "somma_pari"
                exit(somma_pari);
            }
            else if (_p4 < 0)//P4 non generato
            {
                printf("P3 è stato generato con errori \n");
            }
            
            //P3 aspetta che P4 esca e salva in "_variabileDiSalvataggioP4" il valore della somma_pari
            int _aspettaP4;
            wait(&_aspettaP4);
            int _variabileDiSalvataggioP4 = WEXITSTATUS(_aspettaP4);

            //generazione di P5
            _p5 = fork();

            if(_p5 == 0)//P5
            {
                printf("Sono P5: %d mio padre P3 è: %d \n", getpid(), getppid());
                somma_dispari = somma_NumeriDispari(_vettore, somma_dispari);

                printf("P5: %d Ecco la somma dei numeri dispari del vettore: %d \n", getpid(), somma_dispari);
                //P5 esce con il valore "somma_dispari"
                exit(somma_dispari);
            }
            else if (_p5 < 0)//P5 non generato
            {
                printf("P5 è stato generato con errori \n");
            }
            
            //P3 aspetta che P5 esca e salva in "_variabileDiSalvataggioP5" il valore di somma_dispari
            int _aspettaP5;
            wait(&_aspettaP5);
            int _variabileDiSalvataggioP5 = WEXITSTATUS(_aspettaP5);

            //la somma di "somma_pari" e "somma_dispari" viene salvata in "somma_tot"
            int somma_tot = _variabileDiSalvataggioP5 + _variabileDiSalvataggioP4;
            printf("P3: %d ecco la somma di somma_pari e somma_dispari: %d \n",getpid(), somma_tot);

            exit(3);
        }
        else if (_p3 < 0)//P3 non generato
        {
            printf("P3 è stato generato con errori \n");
        }
        

    }
    else if (_p2 == 0)//P2
    {
        printf("Sono P2: %d mio padre P1 è: %d \n", getpid(), getppid());
        exit(2);
    }
    else if (_p2 <0)//P2 non generato 
    {
        printf("P2 è stato generato con errori \n");
    }

    return 0;
}