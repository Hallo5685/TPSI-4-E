#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int numero, successivo;

    do
    {
        printf("Inserire un numero positivo \n");
        scanf("%d", &numero);

    } while (numero < 0);
    
    successivo = numero + 1;

    printf("Ecco il numero successivo: %d",successivo);
    
    return 0;
}