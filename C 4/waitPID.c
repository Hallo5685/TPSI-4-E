#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int p, pid, status;

    p = fork();

    if (p > 0)//padre
    {
        printf("Sono il padre: %d\n", getpid());
        

        int p2 = fork();

        if(p2 == 0)//Figlio P2
        {
            printf("Sono P2 %d, Mio padre P1 è: %d\n", getpid(), getppid());
            printf("P2 esce con valore 2\n\n");
            exit(2);
        }
        else if (p2 < 0)//figlio generato con errori
        {
            printf("P2 è stato generato con errori \n");
        }
        //P1 aspetta che P2 esca e salva in "_variabileDiSalvataggioP2" il valore 2
        waitpid(p, &status, 0);
        printf("Il figlio %d ha restituito %d\n", pid, WEXITSTATUS(status));

    }
    else if (p == 0)//figlio
    {
        sleep(5);
        printf("Sono il figlio: %d\n", getpid());
        printf("Il figlio %d esce\n", getpid());
        exit(25);
    }
    else
    {
        printf("Il figlio non è stato generato \n");
    }

    
    

    return 0;
}