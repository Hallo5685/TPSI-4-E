//manpages-dev per installare open.2 a casa
#include <sys/types.h>
#include <sys/stat.h>       
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv [])
{
    /*if(argc != 2)
    {
        printf("Il programma è iniziato in maniera non corretta: ");
        exit(1);
    }*/

    char alfabeto [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //La system call open gestisce la eventuale esistenza/non esistenza del file
    //0777 sono i permessi che lascio di apertura al file
    int fd = open(argv[1] , O_WRONLY | O_CREAT, 0777);

    write( fd, alfabeto, sizeof(alfabeto));
    //chiudo il file director
    close(fd);

       return 0;
}