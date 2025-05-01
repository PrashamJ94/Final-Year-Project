#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[1001];
    scanf("%s", s);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x[256] = {0};
        int y[256] = {0};

        for (int j = 0; j <= i; j++) {
            x[(int)s[j]]++;
        }

        for (int j = i+1; j < n; j++) {
            y[(int)s[j]]++;
        }

        int z = 0;
        for (int w = 0; w < 256; w++) {
            if (x[w] && y[w]) {
                z++;
            }
        }

        if (z > ans) {
            ans = z;
        }
    }

    printf("%d\n", ans);

    return 0;
} // 
