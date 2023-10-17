/* Programma 1
data: 04/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di valori di risultati di operazioni con variabili
floating point
*/

// Per la compilazione con gcc usare "gcc nomefile.c -lm"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, c, d;

    a = 5;
    b = exp(1);
    c = 1 / 2;
    d = 1.0 / 2;

    printf("La somma di a + b = %lf \n", a + b);
    printf("Il prodotto a * c = %lf \n", a * c);
    printf("Il rapporto a * d = %lf \n", a * d);

    return 0;
}
