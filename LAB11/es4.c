/* Esercizio 4
data: 06/12/2023
autore: Sebastian Ferrigno
Input: Il programma legge un intero positivo n per generare una matrice tridiagonale
        A nxn, poi legge un double positivo toll.

Output: Il programma approssima la soluzione del sistema lineare Ax=b con il metodo
        di Jacobi ottimizzato per matrici tridiagonali.
        Infine stampa a schermo la matrice A, il vettore b, la soluzione approssimata 
        il numero di iterazioni ed il massimo dei residui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int Jacobi_tridiagonale (int size, double mat[size][size], double vec[size], int n, double toll, double result[size]);

int main () {
    double A[MAX_DIM][MAX_DIM], b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    int n, count;
    double toll, res;
    printf("Inserire la dimensione della matrice tridiagonale:\n");
    do {
        scanf("%d", &n);
    } while (n <= 0);

    printf("Inserire una tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);

    gen_vettore(MAX_DIM, b, n);
    for (int i = 0; i < n; i++) {
        A[i][i - 1] = -1;
        A[i][i] = 2;
        A[i][i + 1] = -1;
    }

    count = Jacobi_tridiagonale(MAX_DIM, A, b, n, toll, x);
    calcolo_residui(MAX_DIM, A, b, x, r, n);
    res = max_vec_abs(MAX_DIM, r, n);
    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Soluzione approssimata:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Numero di iterazioni: %d\n", count);
    printf("Massimo dei residui: %lf\n", res);

    return 0;
}

int Jacobi_tridiagonale (int size, double mat[size][size], double vec[size], int n, double toll, double result[size]) {
    if (n > size) {
        fprintf(stderr, "Jacobi_tridiagonale: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    double delta, temp;
    double prev[size];
    int count = 0;
    for (int i = 0; i < n; i++)
        prev[i] = 0;

    do {
        delta = -1;
        for (int i = 0; i < n; i++) {
            result[i] = vec[i] - mat[i][i - 1] * prev[i - 1] - mat[i][i + 1] * prev[i + 1];
            result[i] /= mat[i][i];
            temp = fabs(result[i] - prev[i]); 
            if (temp > delta)
                delta = temp;
        }

        for (int i = 0; i < n; i++)
            prev[i] = result[i];

        count++;
    } while (count < 1000 && delta > toll);

    return count;
}
