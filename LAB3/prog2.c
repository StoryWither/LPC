/* Programma 2
data: 11/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo dei valori di quoto e resto della divisione tra numeri
interi
*/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int a, b, divint, restodivintera;
    a = 3;
    b = 2;
    divint = 3 / 2;

    printf("3/2 = %d\n", divint);
    printf("Inserisci un intero a \n");
    scanf("%d", &a);
    printf("Inserisci un intero b \n");
    scanf("%d", &b);
    divint = a / b;
    printf("%d/%d = %d\n", a, b, divint);
    restodivintera = a % b;
    printf("Resto divisione intera di %d/%d = %d \n", a, b, restodivintera);
    double div;
    div = 3 / 2;
    printf("3/2 = %lf \n", div);
    div = 3.0 / 2;
    printf("3.0/2 =%lf \n", div);
    div = (double)(a) / b;
    printf("(double)(%d)/%d= %lf \n", a, b, div);

    return 0;
}
