#include <stdio.h>

int check(int lis[], int n, int k, int mid) {
    int i;
    for (i = 0; i < n; i++) {
        if (lis[i] % mid == 0) {
            k += 1;
        }
        k -= (lis[i] / mid);
    }
    return k >= 0;
}

int main() {
    int n, k, i, a, b, ans, mid;
    scanf("%d %d", &n, &k);
    int lis[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }
    a = 1;
    b = lis[0];
    for (i = 0; i < n; i++) {
        if (lis[i] > b) {
            b = lis[i];
        }
    }
    ans = b;
    while (a <= b) {
        mid = (a + b) / 2;
        if (check(lis, n, k, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

// End of Code
