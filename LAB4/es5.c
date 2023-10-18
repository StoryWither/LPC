/* Esercizio 5
data: 18/10/2023
autore: Sebastian Ferrigno
Input: Coefficienti di un polinomio di secondo grado e variabile di scelta
Output: Radici del polinomio se appartenenti all'intervallo scelto
*/

#include <math.h>
#include <stdio.h>
// Per la compilazione con gcc usare "gcc nomefile.c -lm"

#define PI 3.141592653589793

int main () {
	int scelta, check_x1, check_x2;
    double a, b, c, delta, x1, x2;
    printf("Inserire a:\n");
    scanf("%lf", &a);
    if (a == 0) {
        printf("ERRORE: 'a' deve essere diverso da 0\n");
        return 1;
    } 
    printf("Inserire b:\n");
    scanf("%lf", &b);
    printf("Inserire c:\n");
    scanf("%lf", &c);
    
	printf("Scegliere l'intervallo a cui restringere l'insieme delle soluzioni\n");
	printf("1: [0, 2pi]\n");
	printf("2: [10^-6, 10^6]\n");
	printf("3: [-10^20, 10^20]\n");
	printf("4: [-1, 1)\n");
	printf("5: (0, 2pi)\n");
    scanf("%d", &scelta);

    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
    }
    delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("Non esistono soluzioni reali\n");
        return 0;
    }

    if (b >= 0) {
        x1 = (2*c) / (-b - sqrt(delta));
        x2 = (-b - sqrt(delta)) / (2*a);
    } else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (2*c) / (-b + sqrt(delta));
    }
	
	switch(scelta) {
		case 1:
			check_x1 = x1 >= 0 && x1 <= 2*PI;
			check_x2 = x2 >= 0 && x2 <= 2*PI;
			break;
		case 2:
			check_x1 = x1 >= pow(10, -6) && x1 <= pow(10, 6);
			check_x2 = x2 >= pow(10, -6) && x2 <= pow(10, 6);
			break;
		case 3:
			check_x1 = x1 >= -pow(10, 20) && x1 <= pow(10, 20);
			check_x2 = x2 >= -pow(10, 20) && x2 <= pow(10, 20);
			break;
		case 4:
			check_x1 = x1 >= -1 && x1 < 1;
			check_x2 = x2 >= -1 && x2 < 1;
			break;
		case 5:
			check_x1 = x1 > 0 && x1 < 2*PI;
			check_x2 = x2 > 0 && x2 < 2*PI;
			break;

		default:
			printf("Scelta non presente\n");
			return 1;
	}

    printf("Valori:\n");
	if (check_x1)
    	printf("x1: %lf\n", x1);
	else	
    	printf("x1 fuori range \n");

	if (check_x2)
    	printf("x2: %lf\n", x2);
	else	
    	printf("x2 fuori range \n");

    return 0;
}
