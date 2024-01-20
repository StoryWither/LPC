/* Elimingazione_Gaussiana_Pivoting (Esercizio 3)
data: 29/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'sistema.txt',
        oppure genera i dati in maniera pseud-random.
        Dal file legge un intero positivo n, le componenti (double) di una matrice A nxn
        e di un vettore b di lunghezza n.

Output: Il programma risolve il sistema lineare Ax=b con il metodo di eliminazione gaussiana
        (con pivoting parziale per righe) + sostitzuioni all'indietro, calcola il vettore 
        dei residui r = b - Ax, infine stampa a video la soluzione del sistema e il 
        massimo dei residui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int elim_gauss_pivoting (int size, double mat[size][size], double vec[size], int n);
int leggi_sistema_file (int size, double mat[size][size], double vec[size], char *nomefile);
int gen_matrice(int size, double mat[size][size], int m, int n);

int main () {
    int n, scelta;
    double A[MAX_DIM][MAX_DIM];
    double b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    double rmax;

    printf("Scegliere tra le seguenti opzioni:\n");
    printf("1: Leggere il sistema da file\n");
    printf("2: Generare la dimensione, la matrice e il vettore in maniera random\n");
    do {
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);

    if (scelta == 1) {
        n = leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    } else {
        n = (rand() % MAX_DIM) + 1;
        gen_matrice(MAX_DIM, A, n, n);
        gen_vettore(MAX_DIM, b, n);
    }

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);

    if (elim_gauss_pivoting(MAX_DIM, A, b, n) == 1) {
        printf("Sistema incompatibile\n");
        return 0;
    }

    sostituzioni_indietro(MAX_DIM, A, b, x, n);
    if (scelta == 1)
        leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    rmax = max_vec_abs(MAX_DIM, r, n);

    printf("Vettore della soluzione approssimata di Ax = b:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Massimo dei residui: %lf\n", rmax);

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

int gen_matrice(int size, double mat[size][size], int m, int n) {
    if (n > size || m > size) {
        fprintf(stderr, "gen_matrice: ERROR: spazio insufficiente\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = (rand() % 10001) / 1000.0;

    return 0;
}
