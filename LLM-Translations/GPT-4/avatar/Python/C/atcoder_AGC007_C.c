#include <stdio.h>

int main() {
    int N;
    double d, x;
    scanf("%d%lf%lf", &N, &d, &x);
    double ret = 0;
    while(N) {
        ret += d + (N - 0.5) * x;
        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;
        N -= 1;
    }
    printf("%lf", ret);
    return 0;
}
// End of Code.
