/* Esercizi 5 e 6
data: 11/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di una tabella contenente temperatura in gradi
Fahrenheit, gradi Celsius e la differenza tra i valori della temperatura Celsius
*/

#include <stdio.h>

int main() {
    float cels, prev_cels;
    printf("Fahr\t Celsius\t Differnza Celsius\n");
    for (int fahr = 0; fahr <= 200; fahr += 20) {
        cels = (5.0 / 9) * (fahr - 32);
        if (fahr > 0)
            printf("%d\t %f\t %f\n", fahr, cels, cels - prev_cels);
        else
            printf("%d\t %f\t ---\n", fahr, cels);
        prev_cels = cels;
    }

    return 0;
}
