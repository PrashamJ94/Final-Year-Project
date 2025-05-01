#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct Pair {
    int key;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

long lcm(long m, long n) {
    return m * n / gcd(m, n);
}

int main() {
    int n, i, ans;
    scanf("%d", &n);
    int l[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare);

    ans = l[n / 2] - l[n / 2 - 1];
    printf("%d\n", ans);

    return 0;
}
