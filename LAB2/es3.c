/* Esercizio 3
data: 04/10/2023
autore: Sebastian Ferrigno
Input: Un numero reale positivo a e un numero reale b 
Output: L'elevamento a potenza a^b
*/

#include <stdio.h>
#include <math.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

int main () {
    double a, b, out;
    printf("Inserire il valore di a:\n");
    scanf("%lf", &a);
    if (a <= 0) {
        printf("ERRORE: 'a' deve essere strettamente maggiore di 0");
        return 1;
    }
    printf("Inserire il valore di b:\n");
    scanf("%lf", &b);

    out = pow(a, b);
    printf("Valore di a^b = %lf\n", out);


    return 0;
}



