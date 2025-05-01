#include <stdio.h>
#include <string.h>

double solve(int N, double x[], char u[][4]);

int main() {
    int N;
    scanf("%d", &N);

    double x[N];
    char u[N][4];

    for (int i = 0; i < N; ++i) {
        scanf("%lf %s", &x[i], u[i]);
    }

    printf("%.10lf\n", solve(N, x, u));
    return 0;
}

double solve(int N, double x[], char u[][4]) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += x[i] * (strcmp(u[i], "JPY") == 0 ? 1 : 380000);
    }
    return sum;
}

// //End of Code
