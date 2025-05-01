#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    getchar();

    char s[N+1];
    fgets(s, N+1, stdin);

    bool flag = false;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = false;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = true;
            } else {
                // temp += dot;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    } else {
        // temp += dot;
    }

    printf("%d\n", ans + dot);

    return 0;
}
// 
