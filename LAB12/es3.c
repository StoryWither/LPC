/* Secanti (Esercizio 3)
data: 13/12/2023
autore: Sebastian Ferrigno
Input: Il programma offre una scelta di funzioni con un menu`. L'utente sceglie
        una funzione inserendo un intero di scelta s. Poi inserisce due punti di 
        innesco x0 e x1, un double positivo toll.

Output: Il programma approssima il valore di una radice della funzione scelta
        con il metodo delle secanti. Infine stampa a video la radice approssimata 
        ed il residuo f(x).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double f (int scelta, double x);
double secanti (double x0, double x1, int scelta, double toll, int max_count);
void movie (int scelta, int n);

int main () {
    int s;
    double x0, x1, toll;
    double x, fx;
    printf("Scegliere una funzione dal menu:\n");
    printf("1) e^x - 1\n");
    printf("2) x^3 - 8\n");
    printf("3) cos(x)\n");
    printf("4) arctan(x)\n");
    printf("5) sin(3x)\n");
    printf("6) ln(1 + x)\n");
    printf("7) e^(-x^2) - 1/2\n");
    printf("8) (1 - x^2)^2\n");
    printf("9) x^3 - 2x^2 +3x - 1\n");
    printf("10) |x^3 - x + 1|\n");
    printf("11) x^5 + 3x^4 + 2x^3 -x^2 -5x +1\n");
    printf("12) 1/(1 + x^2) - 0.3\n");
    printf("13) |2x| - 1\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 13);

    printf("Inserire i punti di innesco:\n");
    scanf("%lf", &x0);
    scanf("%lf", &x1);
    printf("Inserire la tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);
    x = secanti(x0, x1, s, toll, Nmax);
    fx = f(s, x);
    printf("Radice approssimata: %lf\n", x);
    printf("Residuo: %lf\n", fx);

    return 0;
}

double secanti(double x0, double x1, int scelta, double toll, int max_count) {
    if (toll <= 0 || max_count <= 0) {
        fprintf(stderr, "secanti: ERROR: parametri di input non validi\n");
        exit(1);
    }

    FILE* file = fopen("successione.txt", "w");
    double prevx = x0;
    double prevf = f(scelta, x0);
    double x = x1;
    double fx = f(scelta, x1);
    double phix = (prevx * fx - x * prevf) / (fx - prevf); 

    int count = 0;
    while ((f(scelta, x + toll / 2) * f(scelta, x - toll / 2) > 0 || fabs(fx) > toll) && count < max_count) {
        fprintf(file, "%lf %lf\n", x, fx); 
        prevx = x;
        prevf = fx;
        x = phix;
        fx = f(scelta, x);
        phix = (prevx * fx - x * prevf) / (fx - prevf); 
        count++;
    }
    fclose(file);

    if (count >= max_count) {
        printf("secanti: Il metodo non converge (a meno della tolleranza richiesta) in %d iterazioni\n", max_count);
        exit(0);
    }
    movie(scelta, count);

    return x;
}

void movie (int scelta, int n) {
    FILE* file;
    /* apro in scrittura il file "comandi.gp " per registrarci
    * il comando che dovra ‘ essere eseguito da GNUplot
    */
    file = fopen("comandi.gp", "w");
    switch(scelta) {
    case 1:
        fprintf(file, "plot exp(x) - 1 w l \n");
        break;
    case 2:
        fprintf(file, "plot x * x * x - 8 w l \n");
        break;
    case 3:
        fprintf(file, "plot cos(x) w l \n");
        break;
    case 4:
        fprintf(file, "plot atan(x) w l \n");
        break;
    case 5:
        fprintf(file, "plot sin(3*x) w l \n");
        break;  
    case 6:
        fprintf(file, "plot log(1 + x) w l \n");
        break;  
    case 7:
        fprintf(file, "plot exp(-x * x) - 0.5 w l \n");
        break;  
    case 8:
        fprintf(file, "plot (1 - x*x) * (1 - x*x) w l \n");
        break;  
    case 9:
        fprintf(file, "plot x*x*x - 2*x*x + 3*x - 1 w l \n");
        break;  
    case 10:
        fprintf(file, "plot abs(x*x*x - x + 1) w l \n");
        break;  
    case 11:
        fprintf(file, "plot x*x*x*x*x + 3*x*x*x*x + 2*x*x*x - x*x - 5*x + 1 w l \n");
        break;  
    case 12:
        fprintf(file, "plot 1 / (1 + x*x) - 0.3 w l \n");
        break;
    case 13:
        fprintf(file, "plot abs(2*x) - 1 w l \n");
        break;
    default:
        fprintf(stderr, "movie: ERROR: scelta non valida\n");
        fclose(file);
        exit(1);
        break;
    }

    // rimuove lable dalla figura
    fprintf (file, "unset key \n");
    fprintf (file, "pause(-1) \n");
    /*
    * scrivo sul file il comando da eseguire
    */
    for (int i = 0; i < n ; i++) {
        fprintf (file, "replot\"successione.txt\" every ::%d::%d pt 4 ps 3 \n", i, i);
        fprintf (file, "pause(-1) \n");
    }
    fprintf(file, "pause mouse close\n");
    fclose (file);
    system ("gnuplot \"comandi.gp\"");
}


double f (int scelta, double x) {
    double a;
    switch(scelta) {
    case 1:
        return exp(x) - 1;
        break;
    case 2:
        return (x * x * x - 8);
        break;
    case 3:
        return cos(x);
        break;
    case 4:
        return atan(x);
        break;
    case 5:
        return sin(3*x);
        break;  
    case 6:
        return log(1 + x);
        break;  
    case 7:
        return exp(-(x * x) - 0.5);
        break;  
    case 8:
        return (1- x*x) * (1 - x*x);
        break;  
    case 9:
        return x*x*x - 2*x*x + 3*x -1;
        break;  
    case 10:
        return fabs(x*x*x -x + 1);
        break;  
    case 11:
        return x*x*x*x*x + 3*x*x*x*x + 2*x*x*x - x*x - 5*x + 1;
        break;  
    case 12:
        return 1 / (1 + x*x) - 0.3;
        break;
    case 13:
        return fabs(2*x) - 1;
        break;
    default:
        fprintf(stderr, "f: ERROR: scelta non valida\n");
        exit(1);
        break;
    }
}
