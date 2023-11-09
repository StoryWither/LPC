#include <stdio.h>

int main () {
    int n, fact;
    long ln, lfact;
    float fn, ffact;
    double dn ,dfact;

    printf("Inserire valore di n:\n");
    do {
        scanf("%d", &n);
    } while (n < 0);
    ln = (long) n;
    fn = (float) n;
    dn = (double) n;

    fact = 1;
    lfact = 1;
    ffact = 1;
    dfact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
        lfact *= i;
        ffact *= i;
        dfact *= i;
    }

    printf("Fattoriale calcolato in diversi tipi:\n");
    printf("Int: %d\n", fact);
    printf("Long: %ld\n", lfact);
    printf("Float: %f\n", ffact);
    printf("Double: %lf\n", dfact);

    return 0;
}
