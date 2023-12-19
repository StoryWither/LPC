#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double f (int scelta, double x);
double df(int scelta, double x);
double newton (int n, double toll, int max_count, double arr[max_count], int* count);
double secanti (int n, double toll, int max_count, double arr[max_count], int* count);

int main () {
    int n, nnewt, nsec, max;
    double newt[Nmax], sec[Nmax], toll;
    printf("Inserire n:\n");
    do {
        scanf("%d", &n);
    } while (n < 0);
    printf("Inserire la tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);
    newton(n, toll, Nmax, newt, &nnewt);
    secanti(n, toll, Nmax, sec, &nsec);
    max = nnewt > nsec ? nnewt : nsec;
    printf("Iter\t Newton\t\t Secanti\n");
    for (int i = 0; i < max; i++)
        printf("%d\t %lf\t %lf\n", i, newt[i], sec[i]);
   
    return 0;
}

double newton (int n, double toll, int max_count, double arr[max_count], int* count) {
    if (toll <= 0 || max_count <= 0) {
        fprintf(stderr, "newton: ERROR: parametri di input non validi\n");
        exit(1);
    }

    double sqrtn = sqrt(n);
    double x = n;
    double fx = x*x - n; 
    double phix = x - fx / (2*x); 


    *count = 0;
    while ((((x + toll/2) * (x + toll/2) - n) * ((x - toll/2) * (x-toll/2) - n) > 0 || fabs(fx) > toll) && *count < max_count) {
        arr[*count] = x - sqrtn;
        x = phix;
        fx = x*x - n;
        phix = x - fx / (2*x);
        (*count)++;
    }

    if (*count >= max_count) {
        printf("newton: Il metodo non converge (a meno della tolleranza richiesta) in %d iterazioni\n", max_count);
        exit(0);
    }

    return x;
}

double secanti (int n, double toll, int max_count, double arr[max_count], int* count) {
    if (toll <= 0 || max_count <= 0) {
        fprintf(stderr, "secanti: ERROR: parametri di input non validi\n");
        exit(1);
    }

    double sqrtn = sqrt(n);
    double prevx = n;
    double prevf = prevx * prevx - n;
    double x = n - 0.1;
    double fx = x*x - n;
    double phix = (prevx * fx - x * prevf) / (fx - prevf); 

    *count = 0;
    while ((((x + toll/2) * (x + toll/2) - n) * ((x - toll/2) * (x-toll/2) - n) > 0 || fabs(fx) > toll) && *count < max_count) {
        arr[*count] = x - sqrtn;
        prevx = x;
        prevf = fx;
        x = phix;
        fx = x*x - n;
        phix = (prevx * fx - x * prevf) / (fx - prevf); 
        (*count)++;
    }

    if (*count >= max_count) {
        printf("secanti: Il metodo non converge (a meno della tolleranza richiesta) in %d iterazioni\n", max_count);
        exit(0);
    }

    return x;
}
