/* Programma
   data: 
   autore:
   input:
   output:
*/

#include <stdio.h>

int main () {
	int k;
	printf("Inserire un numero intero:\n");
	scanf("%d", &k);
	if ( k % 2 == 0 )
		printf("%d e' pari\n", k);
	else
		printf("%d e' dispari\n", k);
	
	return 0;
}
   
