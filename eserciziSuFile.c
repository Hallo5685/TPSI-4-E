#include <stdio.h>
#include <unistd.h> //per la exit

int main()
{   
    /*FILE è un tipo di dato (oggetto), una struttura definita in stdio.h */ 
    FILE* nomi; //definisco una variabile di tipo puntatore a file
    
    //fopen apre un file in lettura o scrittura e restituisci un puntatore a FILE
    nomi = fopen("nomi.txt", "w"); //apro il file in scrittura (se non esiste lo crea, se esiste lo sovrascrive, la 'a' lo apre in append quindi aggiunge alla fine)
    if(nomi == NULL) //se fopen restituisce NULL vuol dire che c'è stato un errore
    {
        printf("Errore nell'apertura del file\n");
        exit(1); //termina il programma
    }
    return 0;
}