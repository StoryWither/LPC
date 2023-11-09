#include <stdio.h>

int main() {
    int n, sum1, sum2;
    printf("Inserire un numero positivo n\n");
    do { 
        scanf("%d", &n);
    } while (n < 0);

    sum1 = 0;
    for (int i = 2; i <= 2*n; i += 2) 
        sum1 += i;

    sum2 = n * (n+1);
    
    printf("Somma con il ciclo for: %d\n", sum1);
    printf("Somma con la formula: %d\n", sum2);

    return 0;
}
