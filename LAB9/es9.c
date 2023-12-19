#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_DIM 100

int stampa_matrice(int size, double mat[size][size], int m, int n);
int gen_mat_triangolare_sup (int size, double mat[size][size], int n);
int sostituzioni_indietro (int size, double mat[size][size], double vec[size], double result[size], int n);
int stampa_vettore (int size, double vec[size], int n);
int gen_vettore (int size, double vec[size], int n);
int calcolo_residui (int size, double mat[size][size], double vec[size], double sol[size], double res[size], int n);
double max_vec_abs(int size, double vec[size], int n);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    double b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    int n;
    double max_res_abs;
    printf("Inserire la dimensione di A:\n");
    do {
        scanf("%d", &n);
    } while (n < 1);

    gen_mat_triangolare_sup(MAX_DIM, A, n);
    gen_vettore(MAX_DIM, b, n);
    sostituzioni_indietro(MAX_DIM, A, b, x, n);
    calcolo_residui(MAX_DIM, A, b, x, r, n);
    max_res_abs = max_vec_abs(MAX_DIM, r, n);

    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Risultato dell'equazione Ax = b\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Vettore dei residui r = b - Ax\n");
    stampa_vettore(MAX_DIM, r, n);
    printf("Massimo (in valore assoluto) dei residui: %lf\n", max_res_abs);

    return 0; 
}

int calcolo_residui (int size, double mat[size][size], double vec[size], double sol[size], double res[size], int n) {
    if (n > size) {
        fprintf(stderr, "calcolo_residui: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        res[i] = vec[i];
        for (int j = i; j < n; j++)
            res[i] -=  mat[i][j] * sol[j];
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

double max_vec_abs(int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "max_array: ERRORE: spazio insufficiente\n");
        exit(1);
    }

    double max = fabs(vec[0]);
    for (int i = 0; i < n; i++)
        if (fabs(vec[i]) > max)
            max = fabs(vec[i]);

    return max;
}

int gen_mat_triangolare_sup (int size, double mat[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_mat_triangolare_sup: ERROR: spazio insufficiente\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for(int j = i; j < n; j++) 
            mat[i][j] = (rand() % 10001) / 1000.0; 

    return 0;
}

int gen_vettore (int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vec[i] = (rand() % 10001) / 1000.0;

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

int stampa_vettore (int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "leggi_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        printf("%lf\n", vec[i]);

    return 0;
}
