/* Fattorizzazione_LU (Esercizio 4)
data: 29/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'mat.txt',
        Dal file legge un intero positivo n e le componenti di una matrice A nxn.

Output: Il programma esegue la fattorizzazione LU sulla matrice A con il metodo di
        eliminazione gaussiana (senza pivoting), in seguito stampa a video le matrici
        L e U e il loro prodotto P = LU. Infine verificha se P == LU e stama a video
        il risultato del controllo.
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int fattorizzazione_LU (int size, double U[size][size], double L[size][size], int n);
int copia_matrice (int size, double mat[size][size], double cpy[size][size], int m, int n);
int prodotto_LU (int size, double L[size][size], double U[size][size], double prod[size][size], int n);

int main () {
    int n;
    double A[MAX_DIM][MAX_DIM], U[MAX_DIM][MAX_DIM], L[MAX_DIM][MAX_DIM], P[MAX_DIM][MAX_DIM];

    leggi_matrice_file(MAX_DIM, A, &n, &n, "mat.txt");
    copia_matrice(MAX_DIM, A, U, n, n);

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);

    if (fattorizzazione_LU(MAX_DIM, U, L, n) == 1) {
        printf("Fattorizzazione fallita\n");
        return 0;
    }

    printf("Matrice L:\n");
    stampa_matrice(MAX_DIM, L, n, n);
    printf("Matrice U:\n");
    stampa_matrice(MAX_DIM, U, n, n);
    prodotto_LU(MAX_DIM, L, U, P, n);
    printf("Matrice P = LU\n");
    stampa_matrice(MAX_DIM, P, n, n);
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != P[i][j])
                count++;
    if (count == 0)
        printf("A = LU\n");
    else
        printf("A != LU\n");

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
