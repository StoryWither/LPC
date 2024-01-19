/* Esercizio 1
data: 22/11/2023
autore: Sebastian Ferrigno
Input: Il programma legge i file di input da un file di testo chiamato 'matrice.txt'.
        Il file deve contenere due interi positivi m e n nella prima riga e 
        le componenti (double) della matrice nelle righe successive.

Output: Il programma stampa a video la matrice del file.
*/

#include <stdio.h>
#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int stampa_matrice_file(int size, double mat[size][size], int m, int n, char *nomefile);
int leggi_matrice_file(int size, double mat[size][size], int* m, int* n, char *nomefile);
int leggi_matrice(int size, double mat[size][size], int m, int n);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    int m = 0;
    int n = 0;
    if (leggi_matrice_file(MAX_DIM, A, &m, &n, "matrice.txt") == 1)
        return 1;

    stampa_matrice(MAX_DIM, A, m, n);

    return 0; 
}

int stampa_matrice(int size, double mat[size][size], int m, int n) {
    if (m > size || n > size) {
        fprintf(stderr, "stampa_matrice: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2lf ", mat[i][j]);
        printf("\n");
    }

    return 0;
}

int stampa_matrice_file(int size, double mat[size][size], int m, int n, char *nomefile) {
    if (m > size || n > size) {
        fprintf(stderr, "stampa_matrice_file: ERROR: spazio insufficiente\n");
        return 1;
    }

    FILE *file = fopen(nomefile, "w");
    fprintf(file, "%d %d\n", m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fprintf(file, "%lf ", mat[i][j]);
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

int leggi_matrice_file(int size, double mat[size][size], int* m, int* n, char *nomefile) {
    FILE *file = fopen(nomefile, "r");
    fscanf(file, "%d", m);
    fscanf(file, "%d", n);

    if (*m > size || *n > size) {
        fprintf(stderr, "leggi_matrice_file: ERROR: spazio insufficiente\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++)
            fscanf(file, "%lf", &mat[i][j]);
    }

    return 0;
}

int leggi_matrice(int size, double mat[size][size], int m, int n) {
    if (m > size || n > size) {
        fprintf(stderr, "leggi_matrice: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);
    }

    return 0;
}
