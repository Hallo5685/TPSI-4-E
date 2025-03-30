#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza. 
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.
*/

int main(int argc, char *argv[])
{
    int p1p0[2], c_parole_trovate = 0, p1;
    char stringa[1000], c_parole_trovate_tot [1000];

    //se il numero di parametri è diverso da 2
    if (argc != 2)
    {
        fprintf(stderr, "Errore nei parametri\n");
        exit(1);
    }
    //preparazione della pipe (p1p0)
    pipe(p1p0);

    while (1) //while infinito
    {
        printf("Inserisci una stringa: ");
        scanf("%s", stringa);

        //se la stringa inserita è "fine" allora la pipe viene chiusa e il programma termina
        if(strcmp(stringa, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Numero totale di parole trovate: %d\n", c_parole_trovate);
            exit(1);
        }

        p1 = fork(); //creazione del processo figlio

        if(p1 == 0)//P1
        {
            close(p1p0[0]); //chiud std input della pipe
            close(1); //chiud std output
            dup(p1p0[1]); //duplico la pipe
            close(p1p0[1]); //chiudo std output della pipe

            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0); //eseguo il comando grep
            return -1; //se fallisce ritorno -1
        }
       
        //P0 legge da P1 tramite pipe (p1p0)
        close(p1p0[1]); //chiudo std output della pipe
        read(p1p0[0], c_parole_trovate_tot, sizeof(c_parole_trovate_tot));
        printf("Il file ha %d '%s' \n", atoi(c_parole_trovate_tot), stringa);

        c_parole_trovate += atoi(c_parole_trovate_tot); //incremento il numero totale di parole trovate
    }
    

    return 0;
}