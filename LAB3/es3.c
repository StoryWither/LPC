/* Esercizio 3
data: 11/10/2023
autore: Sebastian Ferrigno
Input: Temperatura in gradi Celsius
Output: Temperatura in gradi Fahrenheit
*/

#include <stdio.h>

int main() {
    double celsius, fahr;
    printf("Inserire la temaperatura in gradi Celsius:\n");
    scanf("%lf", &celsius);
    fahr = (9.0 / 5) * celsius + 32;
    celsius = (5.0 / 9) * (fahr - 32);
    printf("Temperatura convertita in gradi Fahrenheit: %lf\n", fahr);
    printf("Temperatura riconvertita in gradi Celsius: %lf\n", celsius);

    return 0;
}
