/* Esercizio 5
data: 08/11/2023
autore: Sebastian Ferrigno
Input: Un intero positivo n <= 100
Output: Il programma genera un vettore di n componenti psuedo-random nell'intervallo 
        reale [-1, 1], successivamente ordina l'array e poi lo stampa a schermo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

void swap(double *a, double *b);
void bubble_sort(int size, double arr[size]);
void print_arr(int size, double arr[size]);
int gen_array(int size, double arr[size], int n);

int main() {
    int n = 0;
    double v[Nmax];

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);

    gen_array(Nmax, v, n);
    bubble_sort(n, v);
    printf("Componenti vettore u ordinate:\n");
    print_arr(n, v);

    return 0;
}

int gen_array(int size, double arr[size], int n) {
    if (n > size) {
        fprintf(stderr, "gen_array: ERRORE: n troppo grande\n");
        return 1;
    }
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
        arr[i] = ((rand() % 2000) / 1000.0) - 1;

    return 0;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int size, double arr[size]) {
    int count = 0;
    do {
        count = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
            else
                count++;
        }
    } while (count != size - 1);
}

void print_arr(int size, double arr[size]) {
    for (int i = 0; i < size; i++)
        printf("%lf\n", arr[i]);
}
