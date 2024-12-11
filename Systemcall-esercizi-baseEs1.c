#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv [])
{
    int fileD, fileR;
    char buffer [1000] = "";
    //potrebbe servire per una lettura char to char
    char fileBuffer;

    //con 0 leggi solo da tastiera
    //con 1 stampi a video (sostituire dove c'è scritto o_RDONLY)
    //open() restituisce un int dato un file .txt presente nella cartella del codice stesso e il flag 

    fileD = open("rfc1918.txt", O_RDONLY);

    /*
    Se l'open è stata creata male ritorna -1 o 0 
    printf("Prova della Open: %d ",fileD);
    */


    //read() restituisce un int, vuole un int con cui hai usato la open, l'indirizzo della string su cui scriverai e la sua lunghezza in Byte
    fileR = read(fileD, &fileBuffer, sizeof(fileBuffer));

    while (fileR > 0)
    {   
        //sistem call che scrive su terminale
        write(fileD, &fileBuffer, sizeof(fileBuffer));
    }

    //Close retorna 0 se ha successo, -1 altrimenti. Vuole un int nella sua firma
    close(fileD);


    return 0;

}
//SBAGLIATO, DA RICONTROLLARE