/* Programma 2
data: 04/10/2023
autore: Sebastian Ferrigno
Input: Due variabili di tipo double
Output: Somma, prodotto e quoziente delle variabili in input
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b;

    printf("Inserisci a \n");
    scanf("%lf", &a);
    printf("Inserisci b \n");
    scanf("%lf", &b);

    printf("La somma di a + b = %lf \n", a + b);
    printf("Il prodotto a * b = %lf \n", a * b);
    printf("Il quoziente a / b = %lf \n", a / b);

    return 0;
}
