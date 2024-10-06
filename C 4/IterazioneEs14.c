#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int num1, num2;
    int max = 0;
    int prodotto = 0;

    do
    {
        printf("Inserire il primo numero intero: \n");
        scanf("%d",&num1);

        printf("Inserire il secondo numero intero: \n");
        scanf("%d",&num2);

    } while (num1 < 1 || num2 < 1);
    
    int i = 0;

    do
    {
        prodotto = prodotto + num1;
        i = i+1;

    }while(i < num2);

    printf("Il prodotto è: %d", prodotto);


    return 0;
}