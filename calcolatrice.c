#include <stdio.h>
#include <stdlib.h>
#include "calcolatrice.h"

double somma(double a, double b)
{
    return a + b;
}

double sottrazione(double a, double b)
{
    return a - b;
}
double moltiplicazione(double a, double b)
{
    return a * b;
}
double divisione(double a, double b)
{
    if (b == 0) {
        printf("Errore: divisione per zero\n");
        return 0;
    }
    return a / b;
}

/*int main(int argc, char* argv[])
{
    double a, b;
    printf("Inserisci il primo numero: ");
    scanf("%lf", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%lf", &b);

    printf("Somma: %.2f\n", somma(a, b));
    printf("Sottrazione: %.2f\n", sottrazione(a, b));
    printf("Moltiplicazione: %.2f\n", moltiplicazione(a, b));
    printf("Divisione: %.2f\n", divisione(a, b));

    return 0;
}*/