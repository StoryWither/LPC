#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Nmax 100

int crivello_eratostene (int* arr, int size, int n); 
int scomposizione (int* arr, int size, int n); 

int main () {
    int n = 0;
    int primi[Nmax]; 
    int check;
    printf("Inserire un intero positivo maggiore di 2:\n");
    do {
        scanf("%d", &n);
    } while (n < 2 || n > Nmax);

    crivello_eratostene(primi, Nmax, n);
    scomposizione(primi, Nmax, n);

    check = 0;
    printf("Scomposizione di %d in fattori primi:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primi[i] != 0) {
            if (check != 0) {
                printf(" * %d^%d", i, primi[i]);
            } else {
                printf("%d^%d", i, primi[i]);
                check = 1;
            }
        }
    }
    printf("\n");

    return 0;
}

int crivello_eratostene (int* arr, int size, int n) {
    if (n > size - 1) {
        fprintf(stderr, "crivello_eratostene: ERRORE: n troppo grande\n");
        return 1;
    }

    int rootN = sqrt(n);
    arr[2] = 1;
    for (int i = 3; i <= n; i += 2)
        arr[i] = 1;

    int i = 3;
    do {
        for (int j = i*i; j <= n; j += i)
            arr[j] = 0;
        do {
            i++;
        } while (arr[i] == 0);
    } while (i <= rootN);

    return 0;
}

int scomposizione (int* arr, int size, int n) {
    if (n > size - 1) {
        fprintf(stderr, "scomposizione: ERRORE: n troppo grande\n");
        return 1;
    }

    int i = 2; 
    int copy = n;
    do {
        arr[i] = 0;
        while (copy % i == 0) {
            arr[i]++;
            copy /= i;
        }
        do {
            i++;
        } while (arr[i] == 0 && i <= n);
    } while (copy > 1);

    while (i <= n)
        arr[i++] = 0;

    return 0;
}
