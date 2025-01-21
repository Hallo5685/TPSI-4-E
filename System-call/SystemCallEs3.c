#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void swap(int argc, char *argv[])
{
    int i, j;
    char *temp;

    for (i = 0; i < argc; i++)
    {
        //vengono ordinati tutti gli argomenti di argv (esclusi i primi 2)
        for (j = 2; j < (argc - i - 1); j++)
        {
            if (strcmp(argv[j], argv[j + 1]) > 0)
            {   
                //scambio delle stringhe in argv
                temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
}


int main(int argc, char *argv[])
{   
    if(argc < 2)
    {
        printf("Il numero di argomenti (argc) è sbagliato !");
        exit(1);
    }

    swap(argc, argv);

    //I permessi di lettura sono 6: (Proprietario legge e scrive) 4: Il gruppo legge solo 4: il resto del mondo legge solo
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);


    close(fd);


    return 0;
}













/* for (int i = 2; i < argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", strlen("\n"));

        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", strlen("\n"));
    }
*/