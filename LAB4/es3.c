/* Esercizio 3
    data: 18/10/2023
    autore: Sebastian Ferrigno
    Input: Coefficienti di un polinomio di secondo grado 
    Output: Radici del polinomio
*/

#include <math.h>
#include <stdio.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

int main () {
    double a, b, c, delta, x1, x2;
    printf("Inserire a:\n");
    scanf("%lf", &a);
    if (a == 0) {
        printf("ERRORE: 'a' deve essere diverso da 0\n");
        return 1;
    } 
    printf("Inserire b:\n");
    scanf("%lf", &b);
    printf("Inserire c:\n");
    scanf("%lf", &c);
    
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
    }

    delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("Non esistono soluzioni reali\n");
        return 0;
    }

    if (b >= 0) {
        x1 = (2*c) / (-b - sqrt(delta));
        x2 = (-b - sqrt(delta)) / (2*a);
    } else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (2*c) / (-b + sqrt(delta));
    }

    printf("Valori:\n");
    printf("x1: %lf\n", x1);
    printf("x2: %lf\n", x2);

    return 0;
}
