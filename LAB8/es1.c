#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

int stampa_vettore(int size, double vec[size], int n);
int leggi_vettore_file(FILE* f, int size, double vec[size]);

int main () {
    FILE* f;
    double vec[MAX_DIM];
    int n = 0;
    f = fopen("vettore.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "ERROR: main: errore nell'apertura del file\n");
    }

    n = leggi_vettore_file(f, MAX_DIM, vec);
    fclose(f);

    stampa_vettore(MAX_DIM, vec, n);

    return 0;
}

int leggi_vettore_file(FILE* f, int size, double vec[size]) {
    int n = 0;
    fscanf(f, "%d", &n);
    if (n > size) {
        fprintf(stderr, "ERROR: leggi_vettore_file: n troppo grande\n");
        fclose(f);
        exit(1);
    }

    for (int i = 0; i < n; i++)
        fscanf(f, "%lf", &vec[i]);

    return n;
}

int stampa_vettore(int size, double vec[size], int n) {
    if (n > size) {
        fprintf(stderr, "ERROR: stampa_vettore: n troppo grande\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        printf("%.2lf\n", vec[i]);


    return 0;
}
