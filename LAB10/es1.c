/* Eliminazione_Gaussiana (Esercizio 1)
data: 29/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'sistema.txt'.
        Dal file legge un intero positivo n, le componenti (double) di una matrice A nxn
        e di un vettore b di lunghezza n.

Output: Il programma risolve il sistema lineare Ax=b con il metodo di eliminazione gaussiana
        (senza pivoting) + sostitzuioni all'indietro, calcola il vettore dei residui r = b - Ax,
        infine stampa a video la soluzione del sistema e il massimo dei residui.
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int elim_gauss (int size, double mat[size][size], double vec[size], int n);
int leggi_sistema_file (int size, double mat[size][size], double vec[size], char *nomefile);

int main () {
    int n;
    double A[MAX_DIM][MAX_DIM];
    double b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    double rmax;

    n = leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);

    if (elim_gauss(MAX_DIM, A, b, n) == 1) {
        printf("Sistema incompatibile\n");
        return 0;
    }

    sostituzioni_indietro(MAX_DIM, A, b, x, n);
    leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    calcolo_residui(MAX_DIM, A, b, x, r, n);
    rmax = max_vec_abs(MAX_DIM, r, n);

    printf("Vettore della soluzione approssimata di Ax = b:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Massimo dei residui: %lf\n", rmax);

    return 0;
}

int elim_gauss (int size, double mat[size][size], double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "elim_gauss: ERROR: spazio insufficiente\n");
        exit(1);
    }

    double mult = 0;

    for (int k = 0; k < n; k++) { 
        if (mat[k][k] == 0)
            return 1;
        for (int i = k + 1; i < n; i++) {
            mult = mat[i][k] / mat[k][k];
            for (int j = k + 1; j < n; j++)
                mat[i][j] -= mult * mat[k][j];
            vec[i] -= mult * vec[k];
        }
    }

    return 0;
}

int leggi_sistema_file (int size, double mat[size][size], double vec[size], char *nomefile) {
    int n = 0;
    FILE *file = fopen(nomefile, "r");
    fscanf(file, "%d", &n);
    if (n > size) {
        fprintf(stderr, "leggi_matrice_file: ERROR: spazio insufficiente\n");
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
