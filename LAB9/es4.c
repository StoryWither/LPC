#include <stdio.h>
#define MAX_DIM 100

int leggi_vettore (int size, double vec[size], int n);
int stampa_vettore (int size, double vec[size], int n);
int stampa_matrice(int size, double mat[size][size], int m, int n);
int leggi_matrice(int size, double mat[size][size], int m, int n);
int prodotto_matrice_vettore (int size, double mat[size][size], double vec[size], int m, int n, int p, double result[size]);

int main() { 
    double A[MAX_DIM][MAX_DIM];
    double v[MAX_DIM], u[MAX_DIM];
    int m, n, p;
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

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &p);
    } while (p < 1); 
    printf("Inserire componenti vettore:\n");
    leggi_vettore(MAX_DIM, v, p);

    if (prodotto_matrice_vettore(MAX_DIM, A, v, m, n, p, u) != 1) {
        printf("Matrice A:\n");
        stampa_matrice(MAX_DIM, A, m, n);
        printf("Vettore v:\n");
        stampa_vettore(MAX_DIM, v, p);
        printf("Prodotto u = Av\n");
        stampa_vettore(MAX_DIM, u, m);
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

int leggi_vettore (int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "leggi_vettore: ERROR: spazio insufficiente\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        scanf("%lf", &vec[i]);

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
