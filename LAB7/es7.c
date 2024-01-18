/* Cambio_di_base (Esercizio 7)
data: 08/11/2023
autore: Sebastian Ferrigno
Input: Il programma prende in input due interi B1 e B2 compresi tra 1 e 9
        e un intero positivo n.
Output: Il programma converte il numero n da base B1 a base B2 e lo stampa a schermo. 
*/

#include <stdio.h>
#include <stdlib.h>

int nBaseB (int n, int B);
int qBase10(int q, int B);
int converti_base (int n, int B1, int B2);

int main () {
    int B1, B2;
    int n, n_conv;
    printf("Scegliere la base di partenza:\n");
    do { 
        scanf("%d", &B1);
    } while (B1 < 2 || B1 > 10);

    printf("Scegliere la base di arrivo:\n");
    do { 
        scanf("%d", &B2);
    } while (B2 < 2 || B2 > 10);
    
    printf("Inserire il numero in base %d da convertire in base %d\n", B1, B2);
    scanf("%d", &n);
    n_conv = converti_base(n, B1, B2);
    printf("Il numero convertito in base %d e': %d\n", B2, n_conv);
    


    return 0;
}

int nBaseB (int n, int B) {
    if (B < 2 || B > 9) {
        fprintf(stderr, "nBaseB: ERRORE: base scelta fuori range\n");
        exit(1);
    }

    int result = 0, esp = 1;
    while (n != 0) {
        result += (n % B) * esp;
        esp *= 10;
        n /= B;
    }

    return result;
}

int qBase10(int q, int B) {
    if (B < 2 || B > 9) {
        fprintf(stderr, "qBase10: ERRORE: base scelta fuori range\n");
        exit(1);
    }
    int result = 0, esp = 1;
    while (q != 0) {
        result += (q % 10) * esp;
        esp *= B;
        q /= 10;
    }

    return result;
}

int converti_base (int n, int B1, int B2) {
    if (B1 < 2 || B2 < 2 || B1 > 10 || B2 > 10) {
        fprintf(stderr, "converti_base: ERRORE: una delle basi scelte e' fuori range\n");
        exit(1);
    }
    int result;
    if (B1 == 10 && B2 == 10)
        result = n;
    else if (B1 == 10)
        result = nBaseB(n, B2); 
    else if (B2 == 10)
        result = qBase10(n, B1);
    else
        result = nBaseB(qBase10(n, B1), B2);

    return result;
}
