#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"

#define MAX_DIM 100

int inverti_matrice_gauss (int size, double mat[size][size], double matInv[size][size], int n);
int copia_matrice (int size, double mat[size][size], double cpy[size][size], int m, int n);

int main () {
    double A[MAX_DIM][MAX_DIM], Acpy[MAX_DIM][MAX_DIM], Ainv[MAX_DIM][MAX_DIM];
    int n;
    leggi_matrice_file(MAX_DIM, A, &n, &n, "mat.txt");
    copia_matrice(MAX_DIM, A, Acpy, n, n);

    if (inverti_matrice_gauss(MAX_DIM, A, Ainv, n) == 1) {
        printf("Matrice non invertibile\n");
        return 0;
    }
    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, Acpy, n, n);
    printf("Matrice A^-1:\n");
    stampa_matrice(MAX_DIM, Ainv, n, n);
    prodotto_matrici(MAX_DIM, Acpy, Ainv, n, n, n, n, A);
    printf("Prodotto AA^-1\n");
    stampa_matrice(MAX_DIM, A, n, n);


    return 0;
}


int inverti_matrice_gauss (int size, double mat[size][size], double matInv[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "inverti_matrice_gauss: ERROR: spazio insufficiente\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        matInv[i][i] = 1;

    double mult = 0;
    int imax = 0;
    double temp = 0;

    for (int k = 0; k < n; k++) { 
        imax = k;
        for (int i = k + 1; i < n; i++)
            if (fabs(mat[i][k]) > fabs(mat[imax][k]))
                imax = i;

        if (mat[imax][k] == 0)
            return 1;

        if (imax != k) {
            for (int j = k; j < n; j++) {
                temp = mat[imax][j];
                mat[imax][j] = mat[k][j];
                mat[k][j] = temp;
            }
            for (int j = 0; j < n; j++) {
                temp = matInv[imax][j];
                matInv[imax][j] = matInv[k][j];
                matInv[k][j] = temp;
            }
        }

        for (int i = k + 1; i < n; i++) {
            mult = mat[i][k] / mat[k][k];

            for (int j = k + 1; j < n; j++)
                mat[i][j] -= mult * mat[k][j];

            for (int j = 0; j < n; j++)
                matInv[i][j] -= mult * matInv[k][j];
        }
    }

    for (int k = n - 1; k >= 0; k--) { 
        for (int i = k - 1; i >= 0; i--) {
            mult = mat[i][k] / mat[k][k];
            for (int j = 0; j < n; j++)
                matInv[i][j] -= mult * matInv[k][j];
        }
        for (int j = 0; j < n; j++)
            matInv[k][j] /= mat[k][k];
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
