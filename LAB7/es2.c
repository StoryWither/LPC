#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535
#define maxM 100

double f(int s, double a, double b, double x);
double findMax (int s, double a, double b, int m, int size, double ascisse[size], int* ind);

int main() {
    int s, m, massimi;
    double a, b, delta, max;
    double ascisse[maxM];

    printf("Scegliere una funzione:\n");
    printf("1) sin(x)\n");
    printf("2) cos(x)\n");
    printf("3) e^x\n");
    printf("4) x^2\n");
    printf("5) ln(x)\n");
    printf("6) 1/x\n");
    printf("7) x\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 7);

    printf("Inserire gli estremi di un intervallo [a, b] su cui calcolare la "
           "funzione:\n");
    printf("Inserire a:");
    scanf("%lf", &a);
    printf("Inserire b:");
    do {
        scanf("%lf", &b);
    } while (b < a);

    printf("Inserire il numero di punti equispaziati da calcolare:\n");
    do {
        scanf("%d", &m);
    } while (m < 2 || m > maxM);

    max = findMax(s, a, b, m, maxM, ascisse, &massimi);
    printf("Valore massimo calcolato: %lf\n", max);
    printf("Ascisse del massimo: ");
    delta = (b - a) / (m - 1);
    for (int i = 0; i < massimi; i++)
        printf("%.2lf, ", ascisse[i]);
    printf("\n");

    return 0;
}

double f(int s, double a, double b, double x) {
    double result = INFINITY;

    switch (s) {
    case 1:
        if (x >= a && x <= b)
            result = cos(x);
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 2:
        if (x >= a && x <= b)
            result = sin(x);
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 3:
        if (x >= a && x <= b)
            result = exp(x);
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 4:
        if (x >= a && x <= b)
            result = x * x;
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 5:
        if (x > 0 && x >= a && x <= b)
            result = log(x);
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 6:
        if (x != 0 && x >= a && x <= b)
            result = 1 / x;
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    case 7:
        if (x >= a && x <= b)
            result = x ;
        else
            fprintf(stderr, "WARNING: f: Valore fuori range\n");
        break;
    default:
        fprintf(stderr, "WARNING: f: Scelta non valida\n");
        break;
    }

    return result;
}

double findMax (int s, double a, double b, int m, int size, double ascisse[size], int* ind) {
    double delta = (b - a) / (m - 1);
    double fx = 0;
    double max = 0;

    int j = 0;
    for (int i = 0; i < m; i++) {
        fx = f(s, a, b, a + delta * i);
        if(fx >= max) {
            if (fx > max) {
                max = fx;
                j = 0;
            } 
            ascisse[j] = a + delta * i;
            j++;
        }
    }

    *ind = j;
    return max;
}
