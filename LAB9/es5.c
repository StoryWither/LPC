/* Esercizio 5
data: 22/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge un intero positivo n e successivamente le
        componenti (double) di due vettori v, u di lungehzza n.

Output: Il programma calcola il prodotto scalare tra i due vettori,
        poi stampa a video i due vettore e il loro prodotto scalare.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_DIM 100

int leggi_vettore (int size, double vec[size], int n);
int stampa_vettore (int size, double vec[size], int n);
double prodotto_scalare (int size, double vec1[size], double vec2[size], int n);

int main() { 
    double v[MAX_DIM], u[MAX_DIM];
    int n;
    double prod = 0;
    printf("Inserire numero di elementi n:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);
    printf("Inserire elementi di v:\n");
    leggi_vettore(MAX_DIM, v, n);
    printf("Inserire elementi di u:\n");
    leggi_vettore(MAX_DIM, u, n);

    prod = prodotto_scalare(MAX_DIM, v, u, n);
    printf("Vettore v:\n");
    stampa_vettore(MAX_DIM, v, n);
    printf("Vettore u:\n");
    stampa_vettore(MAX_DIM, u, n);
    printf("Prodotto scalare u * v: %lf\n", prod);

    return 0; 
}

double prodotto_scalare (int size, double vec1[size], double vec2[size], int n) {
    if (n > size) {
        fprintf(stderr, "prodotto_scalare: ERROR: spazio insufficiente\n");
        exit(1);
    }

    double result = 0;
    for (int i = 0; i < n; i++)
        result += vec1[i] * vec2[i];

    return result;
}

int leggi_vettore (int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "leggi_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        scanf("%lf", &vec[i]);

    return 0;
}

int stampa_vettore (int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "leggi_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        printf("%lf\n", vec[i]);

    return 0;
}
