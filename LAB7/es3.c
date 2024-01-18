/* Esercizio 3
data: 08/11/2023
autore: Sebastian Ferrigno
Input: Un intero positivo n <= 100 e n numeri interi che vengono salvati in un array.
Output: Massimo dell'array.
*/

#include <stdio.h>
#include <stdlib.h>
#define Nmax 100
int leggi_array(int size, int arr[size], int n);
int max_array(int size, int arr[size], int n);

int main () {
    int n, max;
    int array[Nmax];
    printf("Inserire lunghezza array:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);
    printf("Inserire valori array:\n");
    leggi_array(Nmax, array, n);
    max = max_array(Nmax, array, n);
    printf("Massimo dell'array: %d\n", max);

    return 0;
}

int leggi_array(int size, int arr[size], int n) {
    if (n > size) {
        fprintf(stderr, "leggi_array: ERRORE: n tropo grande\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
   return 0; 
}

int max_array(int size, int arr[size], int n) {
    if (n > size) {
        fprintf(stderr, "max_array: ERRORE: n tropo grande\n");
        exit(1);
    }

    int max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}
