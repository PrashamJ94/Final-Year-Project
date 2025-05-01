#include <stdio.h>

int main() {
    int n, N = (int) 1e5 + 5;
    long cnt[21] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        cnt[temp + 10]++;
    }

    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    res += (cnt[10] * (cnt[10] - 1)) / 2;
    printf("%ld\n", res);

    return 0;
}

// //End of Code
