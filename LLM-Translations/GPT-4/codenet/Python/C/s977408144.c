
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    char S[n][l + 1];

    for (int a = 0; a < n; a++) {
        scanf("%s", S[a]);
    }

    qsort(S, n, sizeof(S[0]), compare);

    for (int a = 0; a < n; a++) {
        printf("%s", S[a]);
    }
    printf("\n");

    return 0;
}


