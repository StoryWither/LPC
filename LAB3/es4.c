/* Esercizio 4
data: 11/10/2023
autore: Sebastian Ferrigno
Input: Coefficienti di un polinomio di secondo grado 
Output: Radici del polinomio e residui di calcolo
*/

#include <math.h>
#include <stdio.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

int main () {
    double a, b, c, delta, x1, x2, r1, r2, r1_rel, r2_rel;
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

    r1 = a*(x1*x1) + b*x1 + c;
    r2 = a*(x2*x2) + b*x2 + c;
    r1_rel = r1 / x1; 
    r2_rel = r2 / x2; 

    printf("Valori:\n");
    printf("x1: %lf\n", x1);
    printf("x2: %lf\n", x2);
    printf("R1: %lf\n", r1);
    printf("R2: %lf\n", r2);
    printf("R1_rel: %lf\n", r1_rel);
    printf("R2_rel: %lf\n", r2_rel);

    return 0;
}
