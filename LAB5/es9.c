/* Esercizio 8
data: 25/10/2023
autore: Sebastian Ferrigno
Input: Un numero reale positivo toll
Output: Approssimazione di e con la serie S_n = sum(k=0, N) 1 / k!,
        con N tale che 3/N! < toll.
        Stampa a schermo dell'errore tra S_n calcolato ed exp(1) ad ogni iterazione.
*/

#include <stdio.h>
#include <math.h>

int fact (int n);

int main () {
    double toll, a = 1;
    int n = 1, fact = 1;
    printf("Inserire un toll minimo maggiore di 0:\n");
    do { 
        scanf("%lf", &toll);
    } while (toll <= 0);
    while (3.0 / fact > toll) 
        fact *= ++n; 

    printf("a_n     \t |e - a_n|\n\n");
    while (n > 0) {
        a = 1 + (1.0/n) * a;
        printf("%.8lf\t %.8lf\n", a ,fabs(exp(1) - a));
        n--;
    }

    return 0;
}
