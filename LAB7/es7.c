#include <stdio.h>
#include <stdlib.h>

int nBaseB (int n, int B);
int qBase10(int q, int B);
int converti_base (int n, int B1, int B2);

int main () {

    int m;
    m = nBaseB(33, 2);
    printf("%d\n", m);

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
    if (B1 < 2 || B2 < 2 || B1 > 9 || B2 > 9) {
        fprintf(stderr, "converti_base: ERRORE: una delle basi scelte e' fuori range\n");
        exit(1);
    }
    int result = nBaseB(qBase10(n, B1), B2);

    return result;
}
