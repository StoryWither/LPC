#include <stdio.h>
#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int leggi_matrice(int size, double mat[size][size], int m, int n);
int prodotto_matrici (int size, double mat1[size][size], double mat2[size][size], int m, int n, int p, int q, double result[size][size]);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    double B[MAX_DIM][MAX_DIM];
    double C[MAX_DIM][MAX_DIM];
    int m, n, p, q;
    printf("Inserire il numero di righe di A:\n");
    do {
        scanf("%d", &m);
    } while (m < 1);

    printf("Inserire il numero di colonne A:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);
    printf("Inserire le componenti della matrice A:\n");
    leggi_matrice(MAX_DIM, A, m, n);

    printf("Inserire il numero di righe di B:\n");
    do {
        scanf("%d", &p);
    } while (m < 1);

    printf("Inserire il numero di colonne B:\n");
    do {
        scanf("%d", &q);
    } while (n < 1);
    printf("Inserire le componenti della matrice B:\n");
    leggi_matrice(MAX_DIM, B, p, q);
    

    if (prodotto_matrici(MAX_DIM, A, B, m, n, p, q, C) != 1) {
        printf("Matrice A:\n");
        stampa_matrice(MAX_DIM, A, m, n);
        printf("Matrice B:\n");
        stampa_matrice(MAX_DIM, B, p, q);
        printf("Prodotto C = AB\n");
        stampa_matrice(MAX_DIM, C, m, q);
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

