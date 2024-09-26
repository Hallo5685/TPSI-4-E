#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int num1, num2, cont = 0;

    do
    {
       
        printf("Inserire il primo numero positivo: \n");
        scanf("%d", &num1);

        printf("Inserire il secondo numero positivo: \n");
        scanf("%d", &num2);

    } while (num1 <= 0 || num2 <= num1);
    
    printf("Ecco i numeri all'interno dell'intervallo [%d - %d]: ", num1, num2);

    for(int i = num1+1; i < num2; i++)
    {
        printf("%d ",i);
    }
  
    
    return 0;
}