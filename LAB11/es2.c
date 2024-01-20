/* Jacobi_Priori (Esercizio 2)
data: 06/12/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'sistema.txt'.
        Dal file legge un intero positivo n, le componenti (double) di una matrice A nxn
        e di un vettore b di lunghezza n. Successivamente legge un double positivo toll.

Output: Il programma approssima la soluzione del sistema lineare Ax=b con il metodo
        di Jacobi (con criterio d'arresto a priori), infine stampa a schermo
        la soluzione approssimata ed il numero di iterazioni di Jacobi eseguite.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int Jacobi_priori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]);
double calc_lambda (int size, double mat[size][size], int n);

int main () {
    double A[MAX_DIM][MAX_DIM], b[MAX_DIM], x[MAX_DIM];
    int n, count;
    double toll;
    n = leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    printf("Inserire una tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);

    count = Jacobi_priori(MAX_DIM, A, b, n, toll, x);
    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Soluzione approssimata:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Numero di iterazioni: %d\n", count);

    return 0;
}

double calc_lambda (int size, double mat[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "calc_lambda: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    double sum, lambda = -1;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i)
                sum += fabs(mat[i][j]);
        }
        sum /= fabs(mat[i][i]);
        if (sum > lambda)
            lambda = sum;
    }

    return lambda;
}

int Jacobi_priori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]) {
    if (n > size) {
        fprintf(stderr, "Jacobi_priori: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    double lambda = calc_lambda(size, mat, n);
    double delta, temp;
    double prev[size];
    int iter = 0;
    int count = 0;
    delta = -1;
    for (int i = 0; i < n; i++) {
        temp = fabs(vec[i] / mat[i][i]);
        if (temp > delta)
            delta = temp; 
    }

    temp = delta / (1 - lambda);
    while (temp > toll) {
        temp *= lambda;
        iter++;
    }

    for (int i = 0; i < n; i++)
        prev[i] = 0;

    while (count < iter) {
        for (int i = 0; i < n; i++) {
            result[i] = vec[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    result[i] -= mat[i][j] * prev[j];
            }
            result[i] /= mat[i][i];
        }

        for (int i = 0; i < n; i++)
            prev[i] = result[i];

        count++;
    }

    return iter;
}
