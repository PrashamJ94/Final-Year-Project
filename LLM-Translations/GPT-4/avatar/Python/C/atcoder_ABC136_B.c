#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    int i = 1;
    int ans = 0;

    while (pow(10, i) <= N) {
        ans += ((pow(10, i)) - (pow(10, (i - 1))));
        i += 2;
    }

    ans += max(0, N - pow(10, (i - 1)) + 1);
    printf("%d", ans);

    return 0;
}

// End of Code
