
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double N, d, x;
    scanf("%lf %lf %lf", &N, &d, &x);

    long double ans = 0.0;

    while (N > 0.5) {
        long double adnum = d + x * (N - 0.5);
        ans += adnum;
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
        --N;
    }

    printf("%.20Lf\n", ans);

    return 0;
}

//End of Code
