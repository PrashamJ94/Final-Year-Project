#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {

    int N, L, i;

    scanf("%lld %lld", &N, &L);
    char v[N][L + 1];

    for(i = 0; i < N; i++) {
        scanf("%s", v[i]);
    }

    qsort(v, N, sizeof(v[0]), compare);

    for(i = 0; i < N; i++) {
        printf("%s", v[i]);
    }
    printf("\n");

    return 0;
}

//
