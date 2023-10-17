/* Esercizio 4
data: 04/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di una tabella contenente diversi valori numerici
*/

#include <math.h>
#include <stdio.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

int main() {
    int n[5] = {2, 10, 20, -10, -20};
    printf("n\t cos(n)\t e^n\n\n");
    for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++)
        printf("%d\t %lf\t %lf\n", n[i], cos(n[i]), exp(n[i]));

    return 0;
}
