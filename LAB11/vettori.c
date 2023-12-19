#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "vettori.h"

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

int copia_vettore (int size, double vec[size], double cpy[size], int n) {
    if (n > size) {
        fprintf(stderr, "copia_vettore: ERRROR: spazio insufficiente\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        cpy[i] = vec[i];

    return 0;
}
