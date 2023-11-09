#include <stdio.h>

int main() {
    double epsd, epsilond = 1;
    printf("Epsilon corrente\t 1 + eps\n");
    do {
        epsilond /= 2;
        epsd = 1 + epsilond;
        printf("%e     \t %1.20lf \n", epsilond, epsd);
    } while (epsd > 1);

    printf("Precisione double=%e\n", epsilond * 2);

    return 0;
}
