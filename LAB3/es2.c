/* Esercizio 2
data: 11/10/2023
autore: Sebastian Ferrigno
Input: Base e altezza di un rettangolo
Output: Perimetro e area del rettangolo
*/

#include <stdio.h>

int main() {
    double base, altezza, perimetro, area;
    printf("Inserire valore base:\n");
    scanf("%lf", &base);
    printf("Inserire valore altezza:\n");
    scanf("%lf", &altezza);
    if (base <= 0 || altezza <= 0) {
        printf("ERRORE: La base e l'altezza devono essere misure strettamente "
               "positive\n");
        return 1;
    }

    perimetro = 2 * (base + altezza);
    area = base * altezza;

    printf("Valore perimetro: %lf\n", perimetro);
    printf("Valore area: %lf\n", area);

    return 0;
}
