#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 100
#define MAX_LENGHT 50
#define PI 3.1415926536

double f(int s, double a, double b, double x);
void scrivi_tabella_file(char *nomefile, int s, double a, double b, int m);
void grafico_gnuplot(char *tabella, char *comandi, int s); 

int main() {
    int s, m;
    double a, b;

    printf("Scegliere una funzione:\n");
    printf("1) sin(x), per x in [0, 2*PI]\n");
    printf("2) log(x), per x in [1, 1.5]\n");
    printf("3) e^x, per x in [0, 1]\n");
    printf("4) x^5 + 3x^4 - x^2 - 5x + 1, per x in [-5, 5]\n");
    printf("5) 1 / (1 + x^2), per x in [-5, 5]\n");
    printf("6) |x|, per x in [0, 5] e per x in [-3, 2]\n");
    printf("7) sin(x^2), per x in [-5, 5]\n");
    printf("8) |sin(x^2)|, per x in [-5, 5]\n");
    do {
        scanf("%d", &s);
    } while (s < 1 || s > 8);

    printf("Inserire gli estremi di un intervallo [a, b] su cui calcolare la "
           "funzione:\n");
    printf("Inserire a:");
    scanf("%lf", &a);
    printf("Inserire b:");
    do {
        scanf("%lf", &b);
    } while (b < a);

    printf("Inserire il numero di punti equispaziati da calcolare:\n");
    do {
        scanf("%d", &m);
    } while (m < 2 || m > MAX_DIM);

    scrivi_tabella_file("tabella.txt", s, a, b, m);
    grafico_gnuplot("tabella.txt", "comandi.gp", s);

    return 0;
}

double f(int s, double a, double b, double x) {
    double result = INFINITY;

    switch (s) {
    case 1:
        if (x >= 0 && x <= 2 * PI && x >= a && x <= b)
            result = sin(x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 2:
        if (x >= 1 && x <= 1.5 && x >= a && x <= b)
            result = log(x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 3:
        if (x >= 0 && x <= 1 && x >= a && x <= b)
            result = exp(x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 4:
        if (x >= -5 && x <= 5 && x >= a && x <= b)
            result = x * x * x * x * x + 3 * x * x * x * x - x * x - 5 * x + 1;
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 5:
        if (x >= -5 && x <= 5 && x >= a && x <= b)
            result = 1 / (1 + x * x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 6:
        if (x >= -3 && x <= 5 && x >= a && x <= b)
            result = fabs(x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 7:
        if (x >= -5 && x <= 5 && x >= a && x <= b)
            result = sin(x * x);
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    case 8:
        if (x >= -5 && x <= 5 && x >= a && x <= b)
            result = fabs(sin(x * x));
        else
            fprintf(stderr, "f: WARNING: x fuori range\n");
        break;
    default:
        fprintf(stderr, "f: WARNING: Scelta non valida\n");
        break;
    }

    return result;
}

void scrivi_tabella_file(char *nomefile, int s, double a, double b, int m) {
    srand(time(NULL));

    FILE *file = fopen(nomefile, "w");
    double delta = (b - a) / (m - 1);
    double pert = 0;
    double x = 0;
    double fx = 0;

    for (int i = 0; i < m; i++) {
        x = a + delta * i;
        fx = f(s, a, b, x);
        pert = (rand() % 1001) / 10000.0;
        fprintf(file, "%lf %lf\n", x, fx + pert);
    }

    fclose(file);
}

void grafico_gnuplot(char *tabella, char *comandi, int s) {
    FILE *fcomandi = fopen(comandi, "w");
    fprintf(fcomandi, "plot \"%s\", ", tabella);

    char prompt[MAX_LENGHT];
    char delete[MAX_LENGHT];
    sprintf(prompt, "gnuplot %s", comandi);
    sprintf(delete, "rm %s", comandi);

    switch (s) {
    case 1:
        fprintf(fcomandi, "sin(x)");
        break;
    case 2:
        fprintf(fcomandi, "cos(x)");
        break;
    case 3:
        fprintf(fcomandi, "exp(x)");
        break;
    case 4:
        fprintf(fcomandi, "x * x * x * x * x + 3 * x * x * x * x - x * x - 5 * x + 1");
        break;
    case 5:
        fprintf(fcomandi, "1 / (1 + x * x)");
        break;
    case 6:
        fprintf(fcomandi, "abs(x)");
        break;
    case 7:
        fprintf(fcomandi, "sin(x * x)");
        break;
    case 8:
        fprintf(fcomandi, "abs(sin(x * x))");
        break;
    default:
        fprintf(stderr, "f: WARNING: Scelta non valida");
        break;
    }

    /*Spiegazione ottenuta scrivendo "help pause close" in gnuplot:
     The command `pause mouse close` is a specific example of pausing to wait for
     an external event.  In this case the program waits for a "close" event from
     the plot window.*/ 
    fprintf(fcomandi, "\npause mouse close"); 

    fclose(fcomandi);

    system(prompt);
    system(delete);
}

