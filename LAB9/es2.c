#include <stdio.h>
#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int leggi_matrice(int size, double mat[size][size], int m, int n);
int trasponi_matrice (int size, double mat[size][size], double tras[size][size], int m, int n);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    double A_tras[MAX_DIM][MAX_DIM];
    int m, n;
    printf("Inserire il numero di righe:\n");
    do {
        scanf("%d", &m);
    } while (m < 1);

    printf("Inserire il numero di colonne:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);
    
    printf("Inserire le componenti della matrice:\n");
    leggi_matrice(MAX_DIM, A, m, n);
    trasponi_matrice(MAX_DIM, A, A_tras, m, n);

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, m, n);
    printf("Trasposta di A:\n");
    stampa_matrice(MAX_DIM, A_tras, n, m);

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
