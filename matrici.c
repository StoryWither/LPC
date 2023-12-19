#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrici.h"

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

int trasponi_matrice (int size, double mat[size][size], double tras[size][size], int m, int n) {
    if (m > size || n > size) {
        fprintf(stderr, "trasponi_matrice: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            tras[j][i] = mat[i][j];
    }
     
    return 0;
}

int scambia_righe (int size, double mat[size][size], int m, int n, int p, int q) {
    if (m > size || n > size) {
        fprintf(stderr, "scambia_righe: ERROR: spazio insufficiente\n");
        return 1;
    }

    double temp[n];

    for (int j = 0; j < n; j++) {
        temp[j] = mat[q - 1][j];
        mat[q - 1][j] = mat[p - 1][j];
        mat[p - 1][j] = temp[j];
    }
     
    return 0;
}

int prodotto_matrice_vettore (int size, double mat[size][size], double vec[size], int m, int n, int p, double result[size]) {
    if (m > size || n > size || p > size) {
        fprintf(stderr, "prodotto_matrice_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }
    if (n != p) {
        fprintf(stderr, "prodotto_matrice_vettore: ERORR: dimensioni non compatibili\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++)
            result[i] += mat[i][j] * vec[j];
    }
     
    return 0;
}

int prodotto_matrici (int size, double mat1[size][size], double mat2[size][size], int m, int n, int p, int q, double result[size][size]) {
    if (m > size || n > size || p > size || q > size) {
        fprintf(stderr, "prodotto_matrici: ERROR: spazio insufficiente\n");
        return 1;
    }
    if (n != p) {
        fprintf(stderr, "prodotto_matrici: ERORR: dimensioni non compatibili\n");
        return 1;
    }

    for (int k = 0; k < q; k++) {
        for (int i = 0; i < m; i++) {
            result[i][k] = 0;
            for (int j = 0; j < n; j++)
                result[i][k] += mat1[i][j] * mat2[j][k];
        }
    }
     
    return 0;
}

int sostituzioni_indietro (int size, double mat[size][size], double vec[size], double result[size], int n) {
    if (n > size) {
        fprintf(stderr, "sostituzioni_indietro: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        result[i] = vec[i];
        for (int j = n - 1; j > i; j--)
            result[i] -= result[j] * mat[i][j]; 
        result[i] /= mat[i][i];
    }

    return 0;
}

int calcolo_residui (int size, double mat[size][size], double vec[size], double sol[size], double res[size], int n) {
    if (n > size) {
        fprintf(stderr, "calcolo_residui: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        res[i] = vec[i];
        for (int j = 0; j < n; j++)
            res[i] -=  mat[i][j] * sol[j];
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
