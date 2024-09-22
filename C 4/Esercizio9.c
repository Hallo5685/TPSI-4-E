#include <stdio.h>
#include <math.h>

int main ()
{   
    int num1, num2, num3;
    int max = 0, min = 0;

    do
    {
        printf("Inserire il primo numero: \n");
        scanf("%d", &num1);
        printf("\n");

        printf("Inserire il secondo numero: \n");
        scanf("%d", &num2);
        printf("\n");

        printf("Inserire il terzo numero: \n");
        scanf("%d", &num3);
        printf("\n");

        
        if (num1 > num2 && num1 > num3)
        {
            max = num1;
        }
        else if (num2 > num1 && num2 > num3)
        {
            max = num2;
        }
        else if (num3 > num1 && num3 > num2)
        {
            max = num3;
        }

        if(num1 < num2 && num1 < num3)
        {
            min = num1;
        }
        else if(num2 < num1 && num2 < num3)
        {
            min = num2;
        }
        else if(num3 < num1 && num3 < num2)
        {
            min = num3;
        }

        //utilizzo della porta NAND
        if(!(num1 < num2 && num2 < num3))
        {
            printf("Il numero max è %d: \n",max);
            printf("Il numero min è %d: \n\n",min);
        }



    }while(num1 > 0 && num2 > 0 && num3 > 0);



    return 0;
}    