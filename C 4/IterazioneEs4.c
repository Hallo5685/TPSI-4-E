#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int numero, cont = 0;

    do
    {
        printf("Inserire un numero positivo \n");
        scanf("%d", &numero);

    } while (numero < 0);
    
    do
    {
        cont++;
        if(cont %2 == 0)
        {
            printf("%d\n ",cont);
        }

    }while(cont < numero);

  
    
    return 0;
}