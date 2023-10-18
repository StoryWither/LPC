/* Esercizio 2
data: 18/10/2023
autore: Sebastian Ferrigno
Input: 
Output: 
*/

#include <math.h>
#include <stdio.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

int main () {
    double a, b, c, delta, x1, x2, x3, x4, r1, r2, r3, r4; 
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

    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);
    x3 = (2*c) / (-b - sqrt(delta));
    x4 = (2*c) / (-b + sqrt(delta));
    r1 = a*(x1*x1) + b*x1 + c;
    r2 = a*(x2*x2) + b*x2 + c;
    r3 = a*(x3*x3) + b*x3 + c;
    r4 = a*(x4*x4) + b*x4 + c;

    printf("Valori con la prima formula:\n");
    printf("x1: %lf\n", x1);
    printf("x2: %lf\n", x2);
    printf("R1: %lf\n", r1);
    printf("R2: %lf\n", r2);
    printf("Valori con la seconda formula:\n");
    printf("x1: %lf\n", x3);
    printf("x2: %lf\n", x4);
    printf("R1: %lf\n", r3);
    printf("R2: %lf\n", r4);

    return 0;
}
