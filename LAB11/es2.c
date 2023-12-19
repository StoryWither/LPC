#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int Jacobi_posteriori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]);
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

    count = Jacobi_posteriori(MAX_DIM, A, b, n, toll, x);
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

int Jacobi_posteriori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]) {
    if (n > size) {
        fprintf(stderr, "Jacobi_posteriori: ERROR: spazio non sufficiente\n");
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