#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    char S[N][L+1];

    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }

    qsort(S, N, sizeof(S[0]), cmp);

    for (int i = 0; i < N; i++) {
        printf("%s", S[i]);
    }

    return 0;
}


