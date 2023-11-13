#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535
#define maxM 100 


void f(int s, double a, double b, int m, int size, double fx[size]);
int findmax(int size, double fx[size], double a, double b, int m, int ind[size]);

int main () {
    int s, m, massimi;
    double a, b, delta;
    double fx[maxM];
    int indici[maxM];

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

    printf("Inserire gli estremi di un intervallo [a, b] su cui calcolare la funzione:\n");
    printf("Inserire a:");
    scanf("%lf", &a);
    printf("Inserire b:");
    do {
        scanf("%lf", &b);
    } while (b < a);
    
    printf("Inserire il numeri di punti equispaziati da calcolare:\n");
    do {
        scanf("%d", &m);
    } while (m < 1 || m > maxM);

    f(s, a, b, m, maxM, fx);
    massimi = findmax(maxM, fx, a, b, m, indici);
    printf("Valore massimo calcolato: %lf\n", fx[indici[0]]); 
    printf("Ascisse del massimo: ");
    delta = (b - a) / (m - 1);
    for (int i = 0; i < massimi; i++)
        printf("%.2lf, ", a + indici[i] * delta); 
    printf("\n");

    return 0;
}

void f(int s, double a, double b, int m, int size, double fx[size]) {
    if (m > size) {
        fprintf(stderr, "f: ERRORE: troppi punti, spazio array non sufficiente\n");
        exit(1);
    }
    double delta = (b - a) / (m - 1); 
    switch (s) {
        case 1:
            for (int i = 0; i < m; i++)
                fx[i] = sin(a + i * delta);
            break;
        case 2:
            for (int i = 0; i < m; i++)
                fx[i] = cos(a + i * delta);
            break;
        case 3:
            for (int i = 0; i < m; i++)
                fx[i] = exp(a + i * delta);
            break;
        case 4:
            for (int i = 0; i < m; i++)
                fx[i] = (a + i * delta) * (a + i * delta);
            break;
        case 5:
            for (int i = 0; i < m; i++)
                fx[i] = log(a + i * delta);
            break;
        case 6:
            for (int i = 0; i < m; i++)
                fx[i] = 1 / (a + i * delta);
            break;
        case 7:
            for (int i = 0; i < m; i++)
                fx[i] = (a + i * delta);
            break;
        default:
            printf("Scelta non valida\n");
            break;
    }
}

int findmax(int size, double fx[size], double a, double b, int m, int ind[size]) {
    if (m > size) {
        fprintf(stderr, "findmax: ERRORE: troppi punti, spazio array non sufficiente\n");
        exit(1);
    }
    int count = 0;
    double max = fx[0];

    for (int i = 0; i < m; i++) {
        if (fx[i] >= max) {
            if (fx[i] != max)
                count = 0;
            max = fx[i];
            ind[count] = i;
            count++;
        }
    }
    return count;
}
