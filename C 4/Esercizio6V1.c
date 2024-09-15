#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

    int estremo1, estremo2, numero;
    int cont = 0; 
    double media = 0;

    //controllo sul correto inserimento dei valore per gli estremi (estremo1 deve sempre essere minore di estremo 2)
    do
    {
        printf("Inserire il primo valore estremo: \n");
        scanf("%d",&estremo1);

        printf("Inserire il secondo valore estremo: \n");
        scanf("%d",&estremo2);

    }while(estremo1 > estremo2);
    
    
    do
    {   
        if (numero > estremo1 && numero < estremo2)
        {
            printf("Inserire il %d numero: \n",cont+1);
            scanf("%d", &numero);

            cont++;
            media = media + numero;
        }      
        
    } while (numero > estremo1 && numero < estremo2);

    media = media / (double) cont;

    printf("La media dei valori all'interno degli estremi %d - %d è: %.2f ",estremo1, estremo2, media);


    return 0;
}