/* Esercizio 5
data: 25/10/2023
autore: Sebastian Ferrigno
Input: Un intero positivo n e un intero positivo k <= n
Output: Il risultato del calcolo del coefficiente binomiale "n su k" in al piu' Nmax cicli 
*/

#include <stdio.h>
#define Nmax 100
#define toll 1

int main() {
    int n, k, coe, prev_coe;
    printf("Consideri un coefficiente binomiale nella forma:\n");
    printf(" / n \\\n");
    printf("|     |\n");
    printf(" \\ k /\n");
    printf("Inserire un valore positivo per n:\n");
    do {
        scanf("%d", &n);
    } while (n < 0);
    printf("Inserire un valore di k minore o uguale di n:\n");
    do {
        scanf("%d", &k);
    } while (k < 0 || k > n);

    coe = 1;
    prev_coe = -toll;
    if (k >= n - k) {
        for (int i = 1; i <= n - k && n < Nmax && coe - prev_coe > toll; i++) {
            prev_coe = coe;
            coe *= (k + i) / i;
        }
    } else if (k < n - k) {
        for (int i = 1; i <= k && n < Nmax && coe - prev_coe > toll; i++) {
            prev_coe = coe;
            coe *= (n - k + i) / i;
        }
    }

    printf("Il valore del coefficiente binomiale e' %d\n", coe);

    return 0;
}
