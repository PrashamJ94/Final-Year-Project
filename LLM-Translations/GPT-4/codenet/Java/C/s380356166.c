#include <stdio.h>
#include <stdbool.h>

int main() {
    int K, S;
    scanf("%d%d", &K, &S);

    int ans = 0;
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

//
