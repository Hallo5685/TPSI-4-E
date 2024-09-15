
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    
    double num1, num2, quoziente = 0;
    
    do
    {

        printf("Inserire primo numero: \n");
        scanf("%e", &num1);

		printf("Inserire secondo numero: \n");
		scanf("%e", &num2);
        
        if(num1 < num2)
        {
            quoziente = (double) num1 / num2;
            
        }
        else
        {
            quoziente = (double) num2 / num1;
        }
        
        //appunto personale ricordati di usare %f per stampare il double
        printf("Il quoziente è: %f \n\n", quoziente);

    
     } while(num1 != 0  && num2 != 0);



    return 0;
}