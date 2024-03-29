/* Esercizio 2
data: 25/10/2023
autore: Sebastian Ferrigno
Input: Numero intero positivo n
Output: Somma dei primi n numeri al quadrato calcolata in due modi diversi
*/

#include <stdio.h>

int main () {
    int n, sum1, sum2;
    do {
        scanf("%d", &n);
    } while (n < 0);

    sum1 = 0; 
    for (int i = 1; i <= n; i++)
        sum1 += i * i;

    sum2 = (n * (n+1) * (2*n+1)) / 6; 

    printf("Somma dei quadrati con il ciclo for: %d\n", sum1);
    printf("Somma dei quadrati con la formula: %d\n", sum2); 

    return 0;
}
