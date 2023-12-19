#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int fattorizzazione_LU (int size, double U[size][size], double L[size][size], int n);
int elim_gauss_pivoting (int size, double mat[size][size], double vec[size], int n);
int sostituzioni_avanti (int size, double mat[size][size], double vec[size], double result[size], int n);
int copia_vettore (int size, double vec[size], double cpy[size], int n);

int main () {
    int n, scelta;
    double H[MAX_DIM][MAX_DIM], U[MAX_DIM][MAX_DIM], L[MAX_DIM][MAX_DIM];
    double b[MAX_DIM], b_cpy[MAX_DIM], x[MAX_DIM], y[MAX_DIM], r[MAX_DIM];
    printf("Inserire dimensione della matrice di Hilbert:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > MAX_DIM);

    printf("Inserire il vettore b:\n");
    leggi_vettore(MAX_DIM, b, n);
    printf("Scegliere il metodo di risoluzione del sistema\n");
    printf("1) Eliminazinoe gaussiana con sostituzione all'indietro\n");
    printf("2) Fattorizzazione LU con doppia sostituzione\n");
    do {
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            H[i][j] = 1.0 / ((i + 1) + (j + 1) - 1);
            U[i][j] = H[i][j];
        }
    }

    if (scelta == 1) {
        copia_vettore(MAX_DIM, b, b_cpy, n);
        if (elim_gauss_pivoting(MAX_DIM, U, b, n) == 1) {
            printf("Sistema incompatibile\n");
            return 0;
        }
        sostituzioni_indietro(MAX_DIM, U, b, x, n);
        calcolo_residui(MAX_DIM, H, b_cpy, x, r, n);

    } else {
        if (fattorizzazione_LU(MAX_DIM, U, L, n) == 1) {
            printf("Fattorizzazione fallita\n");
            return 0;
        }
        sostituzioni_avanti(MAX_DIM, L, b, y, n);
        sostituzioni_indietro(MAX_DIM, U, y, x, n);
        calcolo_residui(MAX_DIM, H, b, x, r, n);
    }

    printf("Matrice H:\n");
    stampa_matrice(MAX_DIM, H, n, n);
    printf("Soluzione sistema\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Vettore residui\n");
    stampa_vettore(MAX_DIM, r, n);

    return 0;
}

int fattorizzazione_LU (int size, double U[size][size], double L[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "fattorizzazione_LU: ERROR: spazio insufficiente\n");
        exit(1);
    }

    double mult = 0;

    for (int k = 0; k < n; k++) { 
        if (U[k][k] == 0)
            return 1;

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

int sostituzioni_avanti (int size, double mat[size][size], double vec[size], double result[size], int n) {
    if (n > size) {
        fprintf(stderr, "sostituzioni_avanti: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        result[i] = vec[i];
        for (int j = 0; j < i; j++)
            result[i] -= result[j] * mat[i][j]; 
        result[i] /= mat[i][i];
    }

    return 0;
}

int elim_gauss_pivoting (int size, double mat[size][size], double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "elim_gauss: ERROR: spazio insufficiente\n");
        exit(1);
    }

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
            temp = vec[imax];
            vec[imax] = vec[k];
            vec[k] = temp;
        }

        for (int i = k + 1; i < n; i++) {
            mult = mat[i][k] / mat[k][k];

            for (int j = k + 1; j < n; j++)
                mat[i][j] -= mult * mat[k][j];
            vec[i] -= mult * vec[k];
        }
    }

    return 0;
}

int copia_vettore (int size, double vec[size], double cpy[size], int n) {
    if (n > size) {
        fprintf(stderr, "copia_vettore: ERRROR: spazio insufficiente\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        cpy[i] = vec[i];

    return 0;
}
