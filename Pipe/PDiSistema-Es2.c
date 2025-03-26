#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

/*Scrivere un programma concorrente che realizzi il seguente comando:

cat file.txt | wc 

il processo p2 deve rimandare l'output di wc al padre, il quale lo scriverà
su un file chiamato wc.txt

il nome del file "file.txt" deve essere passato come argomento in argv[1]
*/

int main(int argc, char* argv[])
{
    int p1, p2;
    int P1P2[2];
    int P2P0[2];

    if(argc != 2)
    {
        printf("Errore: numero di argomenti non valido\n");
        exit(1);
    }

    pipe(P1P2);

    p1 = fork();

    //P1 deve eseguire la cat e mandarla a P2
    if(p1 == 0) //Dentro P1
    {   
        close(0);
        close(P1P2[0]);
        dup(P1P2[1]);
        close(P1P2[1]);

        //lancia la exec 
        execl("/bin/cat", "cat", argv[1], (char  *) 0);
    }

    pipe(P2P0);
    //P2 deve eseguire la wc e mandarla a P0
    p2 = fork();

    if(p2 == 0) //Dentro P2
    {   
        //prepara pipe P1P2
        close(P1P2[1]);
        close(0);
        dup(P1P2[0]);
        close(P1P2[0]);

        //Prepara pipe P2P0
        close(P2P0[0]);
        close(0);
        dup(P2P0[1]);
        close(P2P0[1]);

        execl("/bin/wc", "wc", (char *) 0);
    
    }

    int fd, nRead;
    char buffer;

    fd = open("wc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Errore nell'apertura del file wc.txt");
        exit(1);
    }

    while ((nRead = read(P2P0[0], &buffer, sizeof(buffer))) > 0)
    {
        write(fd, &buffer, nRead);
        close(P2P0[0]);
        close(P1P2[0]);
        close(P1P2[1]);
        close(fd);
        wait(NULL); // Wait for child processes to finish
        wait(NULL);
        close(P2P0[0]);
        close(fd);
    }
    
    return 0;
}