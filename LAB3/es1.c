/* Esercizio 1
data: 11/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di valori limite per le variabili short e long
*/

#include <limits.h>
#include <stdio.h>

int main() {
    short smax = SHRT_MAX; 
    short smin = SHRT_MIN; 
    long lmax = LONG_MAX; 
    long lmin = LONG_MIN; 

    printf("Range della variabile short\n");
    printf("---------------------------------\n");
    printf("Massimo valore per la variabile int: %d\n", (short) smax);
    printf("Massimo valore per la variabile int+1: %d\n", (short) (smax + 1));
    printf("Prodotto: %d\n", (short) (smax * smax));
    printf("Minimo valore per la variabile int: %d\n", (short) smin);
    printf("Minimo valore per la variabile int-1: %d\n", (short) (smin - 1));
    printf("Minimo valore per la variabile int-2: %d\n", (short) (smin - 2));
    printf("Prodotto: % d\n\n", (short) (smin * smin));

    printf("Range della variabile long\n");
    printf("---------------------------------\n");
    printf("Massimo valore per la variabile long: %ld\n", lmax);
    printf("Massimo valore per la variabile long+1: %ld\n", lmax + 1);
    printf("Prodotto: %ld\n", lmax * lmax);
    printf("Minimo valore per la variabile long: %ld\n", lmin);
    printf("Minimo valore per la variabile long-1: %ld\n", lmin - 1);
    printf("Minimo valore per la variabile long-2: %ld\n", lmin - 2);
    printf("Prodotto: %ld\n", lmin * lmin);

    return 0;
}
