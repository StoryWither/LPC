/* Programma 3
data: 11/10/2023
autore: Sebastian Ferrigno
Input: Angolo espresso in gradi
Output: Angolo espresso in radianti 
*/

#include <stdio.h>
#include <stdlib.h>
#define pi 3.141592653589793

int main(void) {
    double alfa;
    printf("Scrivi angolo in gradi \n");
    scanf("%lf", &alfa);
    alfa = alfa / 180 * pi;
    printf("alfa = %lf \n", alfa);

    return 0;
}
