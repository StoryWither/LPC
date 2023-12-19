#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nmax 1000

double f (int scelta, double x);
double pfisso (double x0, int scelta, double toll, int max_count);
void movie (int n);

int main () {
    int s;
    double x0, toll;
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

    printf("Inserire il punto di innesco:\n");
    scanf("%lf", &x0);
    printf("Inserire la tolleranza:\n");
    do {
        scanf("%lf", &toll);
    } while (toll <= 0);
    x = pfisso(x0, s, toll, Nmax);
    fx = f(s, x);
    printf("Punto fisso approssimato: %lf\n", x);
    printf("Residuo: %lf\n", fx - x);

    return 0;
}

double pfisso (double x0, int scelta, double toll, int max_count) {
    if (toll <= 0 || max_count <= 0) {
        fprintf(stderr, "pfisso: ERROR: parametri di input non validi\n");
        exit(1);
    }

    FILE* file = fopen("successione.txt", "wt");
    double x = x0;
    double fx = f(scelta, x0); 

    int count = 0;
    while (fabs(fx - x) > toll && count < max_count) {
        fprintf(file, "%lf %lf\n", x, fx); 
        x = fx;
        fx = f(scelta, x);
        count++;
    }
    fclose(file);

    movie(count);
    if (count >= max_count) {
        printf("pfisso: Il metodo non converge (a meno della tolleranza richiesta) in %d iterazioni\n", max_count);
        exit(0);
    }


    return fx;
}

void movie (int n) {
    FILE* file;
    /* apro in scrittura il file "comandi.txt " per registrarci
    * il comando che dovra ‘ essere eseguito da GNUplot
    */
    file = fopen("comandi.txt", "wt");
    fprintf(file, "plot cos(x) w l \n");
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
    fclose (file);
    system ("gnuplot \"comandi.txt\"");
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
        return exp(-x * x) - 0.5;
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
