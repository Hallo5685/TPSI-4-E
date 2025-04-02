#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
Si vuole realizzare un software concorrente in linguaggio C che legga un file di testo da argv[1] e conteggi il numero di parole presenti nel file.
Una volta effettuato il conteggio il programma principale deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat. 
P2 legge da pipe il flusso di caratteri e capisce quando finisce una parola e ne inizia un'altra, in modo da poter aggiornare il contatore. 
P2 invia a P0 il totale 
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 parole
*/

int contaParole(char buffer)
{
    int count = 0;
    while (buffer != '\0')
    {
        if (buffer == ' ' || buffer == '\n')
        {
            count++;
        }
        
    }
    return count;
}


int main(int argc, char* argv[])
{
    int p1, p2;
    int p1p2[2], p2p0[2];
    
    if(argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(1);
    }
    //preparazione della pipe p1p2
    pipe(p1p2);
    p1 = fork();

    if(p1 == 0) //P1
    {
        close(0);
        dup(p1p2[1]);
        close(p1p2[0]);
        execl("/usr/bin", "cat", argv[1], NULL);
        return -1;
    }
    //preparazione della pipe p2p0
    pipe(p2p0);

    p2 = fork();

    if(p2 == 0)//P2
    {      
        //preparazione pipe P1P2
        close(p1p2[1]);

        char buffer;
        int count = 0;
        while (read(p1p2[0], &buffer, sizeof(buffer)))
        {   
            //conta le parole nel buffer
            count = contaParole(buffer);
            //Scrive nella pip1 p2p0
            
        }
        write(p2p0[1], &count, sizeof(count));
    
        //preparazione pipe P2P0
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        //Per terminare il processo P2 quando il processo P1 termina
        exit(0);
    }

    //P0 aspetta la terminazione dei Figli P1 e P2
    //wait(&p1);
    wait(&p2);
    
    int contatore;
    read(p2p0[0], &contatore, sizeof(contatore));

    //chiusura pipe
    close(p2p0[0]);
    close(p2p0[1]);
    
    //Stampa del risultato
    printf("Nel file sono presenti %d parole\n", contatore);

    return 0;
}