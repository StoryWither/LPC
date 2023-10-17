/* Esercizio 2
data: 04/10/2023
autore: Sebastian Ferrigno
Input: Due numeri reali x e y
Output: Somma, differenza, prodotto e quoziente delle variabili di input
*/

#include <stdio.h>

int main() {
    float x, y;

    printf("Inserire valore di x:\n");
    scanf("%f", &x);
    printf("Inserire valore di y:\n");
    scanf("%f", &y);

    printf("Somma di x + y = %f\n", x + y);
    printf("Differenza di x - y = %f\n", x - y);
    printf("Prodotto di x * y = %f\n", x * y);
    printf("Quoziente di x / y = %f\n", x / y);

    return 0;
}
