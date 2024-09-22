#include <stdio.h>
#include <math.h>

int main ()
{   
    int somma = 0, numero, numeroInserimenti;

    printf("Quante numeri vuole inserire?: \n");
    scanf("%d", &numeroInserimenti);

    printf("\n");

    for(int i = 0; i < numeroInserimenti; i++)
    {
        printf("Inserie il %d numero: \n",i+1);
        scanf("%d",&numero);

        if(numero < 0)
        {   
            printf("\nNon è possibile eseguire il calcolo...");
            i = numeroInserimenti;
        }
        else
        {
            numero = sqrt(numero);
            somma = somma + numero;
        }

    }

    printf("\nLa somma è: %d ",somma);



    return 0;
}


//            quoziente = sqrt(quoziente);
