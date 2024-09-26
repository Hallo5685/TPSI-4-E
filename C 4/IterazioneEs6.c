#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int num1, num2;

    do
    {
        printf("Inserire un numero positivo: \n");
        scanf("%d", &num1);

    } while (num1 <= 0);

    printf("Ecco i numeri all'interno dell'intervallo [%d - %d]: ",num1*-1, num1);


    for(int i = num1*-1; i < num1; i++)
    {
        printf("%d ",i);
    }
  
    
    return 0;
}