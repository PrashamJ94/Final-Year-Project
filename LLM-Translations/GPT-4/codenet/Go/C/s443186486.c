
#include <stdio.h>
#include <stdlib.h>

int combi(int n, int r);

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int s[n+1];
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[i];
    }

    qsort(s, n+1, sizeof(int), (int (*)(const void *, const void *)) &compare_ints);

    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i+1]) {
            count++;
        } else if (count > 0) {
            ans += combi(count+1, 2);
            count = 0;
        }
    }
    if (count > 0) {
        ans += combi(count+1, 2);
    }

    printf("%d\n", ans);
    return 0;
}

int combi(int n, int r) {
    int c = 1;
    for (int i = 1; i <= r; i++) {
        c = c * (n - i + 1) / i;
    }
    return c;
}

int compare_ints(const int *a, const int *b) {
    return *a - *b;
}

// 
