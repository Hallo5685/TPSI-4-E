#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int numero;

    // Apertura del file in modalità APPEND binaria
    fp = fopen("salvaBinari.txt", "ab");

    if(fp == NULL)
    {
        printf("Errore nell'apertura del file\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Inserisci il %d numero intero: ", i+1);
        if (scanf("%d", &numero) != 1) {
            printf("Errore nell'inserimento\n");
            fclose(fp);
            exit(1);
        }

        // Scrittura del numero nel file binario
        if(fwrite(&numero, sizeof(int), 1, fp) != 1)
        {
            printf("Errore nella scrittura del file\n");
            fclose(fp);
            exit(1);
        }
    }
    printf("Scrittura completata.\n");
    fclose(fp);

    fp = fopen("salvaBinari.txt", "rb");
    if(fp == NULL)
    {
        printf("Errore nell'apertura del file\n");
        exit(1);
    }

    while(fread(&numero, sizeof(int), 1, fp))
    {
        printf("%d ", numero);
    }
    fclose(fp);

    
    return 0;
}
