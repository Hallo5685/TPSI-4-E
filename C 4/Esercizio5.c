#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int num1, num2, num3;
    int differrenza = 0;
    int contdispari = 0, contzero = 0, contpari = 0;

    do
    {   
        //il primo scanf chiede un doppio inserimento 
        printf("Inserire il primo numero: \n");
        scanf("%d\n\n", &num1);
        
        printf("Inserire il secondo numero: \n");
        scanf("%d\n\n", &num2);

        printf("Inserire il terzo numero; \n");
        scanf("%d\n\n", &num3);

        differrenza = num1 - num2;

        if(differrenza % 2 == 0)
        {
            contpari++;
        }
        else if (differrenza % 2 != 0)
        {
            contdispari++;
        }
        else if (differrenza == 0)
        {
            contzero++;
        }
        

    } while (num1 + num2 >= num3);
    
    printf("Le volte in cui A - B era pari: %d\n", contpari);
    printf("Le volte in cui A - B era dispari: %d\n", contdispari);
    printf("Le volte in cui A - B era zero: %d\n", contzero);

    return 0;
}
