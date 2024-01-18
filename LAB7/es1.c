/* Esercizio 1
data: 08/11/2023
autore: Sebastian Ferrigno
Input: Il programma stampa un menu' con una scelta di 8 funzioni con intervalli associati,
        in input il programma legge un intero s corrispondente alla scelta ed numero reale x.

Output: Se il numero x appartiene all'intervallo specificato nel menu', allora viene calcolato
        e stampato a video il valore della funzione scelta calcolata in x.
*/

#include <stdio.h>
#include <math.h>
#define PI 3.1415926535


double f(int s, double x);

int main () {
    int s;
    double x, fx;
    printf("Scegliere una funzione:\n");
    printf("1) sin(x), per x in [0, 2*PI]\n");
    printf("2) log(x), per x in [1, 1.5]\n");
    printf("3) e^x, per x in [0, 1]\n");
    printf("4) x^5 + 3x^4 - x^2 - 5x + 1, per x in [-5, 5]\n");
    printf("5) 1 / (1 + x^2), per x in [-5, 5]\n");
    printf("6) |x|, per x in [0, 5] e per x in [-3, 2]\n");
    printf("7) sin(x^2), per x in [-5, 5]\n");
    printf("8) |sin(x^2)|, per x in [-5, 5]\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 8);

    printf("Inserire un valore di x:\n");
    scanf("%lf", &x);

    fx = f(s, x);
    if (fx != INFINITY)
        printf("f(x) = %lf\n", fx);

    return 0;
}

double f(int s, double x) {
    double result = INFINITY;
    switch (s) {
        case 1:
            if (x >= 0 && x <= 2*PI)
                result = sin(x);
            else
                printf("x fuori range\n");
            break;
        case 2:
            if (x >= 1 && x <= 1.5)
                result = log(x);
            else
                printf("x fuori range\n");
            break;
        case 3:
            if (x >= 0 && x <= 1)
                result = exp(x);
            else
                printf("x fuori range\n");
            break;
        case 4:
            if (x >= -5 && x <= 5)
                result = x*x*x*x*x + 3*x*x*x*x - x*x - 5*x + 1; 
            else
                printf("x fuori range\n");
            break;
        case 5:
            if (x >= -5 && x <= 5)
                result = 1 / (1 + x*x);
            else
                printf("x fuori range\n");
            break;
        case 6:
            if (x >= -3 && x <= 5)
                result = fabs(x);
            else
                printf("x fuori range\n");
            break;
        case 7:
            if (x >= -5 && x <= 5)
                result = sin(x*x); 
            else
                printf("x fuori range\n");
            break;
        case 8:
            if (x >= -5 && x <= 5)
                result = fabs(sin(x*x)); 
            else
                printf("x fuori range\n");
            break;
        default:
            printf("Scelta non valida\n");
            break;
    }

    return result;
}
