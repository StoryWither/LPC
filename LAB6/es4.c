/* Esercizio 4
data: 07/11/2023
autore: Sebastian Ferrigno
Input: Un numero intero positivo n ed n numeri interi
Output: Il programma suddivide i numeri letti in quattro vettori:
        - Vettore A: Numeri dispari
        - Vettore B: Multipli di 4 
        - Vettore C: Multipli di 10
        - Vettore D: Tutti gli altri
        Il programma stampa a video i contenuti dei 4 vettori oppure dichiara se sono vuoti
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

int main () {
    srand(time(NULL));
    int n = 0;
    int u[Nmax], A[Nmax], B[Nmax], C[Nmax], D[Nmax];
    int a = 0, b = 0, c = 0, d = 0;

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);

    printf("Inserire elementi interi del vettore:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", u + i);
        if (u[i] % 2 != 0) {
            A[a++] = u[i];
        } else if (u[i] % 4 == 0 || u[i] % 10 == 0) { 
            if (u[i] % 4 == 0)
                B[b++] = u[i];
            if (u[i] % 10 == 0)
                C[c++] = u[i];
        } else {
            D[d++] = u[i];
        }
    }

    /* printf("Componenti vettore u in ordine inverso:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", u[i]); */

    if(a != 0) {
        printf("Vettore A:\n");
        for (int i = 0; i < a; i++)
            printf("%d\n", A[i]);
    } else {
        printf("Il vettore A e' vuoto\n");
    }

    if(b != 0) {
        printf("Vettore B:\n");
        for (int i = 0; i < b; i++)
            printf("%d\n", B[i]);
    } else {
        printf("Il vettore B e' vuoto\n");
    }

    if(c != 0) {
        printf("Vettore C:\n");
        for (int i = 0; i < c; i++)
            printf("%d\n", C[i]);
    } else {
        printf("Il vettore C e' vuoto\n");
    }

    if(d != 0) {
        printf("Vettore D:\n");
        for (int i = 0; i < d; i++)
            printf("%d\n", D[i]);
    } else {
        printf("Il vettore D e' vuoto\n");
    }

    return 0;
}
