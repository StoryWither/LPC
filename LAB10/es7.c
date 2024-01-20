/* Esercizio 7 
data: 29/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'sistema.txt',
        Dal file legge un intero positivo n, le componenti di una matrice A nxn e di
        un vettore b di lunghezza n. Si presuppone che la matrice A sia tridiagonale.

Output: Il programma risolve il sistema lineare Ax = b con versione ottimizzate del MEG
        e delle sostituzioni all'indietro per matrici tridiagonali. Il costo operazioni
        (moltiplicazioni e divisioni) asintotico e` 5n.
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int elim_gauss_tridiagonale (int size, double mat[size][size], double vec[size], int n);
int leggi_sistema_file (int size, double mat[size][size], double vec[size], char *nomefile);
int sost_indietro_tridiagonale (int size, double mat[size][size], double vec[size], double result[size], int n);

int main () {
    int n;
    double A[MAX_DIM][MAX_DIM];
    double b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    double rmax;

    n = leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");


    if (elim_gauss_tridiagonale(MAX_DIM, A, b, n) == 1) {
        printf("Sistema incompatibile\n");
        return 0;
    }

    sost_indietro_tridiagonale(MAX_DIM, A, b, x, n);
    leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    calcolo_residui(MAX_DIM, A, b, x, r, n);
    rmax = max_vec_abs(MAX_DIM, r, n);

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Vettore della soluzione approssimata di Ax = b:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Massimo dei residui: %lf\n", rmax);

    return 0;
}

int elim_gauss_tridiagonale (int size, double mat[size][size], double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "elim_gauss_tridiagonale: ERROR: spazio insufficiente\n");
        exit(1);
    }
    double mult = 0;

    for (int k = 0; k < n; k++) {
        if (mat[k][k] == 0)
            return 1;
        mult = mat[k + 1][k] / mat[k][k];
        mat[k + 1][k + 1] -= mult * mat[k][k+1];
        vec[k + 1] -= mult * vec[k];
    }

    return 0;
}

int sost_indietro_tridiagonale (int size, double mat[size][size], double vec[size], double result[size], int n) {
    if (n > size) {
        fprintf(stderr, "sost_indietro_tridiagonale: ERROR: spazio insufficiente\n");
        return 1;
    }

    result[n - 1] = vec[n - 1] / mat[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result[i] = vec[i];
        result[i] -= result[i + 1] * mat[i][i + 1]; 
        result[i] /= mat[i][i];
    }

    return 0;
}

int leggi_sistema_file (int size, double mat[size][size], double vec[size], char *nomefile) {
    int n = 0;
    FILE *file = fopen(nomefile, "r");
    fscanf(file, "%d", &n);
    if (n > size) {
        fprintf(stderr, "leggi_sistema_file: ERROR: spazio insufficiente\n");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fscanf(file, "%lf", &mat[i][j]);
    }

    for (int i = 0; i < n; i++)
        fscanf(file, "%lf", &vec[i]);

    fclose(file);
    return n;
}
