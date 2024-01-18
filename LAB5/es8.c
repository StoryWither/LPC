/* Esercizio 8
data: 25/10/2023
autore: Sebastian Ferrigno
Input: ---
Output: Approssimazione di e con la successione a_n = (1 + 1/n)^n,
        stampa a schermo dell'errore tra a_n calcolato ed exp(1) ad ogni iterazione.
*/

#include <stdio.h>
#include <math.h>

int main () {
    int k = 0;
    double n = 1;
    double a = 2;
    printf("n\t a_n     \t |e - a_n|\n\n");
    while (1 + 1/n > 1) {
        a = pow(1 + 1.0/n, n);
        printf("%.0e\t %.8lf\t %.8lf\n", n, a, fabs(exp(1) - a));
        n = pow(10, ++k);
    }

    return 0;
}
