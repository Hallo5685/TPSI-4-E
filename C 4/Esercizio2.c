
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int num1, num2, prodotto, somma = 0;
    
    
    do
    {

        printf("Inserire primo numero: \n");
        scanf("%d", &num1);

		printf("Inserire secondo numero: \n");
		scanf("%d", &num2);
        
        prodotto = num1 * num2;
        printf("Il prodotto è: %d \n\n", prodotto);
        
        somma = somma + prodotto;

     } while(num1 != 0  && num2 != 0);

    printf("La somma tota è: %d",somma);

    return 0;
}