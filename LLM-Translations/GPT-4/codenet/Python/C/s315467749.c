#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int q;
    scanf("%d", &q);
    int T[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    int ans = 0;
    for (int i = 0; i < q; i++) {
        if (T[i] == S[n - 1] || T[i] == S[0]) {
            ans++;
        } else {
            int left = 0;
            int right = n - 1;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (S[mid] == T[i]) {
                    ans++;
                    break;
                } else if (S[mid] < T[i]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
// 
