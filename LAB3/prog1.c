/* Programma 1
data: 11/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di valori limite per la variabile int
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Range della variabile intera\n");
    printf("---------------------------------\n");

    int n1 = INT_MAX; // maximum range di integer
    int n2 = INT_MIN; // minimum range di integer

    printf("Massimo valore per la variabile int: %d\n", n1);
    printf("Massimo valore per la variabile int+1: %d\n", n1 + 1);
    printf("Prodotto: %d\n", n1 * n1);
    printf("Minimo valore per la variabile int: %d\n", n2);
    printf("Minimo valore per la variabile int-1: %d\n", n2 - 1);
    printf("Minimo valore per la variabile int-2: %d\n", n2 - 2);
    printf("Prodotto: % d\n", n2 * n2);

    return 0;
}
