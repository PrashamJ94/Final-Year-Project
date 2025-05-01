#include <stdio.h>
#include <string.h>

int main() {
    char S[1001], T[1001];
    scanf("%s", S);
    scanf("%s", T);

    int N = strlen(S);
    int M = strlen(T);
    int ans = M;
    for (int i = 0; i <= N - M; i++) {
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            if (T[j] != S[i + j]) {
                cnt++;
            }
        }
        if (cnt < ans) {
            ans = cnt;
        }
    }

    printf("%d\n", ans);

    return 0;
}
// 
