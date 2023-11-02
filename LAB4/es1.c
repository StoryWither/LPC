/* Esercizio 1
   data: 18/10/2023
   autore: Sebastian Ferrigno
   Input: Numero intero k
   Output: Stampa a schermo della parità o disparità di k
*/

#include <stdio.h>

int main() {
    int k;
    printf("Inserire un numero intero:\n");
    scanf("%d", &k);
    if (k % 2 == 0)
        printf("%d e' pari\n", k);
    else
        printf("%d e' dispari\n", k);

    return 0;
}
