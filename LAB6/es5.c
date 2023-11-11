#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 100

void swap(int *a, int *b);
void reverse_bubble_sort(int *arr, int size);
void print_arr(int *arr, int size);

int main() {
    srand(time(NULL));
    int n = 0;
    int u[Nmax];
    int count = 0;

    printf("Inserire lunghezza vettore:\n");
    do {
        scanf("%d", &n);
    } while (n < 0 || n > Nmax);

    for (int i = 0; i < n; i++) {
        u[i] = (rand() % 100) + 1;
    }

    reverse_bubble_sort(u, n);
    printf("Componenti vettore u ordinate in senso decrescente:\n");
    print_arr(u, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_bubble_sort(int *arr, int size) {
    int count = 0;
    do {
        count = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
            else
                count++;
        }
    } while (count != size - 1);
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}
