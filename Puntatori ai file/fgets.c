#include <stdio.h>
int main(int argc, char* argv[])
{
    FILE* fp;
    char buffer[100];
    int lineCount = 0, charCount = 0;

    // Open a file for reading
    fp = fopen("fileGhandi.txt", "r");
    //Check if the file opened successfully
    if (fp == NULL) 
    {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        lineCount++;
        for (int i = 0; buffer[i] != '\0'; i++) {
            charCount++;
        }
    }

    //Close the file 
    fclose(fp);
    //Print the resoults
    printf("Numero di righe: %d\n", lineCount);
    printf("Numero di caratteri: %d\n", charCount);
    return 0;
}