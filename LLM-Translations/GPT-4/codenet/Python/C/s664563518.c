#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char s[N][101];
    int t[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", s[i], &t[i]);
    }

    char X[101];
    scanf("%s", X);
    int xi = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(s[i], X) == 0) {
            xi = i;
            break;
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (xi < i) {
            ans += t[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
