/* Programma 3
data: 04/10/2023
autore: Sebastian Ferrigno
Input: --
Output: Stampa a schermo di valori float e double in vari formati di precisione
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double a = 3.912348239293;
    float b = 3.912348239293;

    printf("Numero di tipo double = %lf \n", a);
    printf("Numero di tipo float = %f \n", b);
    printf("Numero di tipo double = %1.16lf \n", a);
    printf("Numero di tipo float = %1.16f \n", b);

    return 0;
}
