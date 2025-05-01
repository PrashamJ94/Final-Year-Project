#include <stdio.h>

void get_nums(int num, int t, int *result) {
    for (int i = 0; i < num; i++) {
        result[i] = (i < t % num) ? t / num + 1 : t / num;
    }
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    int ans[n];
    get_nums(k, sk, ans);
    get_nums(n - k, sa - sk, ans + k);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}

// End of Code
