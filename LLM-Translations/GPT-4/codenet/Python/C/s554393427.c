#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    double x;
    char u[4];
    double mo[N][2];
    
    for (int i = 0; i < N; i++) {
        scanf("%lf %s", &x, u);
        if (strcmp(u, "JPY") == 0) {
            mo[i][0] = x;
            mo[i][1] = 1;
        } else {
            mo[i][0] = x;
            mo[i][1] = 380000;
        }
    }

    double okz = 0;
    for (int i = 0; i < N; i++) {
        okz += mo[i][0] * mo[i][1];
    }

    printf("%lf\n", okz);
    return 0;
} // 
