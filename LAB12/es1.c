#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double bisezione (double left, double right, int scelta, double toll, int max_iter);
double f (int scelta, double x);

int main () {
    int s;
    double a, b, toll;
    double x, fx;
    printf("Scegliere una funzione dal menu:\n");
    printf("1) e^x - 1\n");
    printf("2) x^3 - 8\n");
    printf("3) cos(x)\n");
    printf("4) arctan(x)\n");
    printf("5) sin(3x)\n");
    printf("6) ln(1 + x)\n");
    printf("7) e^(-x^2) - 1/2\n");
    printf("8) (1 - x^2)^2\n");
    printf("9) x^3 - 2x^2 +3x - 1\n");
    printf("10) |x^3 - x + 1|\n");
    printf("11) x^5 + 3x^4 + 2x^3 -x^2 -5x +1\n");
    printf("12) 1/(1 + x^2) - 0.3\n");
    printf("13) |2x| - 1\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 13);

    printf("Inserire l'estremo sinistro:\n");
    scanf("%lf", &a);
    printf("Inserire l'estremo destro:\n");
    scanf("%lf", &b);
    printf("Inserire la tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);
    x = bisezione(a, b, s, toll, Nmax);
    fx = f(s, x); 
    printf("Radice approssimata: %lf\n", x);
    printf("Residuo: %lf\n", fx);


    return 0;
}


double bisezione (double left, double right, int scelta, double toll, int max_count) {
    double fleft = f(scelta, left);
    if (fleft == 0)
        return left;

    double fright = f(scelta, right);
    if (fright == 0)
        return right;

    if (toll <= 0 || max_count <= 0 || fleft * fright > 0) {
        fprintf(stderr, "bisezione: ERROR: parametri di input non validi\n");
        exit(1);
    }

    double middle, fmiddle;
    int count = 0;

    do {
       middle = (left + right) / 2;
       fmiddle = f(scelta, middle);

       if (fmiddle == 0) {
           return middle;
       } else if (fleft * fmiddle < 0) {
           right = middle;
           fright = fmiddle;
       } else {
           left = middle;
           fleft = fmiddle;
       } 

       count++;
    } while ((right - left > toll || fabs(fmiddle) > toll) && count < max_count);

    if (count >= max_count) {
        printf("bisezione: Il metodo non converge (a meno della tolleranza richiesta) in %d iterazioni\n", max_count);
        exit(0);
    }

    return (left + right) / 2;
}

double f (int scelta, double x) {
    double a;
    switch(scelta) {
    case 1:
        return exp(x) - 1;
        break;
    case 2:
        return (x * x * x - 8);
        break;
    case 3:
        return cos(x);
        break;
    case 4:
        return atan(x);
        break;
    case 5:
        return sin(3*x);
        break;  
    case 6:
        return log(1 + x);
        break;  
    case 7:
        return exp(-x * x) - 0.5;
        break;  
    case 8:
        return (1- x*x) * (1 - x*x);
        break;  
    case 9:
        return x*x*x - 2*x*x + 3*x -1;
        break;  
    case 10:
        return fabs(x*x*x -x + 1);
        break;  
    case 11:
        return x*x*x*x*x + 3*x*x*x*x + 2*x*x*x - x*x - 5*x + 1;
        break;  
    case 12:
        return 1 / (1 + x*x) - 0.3;
        break;
    case 13:
        return fabs(2*x) - 1;
        break;
    default:
        fprintf(stderr, "f: ERROR: scelta non valida\n");
        exit(1);
        break;
    }
}