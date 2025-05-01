#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    int s[] = {1, 2, 4, 8, 16, 32, 64};
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        bool in_s = false;
        for (int j = 0; j < 7; j++) {
            if (i == s[j]) {
                in_s = true;
                break;
            }
        }
        if (in_s) {
            ans = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}

// 
