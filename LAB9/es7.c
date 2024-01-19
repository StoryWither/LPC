/* Esercizio 7
data: 22/11/2023
autore: Sebastian Ferrigno
Input: Un intero positivo n.
Output: Il programma genera una matrice triangolare superiore nxn di
        componenti pseudo-random reali tra 0 e 100.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int gen_mat_triangolare_sup (int size, double mat[size][size], int n);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    int n;
    printf("Inserire la dimensinoe di A:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);

    gen_mat_triangolare_sup(MAX_DIM, A, n);
    printf("Matrice triangolare superiore generata:\n");
    stampa_matrice(MAX_DIM, A, n, n);

    return 0; 
}

int gen_mat_triangolare_sup (int size, double mat[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_mat_triangolare_sup: ERROR: spazio insufficiente\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for(int j = i; j < n; j++) 
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

