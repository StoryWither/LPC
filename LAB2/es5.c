/* Esercizio 5
data: 04/10/2023
autore: Sebastian Ferrigno
Input: Tre numeri reali
Output: I valori delle variabili vengono scambiati in maniera circolare (i.e.
a->c, c->b, b->a)
*/

#include <stdio.h>

int main() {
    double a, b, c, tmp;
    printf("Inserire il valore di a:\n");
    scanf("%lf", &a);
    printf("Inserire il valore di b:\n");
    scanf("%lf", &b);
    printf("Inserire il valore di c:\n");
    scanf("%lf", &c);

    tmp = a;
    a = b;
    b = c;
    c = tmp;

    printf("Valori scambiati:\n");
    printf("a = %lf\n", a);
    printf("a = %lf\n", b);
    printf("c = %lf\n", c);

    return 0;
}
