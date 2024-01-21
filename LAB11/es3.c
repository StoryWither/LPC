/* Esercizio 3
data: 06/12/2023
autore: Sebastian Ferrigno
Input: Il programma legge un intero s per scegliere il modo in cui genereare il
        sistema lineare da risolvere. Nel caso s==1, legge anche i dati del
        sistema dal file 'sistema.txt'. Successivamente legge un double positivo toll.

Output: Il programma approssima la soluzione del sistema lineare Ax=b con il metodo
        di Jacobi (con criterio d'arresto a priori), infine stampa a schermo la 
        matrice A, il vettore b, la soluzione approssimata ed il massimo dei residui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrici.h"
#include "vettori.h"
#define MAX_DIM 100

int Jacobi_priori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]);
double calc_lambda (int size, double mat[size][size], int n);

int main () {
    double A[MAX_DIM][MAX_DIM], b[MAX_DIM], x[MAX_DIM], r[MAX_DIM];
    int n, count, scelta;
    double toll, sum, res;
    srand(time(NULL));
    printf("Scegliere tra le seguenti opzioni per generare il sistema:\n");
    printf("1) Lettura sistema da file\n"); 
    printf("2) Matrice e termine noto random\n"); 
    printf("3) Matrice D.D.R.S e termine noto random\n"); 
    do {
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta  != 2 && scelta != 3);
    if (scelta == 1) {
        n = leggi_sistema_file(MAX_DIM, A, b, "sistema.txt");
    } else if (scelta == 2) {
        n = (rand() % 50) + 1;
        gen_matrice(MAX_DIM, A, n, n);
        gen_vettore(MAX_DIM, b, n);
    } else if (scelta == 3) {
        n = (rand() % 50) + 1;
        gen_vettore(MAX_DIM, b, n);
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    A[i][j] = (rand() % 10001) / 100.0;
                    sum += A[i][j];
                }
            }
            A[i][i] = sum + 1 + (rand() % 10001 / 100.0); 
        }
    }
    
    printf("Inserire una tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);

    count = Jacobi_priori(MAX_DIM, A, b, n, toll, x);
    calcolo_residui(MAX_DIM, A, b, x, r, n);
    res = max_vec_abs(MAX_DIM, r, n);
    printf("Matrice A:\n");
    stampa_matrice(MAX_DIM, A, n, n);
    printf("Vettore b:\n");
    stampa_vettore(MAX_DIM, b, n);
    printf("Soluzione approssimata:\n");
    stampa_vettore(MAX_DIM, x, n);
    printf("Massimo dei residui: %lf\n", res);


    return 0;
}

double calc_lambda (int size, double mat[size][size], int n) {
    if (n > size) {
        fprintf(stderr, "calc_lambda: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    double sum, lambda = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i)
                sum += fabs(mat[i][j]);
        }
        sum /= fabs(mat[i][i]);
        if (sum > lambda)
            lambda = sum;
    }

    return lambda;
}

int Jacobi_priori(int size, double mat[size][size], double vec[size], int n, double toll, double result[size]) {
    if (n > size) {
        fprintf(stderr, "Jacobi_priori: ERROR: spazio non sufficiente\n");
        exit(1);
    }

    double lambda = calc_lambda(size, mat, n);
    double delta, temp;
    double prev[size];
    int iter = 0;
    int count = 0;
    delta = 0;
    for (int i = 0; i < n; i++) {
        temp = fabs(vec[i] / mat[i][i]);
        if (temp > delta)
            delta = temp; 
    }


    temp = delta / (1 - lambda);
    while (temp > toll) {
        temp *= lambda;
        iter++;
    }

    for (int i = 0; i < n; i++)
        prev[i] = 0;

    while (count < iter) {
        for (int i = 0; i < n; i++) {
            result[i] = vec[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    result[i] -= mat[i][j] * prev[j];
            }
            result[i] /= mat[i][i];
        }

        for (int i = 0; i < n; i++)
            prev[i] = result[i];

        count++;
    }

    return iter;
}
