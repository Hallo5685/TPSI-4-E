#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int num;

    do
    {
        printf("Inserire un numero intero: \n");
        scanf("%d",&num);

    } while (num < 0);
    
    int somma = 0;
    int i = num; 

    do
    {
        if((i - 1)%2 == 0)
        {
            somma = somma + i;
            i = i-1;
        }

    } while (i > 0);
    
    printf("La somma è: %d", somma);


    return 0;
}