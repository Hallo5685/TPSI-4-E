#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

void convertiMaiuscolo (char str[])
{

    for(int i=0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }


}


 int main(int argc, char* argv [])
 {
    char str[strlen(argv[1])];

    int p1;

    p1 = fork();

    if(p1 == 0)
    {
        strcpy(str, argv[1]);
        convertiMaiuscolo(str);
        printf("Ecco la stringa inserita: %s\n\n", str);
        //Uscita del programma figlio
        exit(0);
    }
    else
    {   
        //il padre aspetta il figlio
        wait(&p1);
    }

    printf("Sono il processo padre %d",getpid());

    return 0;
 }