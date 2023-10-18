/* Esercizio 4
data: 18/10/2023
autore: Sebastian Ferrigno
Input: 
Output: 
*/

#include <stdio.h>

int main () {
	int i, j;
	printf("Inserire 2 numeri:\n");
	scanf("%d", &i);
	scanf("%d", &j);

	if (i % j == 0 || j % i == 0 || i % 7 == 3 || j % 7 == 3)
		printf("Vero\n");
	else
		printf("Falso\n");

	return 0;
}

