/* Esercizio 2
data: 07/11/2023
autore: Sebastian Ferrigno
Input: Numero intero positivo n
Output: Viene generato un vettore di n componenti pseudo-random compresi tra 1 e n,
        viene trovata la componente massima in modulo e viene stampata a video
        assieme al suo indice.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

int main () {
    srand(time(NULL));
    int n = 0;
    int u[Nmax], max[Nmax];
    int j = 0;
    max[0] = 0;

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);

    for (int i = 0; i < n; i++) {
        u[i] = (rand() % n) + 1;
        if (u[i] >= u[max[0]]) {
            if (u[i] != u[max[0]])
                j = 0;
            max[j] = i;
            j++;
        }
    }

    /* printf("Componenti vettore u in ordine inverso:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", u[i]); */

    printf("Valore massimo: %d\n", u[max[0]]);
    printf("Indici:\n");
    for (int i = 0; i < j; i++)
        printf("%d\n", max[i]);

    return 0;
}
