/* Esercizio 5
data: 18/10/2023
autore: Sebastian Ferrigno
Input: 
Output: 
*/

#include <stdio.h>


int main () {
	const double euro_to_dollar = 1.0554076; // Valori presi in data 18/10/2023
	const double bit_to_dollar = 28387.92; // Valori presi in data 18/10/2023
	const double dollar_to_euro = 0.94744195; // Non inverto nel codice per perdere meno precisione
	const double dollar_to_bit = 3.52423e-5; // Non inverto nel codice per perdere meno precisione
	int scelta_in, scelta_out;
	double val_in, val_out, temp_dollar;	

	printf("Scegliere la valuta di inserimento:\n");
	printf("1: Euro\n");
	printf("2: Dollari\n");
	printf("3: Bitcoin\n");
	scanf("%d", &scelta_in);
	if (scelta_in == 1)
		temp_dollar = val_in * euro_to_dollar; 
	else if (scelta_in == 2)
		temp_dollar = val_in;
	else if (scelta_in == 3)
		temp_dollar = val_in * bit_to_dollar;
	else {
		printf("Scelta non ammissibile!\n");
		return 1;
	}

	printf("Inserire la quantita' di valuta da convertire:\n");
	scanf("%lf", &val_in);
	printf("Scegliere la valuta di output:\n");
	printf("1: Euro\n");
	printf("2: Dollari\n");
	printf("3: Bitcoin\n");
	scanf("%d", &scelta_out);
		
	if (scelta_out == 1)
		val_out = dollar_to_euro * temp_dollar;
	else if (scelta_out == 2)
		val_out = temp_dollar;
	else if (scelta_out == 3)
		val_out = dollar_to_bit * temp_dollar;
	else {
		printf("Scelta non ammissibile!\n");
		return 1;
	}

	printf("Quantita convertita nella valuta scelta:\n");
	printf("%lf\n", val_out);
		

	return 0;
}
