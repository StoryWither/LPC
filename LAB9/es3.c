#include <stdio.h>
#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int leggi_matrice(int size, double mat[size][size], int m, int n);
int scambia_righe (int size, double mat[size][size], int m, int n, int p, int q);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    int m, n, p, q;
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

    printf("Inserire numero della prima riga da scambiare\n");
    do {
        scanf("%d", &p);
    } while (p < 1 || p > m);

    printf("Inserire numero della seconda riga da scambiare\n");
    do {
        scanf("%d", &q);
    } while (q < 1 || q > m);


    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, m, n);

    scambia_righe(MAX_DIM, A, m, n, p, q);
    printf("Matrice A con righe scambiate:\n");
    stampa_matrice(MAX_DIM, A, m, n);

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
