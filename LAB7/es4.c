#include <stdio.h>
#include <stdlib.h>
#define Nmax 100
int leggi_array(int size, int arr[size], int n);
int max_array(int size, int arr[size], int n, int indici[size]);

int main () {
    int n, ind;
    int array[Nmax], indici[Nmax];
    printf("Inserire lunghezza array:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);
    printf("Inserire valori array:\n");
    leggi_array(Nmax, array, n);
    ind = max_array(Nmax, array, n, indici);
    printf("Massimo dell'array: %d\n", array[indici[0]]);
    printf("Indici del massimo: ");
    for (int i = 0; i < ind; i++)
        printf("%d, ", indici[i]);
    printf("\n");

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

int max_array(int size, int arr[size], int n, int indici[size]) {
    if (n > size) {
        fprintf(stderr, "max_array: ERRORE: n tropo grande\n");
        exit(1);
    }

    int max = arr[0];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= max) {
            if (arr[i] != max)
                count = 0;
            max = arr[i];
            indici[count] = i;
            count++;
        }
    }
    return count;
}
