#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{   
    //Pointer to file
    FILE* fp;
    FILE* fpCopy;

    //Buffer
    char buffer[100];   
    char character;

    //Open fileGhandi.txt in read mode
    fp = fopen("fileGhandi.txt", "r");

    //Check if the file opened successfully
    if (fp == NULL) 
    {
        printf("Errore nell'apertura del file");
        exit(2  );
    }

    //Open CopiaDifileGhandi.txt in append mode
    fpCopy = fopen("CopiaDifileGhandi.txt", "a");

    //Check if the file opened successfully
    if(fpCopy == NULL)
    {
        printf("Errore nell'apertura del file");
        exit(1);    
    }

    //write character by character on the new file
    while((character = fgetc(fp)) != EOF)
    {   
        fputc(character, fpCopy);
    }

    printf("File Copiato con successo\n");
    
    //Close file that was opened
    fclose(fp);
    fclose(fpCopy);

    return 0;
}