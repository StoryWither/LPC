/* Esercizio 1
data: 07/11/2023
autore: Sebastian Ferrigno
Input: Numero intero positivo n
Output: Vettore di n componenti pseudo-random stampate a video in ordine inverso
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

int main () {
    srand(time(NULL));
    int n = 0;
    int u[Nmax];
    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);
    for (int i = 0; i < n; i++)
        u[i] = rand();

    printf("Componenti vettore u in ordine inverso:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", u[i]);



    return 0;
}
