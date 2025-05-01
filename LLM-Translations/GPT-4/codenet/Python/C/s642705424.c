#include <stdio.h>
#include <string.h>

int main() {
    int N, x = 1;
    scanf("%d", &N);

    char S[N];
    scanf("%s", S);

    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            x = x + 1;
        }
    }

    printf("%d\n", x);
    return 0;
} // 
