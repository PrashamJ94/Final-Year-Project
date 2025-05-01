#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char S[N];
    scanf("%s", S);

    int ans = 1;
    char tmp = S[0];
    for (int i = 0; i < N; i++) {
        if (S[i] != tmp) {
            ans += 1;
            tmp = S[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}
// 
