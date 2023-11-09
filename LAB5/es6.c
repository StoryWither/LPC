#include <stdio.h>

int main () {
    int n;
    double x, max, min;
    printf("Inserire un intero positivo:\n");
    do {
        scanf("%d", &n);
    } while (n < 0);

    printf("Inserire %d numeri reali:\n", n);
    scanf("%lf", &x);
    max = x;
    min = x;

    for (int i = 1; i < n; i++) {
        scanf("%lf", &x);
        max = x > max ? x : max;
        min = x < min ? x : min;
    }

    printf("Il massimo dei valori inseriti e': %lf\n", max);
    printf("Il minimo dei valori inseriti e': %lf\n", min);

    return 0;
}
