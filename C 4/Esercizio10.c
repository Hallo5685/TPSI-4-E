#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main ()
{
    //dichiarazione di stringa 
    char start [50];
    //dichiarazione di valori che conterranno le MEDIE
    double mediaBevande = 0, mediaRistorazione = 0;

    int sceltaConsumato, importoBevande, importoRistorazione, sommaBevande, sommaRistorazione; 
    int contaBevande = 0, contaRistorazione = 0;

    do
    {
        printf("Selezionare cosa è stato ordinato: 1 - Bevande || 2 - Risotarazione \n");
        scanf("%d", &sceltaConsumato);

        //controllo su inserimento di BEVANDE o RISTORAZIONE
        if(sceltaConsumato == 1 )
        {
            contaBevande++;
            printf("Inserire l'importo delle bevande: \n");
            scanf("%d", &importoBevande);
            sommaBevande = mediaBevande + importoBevande;
        }
        else if(sceltaConsumato == 2 )
        {
            contaRistorazione++;
            printf("Inserire l'importo delle bevande: \n");
            scanf("%d", &importoRistorazione);
            sommaRistorazione = mediaRistorazione + importoRistorazione;
        }
        
        //inserimento della Stringa START
        printf("Per uscire dal softwere scrivere 'esci': ");
        scanf("%s", start);

    } while (start != "esci");
    
    //calcolo dei valori delle MEDIE
    mediaBevande = (double) sommaBevande / (double) contaBevande;
    mediaRistorazione = (double) sommaRistorazione / (double) contaRistorazione;

    //stampa delle MEDIE
    printf("L'incasso medio delle Bevande: %d \n",importoBevande);
    printf("L'incasso medio delle Ristorazione: %d \n",importoRistorazione);
    
    //stampa del servizio più veduto
    if(contaBevande > contaRistorazione)
    {
        printf("Sono state vendute più bevande ");
    }
    else if(contaBevande < contaRistorazione)
    {
        printf("Sono state vendute più ristorazioni ");
    }
    else
    {
        printf("Sono state vendute lo stesso numero di bevande e ristorazioni ");
    }


    return 0;
}