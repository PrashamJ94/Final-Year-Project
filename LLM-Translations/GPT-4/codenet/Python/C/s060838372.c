#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s", S);

    if (S[K-1] == 'A') {
        S[K-1] = 'a';
    } else if (S[K-1] == 'B') {
        S[K-1] = 'b';
    } else {
        S[K-1] = 'c';
    }

    printf("%s\n", S);
    return 0;
}

// 
