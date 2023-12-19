#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int Jacobi (int size, double mat[size][size], double vec[size], double sol[size], int n, int nmax, double toll, double result[size]);
int leggi_sistema_sol_file (int size, double mat[size][size], double vec[size], double sol[size], char *nomefile);

int main () {
    double A[MAX_DIM][MAX_DIM], b[MAX_DIM], x[MAX_DIM], x_esatta[MAX_DIM];
    int n, count, nmax;
    double toll;
    n = leggi_sistema_sol_file(MAX_DIM, A, b, x_esatta, "sistema_sol.txt");
    printf("Inserire numero massimo di iterazioni:\n");
    do {
        scanf("%d", &nmax);
    } while (nmax <= 0);

    printf("Inserire una tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);

    count = Jacobi(MAX_DIM, A, b, x_esatta, n, nmax, toll, x);
    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Soluzione approssimata:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Numero di iterazioni: %d\n", count);
    system("gnuplot << EOF\nplot \"convergenza.gp\"\npause mouse close\nEOF");

    return 0;
}

int Jacobi (int size, double mat[size][size], double vec[size], double sol[size], int n, int nmax, double toll, double result[size]) {
    if (n > size) {
        fprintf(stderr, "Jacobi: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    FILE* file = fopen("convergenza.gp", "w");

    double delta, temp;
    double prev[size];
    int count = 0;
    for (int i = 0; i < n; i++)
        prev[i] = 0;

    do {
        delta = -1;
        for (int i = 0; i < n; i++) {
            result[i] = vec[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    result[i] -= mat[i][j] * prev[j];
            }
            result[i] /= mat[i][i];
            temp = fabs(result[i] - sol[i]); 
            if (temp > delta)
                delta = temp;
        }

        fprintf(file, "%d %lf\n", count, delta);

        for (int i = 0; i < n; i++)
            prev[i] = result[i];

        count++;
    } while (count < nmax && delta > toll);

    fclose(file);

    return count;
}

int leggi_sistema_sol_file (int size, double mat[size][size], double vec[size], double sol[size], char *nomefile) {
    int n = 0;
    FILE *file = fopen(nomefile, "r");
    fscanf(file, "%d", &n);
    if (n > size) {
        fprintf(stderr, "leggi_sistema_sol_file: ERROR: spazio insufficiente\n");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fscanf(file, "%lf", &mat[i][j]);
    }

    for (int i = 0; i < n; i++)
        fscanf(file, "%lf", &vec[i]);

    for (int i = 0; i < n; i++)
        fscanf(file, "%lf", &sol[i]);

    fclose(file);
    return n;
}