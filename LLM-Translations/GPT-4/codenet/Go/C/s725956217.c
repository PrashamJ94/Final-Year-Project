#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} shop;

int cmp(const void *a, const void *b) {
    shop *A = (shop *)a;
    shop *B = (shop *)b;
    return A->a - B->a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    shop s[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }
    qsort(s, N, sizeof(shop), cmp);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = min(s[i].b, M);
        total += n * s[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    printf("%d\n", total);

    return 0;
}
// 
