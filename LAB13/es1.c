#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double f (int scelta, double x);
int crea_griglia (double left, double right, int n, int size, double nodes[size]);

int main () {
    int s;
    double a, b, toll;
    double x, fx;
    printf("Scegliere una funzione dal menu:\n");
    printf("1) sin(x)\n");
    printf("2) ln(x)\n");
    printf("3) e^x\n");
    printf("4) x^5 + 3x^4 + 2x^3 - x^2 -5x + 1\n");
    printf("5) 1 / (1 + x^2)\n");
    printf("6) |x|\n");
    printf("7) sin(x^2)\n");
    printf("8) |sin(x^2)|\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 8);

    printf("Inserire l'estremo sinistro:\n");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro:\n");
    scanf("%lf", &b);
    printf("Inserire la tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);
    printf("Radice approssimata: %lf\n", x);
    printf("Residuo: %lf\n", fx);

    return 0;
}

int crea_griglia (double left, double right, int n, int size, double nodes[size]) {
    if (n > size) {
        fprintf(stderr, "crea_griglia: ERROR: spazio insufficiente\n");
        return 1;
    }

    double h = (right - left) / n;
    for (int i = 0; i <= n; i++)
        nodes[i] = left + i * h;
    
    return 0;
}

double f (int scelta, double x) {
    double a;
    switch(scelta) {
    case 1:
        return sin(x);
        break;
    case 2:
        return log(x);
        break;
    case 3:
        return exp(x);
        break;
    case 4:
        return x*x*x*x*x + 3*x*x*x*x + 2*x*x*x + - x*x - 5*x + 1;
        break;
    case 5:
        return 1 / (1 + x*x);
        break;  
    case 6:
        return fabs(x);
        break;  
    case 7:
        return sin(x*x);
        break;  
    case 8:
        return fabs(sin(x*x));
        break;  
    default:
        fprintf(stderr, "f: ERROR: scelta non valida\n");
        exit(1);
        break;
    }
}
