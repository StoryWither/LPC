#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double f (int scelta, double x);
int crea_griglia (double left, double right, int n, int size, double nodes[size]);
double intpol_laplace (int size, double nodes[size], int n, int scelta, double x);

int main () {
    int s, n, m;
    double a, b, z, pz, max, res;
    double griglia[Nmax];
    FILE* file = fopen("punti.gp", "w");
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
    printf("Inserire il numero di nodi di interpolazione:\n");
    do {
        scanf("%d", &n);
    } while (n <= 0);
    printf("Inserire il numero di punti da interpolare:\n");
    do {
        scanf("%d", &m);
    } while (m <= 0);
    crea_griglia(a, b, n, Nmax, griglia); 

    double h = (b - a) / (m + 1);
    max = -1;
    for (int i = 1; i <= m; i++) {
        z = a + i * h;
        pz = intpol_laplace(Nmax, griglia, n, s, z);
        fprintf(file, "%lf %lf\n", z, pz);
        res = fabs(f(s, z) - pz);
        max = max < res ? res : max;
    }

    fclose(file);
    system("gnuplot << EOF\nplot sin(x), \"punti.gp\"\npause mouse close\nEOF");
    printf("Massimo residui: %lf\n", max);

    return 0;
}

double intpol_laplace (int size, double nodes[size], int n, int scelta, double x) {
    if (n > size) {
        fprintf(stderr, "intpol_laplace: ERROR: spazio insufficiente\n");
        return 1;
    }

    double li;
    double pol = 0;
    for (int i = 0; i <= n; i++) {
        li = 1;
        for (int j = 0; j <= n; j++) {
            if (j != i)
                li *= (x - nodes[j]) / (nodes[i] - nodes[j]);
        }
        pol += li * f(scelta, nodes[i]);
    }

    return pol;
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
