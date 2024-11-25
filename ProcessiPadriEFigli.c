#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int p1, p2, p3, p4;

    //fork del processo padre e generazione del processo figlio1
    p1 = fork();

    if(p1 > 0)
    {
        printf("Questo è il puntatore del dip del processo padre: %d \n",getpid);
        printf("Questo è il pid del processo padre: %d \n",getpid());

        //fork del processo padre e generazione del processo figlio1 
        p2 = fork();
    }

    if(p1 == 0)
    {
        printf("Sono il processo figlio p1, ecco il mio pid: %d \n",getegid());


    }
    
    if(p2 == 0)
    {
        printf("\nSono il processo figlio p1, ecco il mio pid: %d \n",getegid());
    }

    return 0;
}