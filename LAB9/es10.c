/* Esercizio 10
data: 22/11/2023
autore: Sebastian Ferrigno
Input: Un intero positivo n.
Output: Il programma genera due matrici triangolari inferiori nxn con
        componenti pseudo-random reali tra 0 e 100. Il programma calcola
        il prodotto tra le due matrici con un algoritmo ottimizzato per
        le matrici triangolari inferiori. Il prodotto e` ancora una matrice
        triangolare inferiore e il conto di operazioni (moltiplicazioni)
        asintotico e` (n^3)/6 (quello del prodotto tra matrici normali e` n^3).
        Infine il programma stampa le due matrici generate ed il loro prodotto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int gen_mat_triangolare_inf (int size, double mat[size][size], int n);
int prod_mat_triangolari_inf (int size, double mat1[size][size], double mat2[size][size], int n, double result[size][size]);

int main() { 
    double A[MAX_DIM][MAX_DIM], B[MAX_DIM][MAX_DIM], C[MAX_DIM][MAX_DIM];
    int n;
    printf("Inserire la dimensione di A:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);

    gen_mat_triangolare_inf(MAX_DIM, A, n);
    gen_mat_triangolare_inf(MAX_DIM, B, n);
    prod_mat_triangolari_inf(MAX_DIM, A, B, n, C);
    printf("Matrice triangolare inferiore A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Matrice triangolare inferiore B:\n");
    stampa_matrice(MAX_DIM, B, n, n);
    printf("Matrice C = AB\n");
    stampa_matrice(MAX_DIM, C, n, n);

    return 0; 
}

int prod_mat_triangolari_inf (int size, double mat1[size][size], double mat2[size][size], int n, double result[size][size]) {
    if (n > size) {
        fprintf(stderr, "prod_mat_triangolari_inf: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            result[i][k] = 0;
            for (int j = k; j <= i; j++)
                result[i][k] += mat1[i][j] * mat2[j][k];
        }
    }

    return 0;
}

int gen_mat_triangolare_inf (int size, double mat[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_mat_triangolare_sup: ERROR: spazio insufficiente\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for(int j = 0; j <= i ; j++) 
            mat[i][j] = (rand() % 10001) / 100.0; 

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
