#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv [])
{   
    //Pointer to file
    FILE* fp, * fpPari, * fpDispari;

    //Create the variables
    char character;

    //Open fileNumeri.txt in read mode
    fp = fopen("fileNumeri.txt", "r");

    //Check if the file opened successfully
    if (fp == NULL) 
    {
        printf("Errore nell'apertura del file >> fileNumeri.txt\n");
        exit(1);
    }

    //Open fileNumeriPari.txt in append mode
    fpPari = fopen("fileNumeriPari.txt", "a");

    //Check if the file opened successofully
    if(fpPari == NULL)
    {
        printf("Errore nell'apertura del file >> fileNumeriPari.txt\n");
        exit(1);    
    }
    //Open fileNumeriDispari.txt in append mode
    fpDispari = fopen("fileNumeriDispari.txt", "a");
        
    //Check if the file opened successofully
    if(fpDispari == NULL)
    {
        printf("Errore nell'apertura del file >> fileNumeriDispari.txt\n");
        exit(1);    
    }

    //Central loop that reads the file character by character
    while((character = fgetc(fp)) != EOF)
    {   
        if(character % 2 == 0)
        {
            fputc(character, fpPari);
        }
        else
        {
            fputc(character, fpDispari);
        }
    }

    printf("Copiatura su fileNumeriPari.txt e fileNumeriDispari.txt avvenuta con successo\n");

    //Close file that was opened
    fclose(fp);
    fclose(fpPari);
    fclose(fpDispari);

    return 0;
}