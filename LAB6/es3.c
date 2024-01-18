/* Esercizio 3
data: 07/11/2023
autore: Sebastian Ferrigno
Input: Numero intero positivo n
Output: Il programma genera n componenti pseudo-random tra 1 e 100,
        i numeri pari e dispari vengono salvati in due vettori diversi
        che vengono successivamente stampati a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

int main () {
    srand(time(NULL));
    int n = 0;
    int u[Nmax], pari[Nmax], dispari[Nmax];
    int j = 0, k = 0;

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);

    for (int i = 0; i < n; i++) {
        u[i] = (rand() % 100) + 1;
        if (u[i] % 2 == 0)
            pari[j++] = u[i];
        else
            dispari[k++] = u[i];
    }

    /* printf("Componenti vettore u in ordine inverso:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", u[i]); */

    printf("Numeri pari:\n");
    for (int i = 0; i < j; i++)
        printf("%d\n", pari[i]);

    printf("Numeri dispari:\n");
    for (int i = 0; i < k; i++)
        printf("%d\n", dispari[i]);

    return 0;
}
