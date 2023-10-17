/* Programma 4
data: 11/10/2023
autore: Sebastian Ferrigno
Input: Due numeri reali
Output: Valori di input scambiati
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, app;
    printf("Inserisci a:\n");
    scanf("%lf", &a);
    printf("Inserisci b:\n");
    scanf("%lf", &b);
    app = a;
    a = b;
    b = app;
    printf("a = %lf\n", a);
    printf("b = %lf\n", b);

    return 0;
}
