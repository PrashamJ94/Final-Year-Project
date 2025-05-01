#include <stdio.h>
#include <string.h>

int main() {
    int N;
    double x, sum = 0.0;
    char currency[4];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lf %s", &x, currency);
        
        if (strcmp(currency, "JPY") == 0) {
            sum += x * 1.0;
        } else if (strcmp(currency, "BTC") == 0) {
            sum += x * 380000.0;
        }
    }

    printf("%lf\n", sum);

    return 0;
} // End of Code.
