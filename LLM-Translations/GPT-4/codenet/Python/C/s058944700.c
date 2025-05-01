#include <stdio.h>

int main() {
    int n, k, tmp, ans;

    scanf("%d %d", &n, &k);

    if (n > k) {
        tmp = n % k;
        if (tmp >= k - tmp) {
            ans = k - tmp;
        } else {
            ans = tmp;
        }
    } else if (n < k) {
        if (n >= k - n) {
            ans = k - n;
        } else {
            ans = n;
        }
    } else {
        ans = 0;
    }

    printf("%d\n", ans);

    return 0;
} // 
