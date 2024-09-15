
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int num1, num2;
    double quoziente = 0;
    

    
    do
    {

        printf("Inserire primo numero: \n");
        scanf("%d", &num1);

		printf("Inserire secondo numero: \n");
		scanf("%d", &num2);
        
        if(num1 >= num2)
        {
            quoziente = (double) num1 / (double)num2;
            
        }
        else
        {
            quoziente = (double) num2 / (double)num1;
            
        }

        if(quoziente > 0)
        {
            quoziente = sqrt(quoziente);
            printf("La radice quadrata del quoziente dei numeri è: %f",quoziente);
            
        }
        

     }while(quoziente > 0);

    printf("ERRORE: i numeri inseriti impedivano il calcolo della radice quadrata del loro rapporto ");

    return 0;
}