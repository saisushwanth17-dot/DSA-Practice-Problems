#include <stdio.h>
#include <string.h>

#define LEN 20

int main() {
    char var[3][LEN];
    char inp[3][LEN];
    double M, D, X, x;
    char c1, c2, c3;

    while (scanf(" %c", &c1) == 1) {
        if (c1 == 'M') {
            scanf("%lf", &M);
            scanf(" %c %lf", &c2, &D);
            scanf(" %c %s", &c3, inp[0]);
            // x = M + D
            x = M + D;
            printf("x %.2f\n", x);
        }
    }
    return 0;
}
