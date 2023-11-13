#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

double dot_prod(int size, double v1[size], double v2[size], int n);
int gen_array(int size, double arr[size], int n);

int main () {
    int n;
    double v1[Nmax], v2[Nmax];
    double prod;
    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);
    gen_array(Nmax, v1, n);
    gen_array(Nmax, v2, n);
    prod = dot_prod(Nmax, v1, v2, n);
    printf("Prodotto scalare di v1 e v2: %lf\n", prod);


    return 0;
}

double dot_prod(int size, double v1[size], double v2[size], int n) {
    if (n > size) {
        fprintf(stderr, "dot_prod: ERRORE: n troppo grande\n");
        exit(1);
    }

    double result = 0;
    for (int i = 0; i < n; i++) 
        result += v1[i] * v2[i];

    return result;
}

int gen_array(int size, double arr[size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_array: ERRORE: n troppo grande\n");
        return 1;
    }
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
        arr[i] = ((rand() % 2000) / 1000.0) - 1;

    return 0;
}


