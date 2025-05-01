
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % 1000000007;
    }
    return result;
}

int main() {
    int n, m;
    long long result;
    scanf("%d %d", &n, &m);

    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }

    result = (2 - m + n) * factorial(n) * factorial(m);
    result = (result % 1000000007 + 1000000007) % 1000000007;

    printf("%lld\n", result);

    return 0;
}


