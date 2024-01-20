#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int fattorizzazione_PA_LU (int size, double P[size][size], double U[size][size], double L[size][size], int n);
int copia_matrice (int size, double mat[size][size], double cpy[size][size], int m, int n);
int prodotto_LU (int size, double L[size][size], double U[size][size], double prod[size][size], int n);

int main () {
    int n;
    double A[MAX_DIM][MAX_DIM], P[MAX_DIM][MAX_DIM], U[MAX_DIM][MAX_DIM], L[MAX_DIM][MAX_DIM], Prod[MAX_DIM][MAX_DIM];
    double Prod2[MAX_DIM][MAX_DIM];

    leggi_matrice_file(MAX_DIM, A, &n, &n, "mat.txt");
    copia_matrice(MAX_DIM, A, U, n, n);

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);

    if (fattorizzazione_PA_LU(MAX_DIM, P, U, L, n) == 1) {
        printf("Fattorizzazione fallita\n");
        return 0;
    }
    printf("Matrice P:\n");
    stampa_matrice(MAX_DIM, P, n, n);
    printf("Matrice L:\n");
    stampa_matrice(MAX_DIM, L, n, n);
    printf("Matrice U:\n");
    stampa_matrice(MAX_DIM, U, n, n);
    prodotto_LU(MAX_DIM, L, U, Prod, n);
    printf("Matrice Prod = LU\n");
    stampa_matrice(MAX_DIM, Prod, n, n);
    prodotto_matrici(MAX_DIM, P, A, n, n, n, n, Prod2);
    printf("Matrice Prod = PA\n");
    stampa_matrice(MAX_DIM, Prod2, n, n);
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (fabs(Prod2[i][j] - Prod[i][j]) > 1e-3)
                printf("Numero:%d, Righa:%d, Colonna:%d", count++, i, j);
    if (count == 0)
        printf("PA = LU\n");
    else
        printf("PA != LU\n");

    return 0;
}

int fattorizzazione_PA_LU (int size, double P[size][size], double U[size][size], double L[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "fattorizzazione_PA_LU: ERROR: spazio insufficiente\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        P[i][i] = 1;

    double mult = 0;
    double temp;
    int imax = 0;

    for (int k = 0; k < n; k++) { 
        imax = k;
        for (int i = k + 1; i < n; i++)
            if (fabs(U[i][k]) > fabs(U[imax][k]))
                imax = i;

        if (U[imax][k] == 0)
            return 1;

        if (imax != k) {
            for (int j = k; j < n; j++) {
                temp = U[imax][j];
                U[imax][j] = U[k][j];
                U[k][j] = temp;
            }
            for (int j = 0; j < n; j++) {
                temp = P[imax][j];
                P[imax][j] = P[k][j];
                P[k][j] = temp;
            }
        }

        L[k][k] = 1;
        for (int i = k + 1; i < n; i++) {
            mult = U[i][k] / U[k][k];
            L[i][k] = mult;

            for (int j = k + 1; j < n; j++)
                U[i][j] -= mult * U[k][j];
        }
    }

    return 0;
}

int prodotto_LU (int size, double L[size][size], double U[size][size], double prod[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "prodotto_LU: ERROR: spazio insufficiente\n");
        return 1;
    }

    int min = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            prod[i][k] = 0;
            min = i < k ? i : k;
            for (int j = 0; j <= min; j++)
                prod[i][k] += L[i][j] * U[j][k];
        }
    }

    return 0;
}

int copia_matrice (int size, double mat[size][size], double cpy[size][size], int m, int n) {
    if (n > size || m > size) {
        fprintf(stderr, "copia_matrice: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cpy[i][j] = mat[i][j];

    return 0;
}
