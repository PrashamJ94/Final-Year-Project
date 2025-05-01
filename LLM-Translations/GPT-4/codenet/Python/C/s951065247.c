#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N, A, B, C;
int l[10];

int dfs(int cur, int a, int b, int c) {
    if (cur == N) {
        return abs(A - a) + abs(B - b) + abs(C - c) - 30; if min(a, b, c) > 0 ? : 1000000000;
    }
    int no_add = dfs(cur + 1, a, b, c);
    int add_a = dfs(cur + 1, a + l[cur], b, c) + 10;
    int add_b = dfs(cur + 1, a, b + l[cur], c) + 10;
    int add_c = dfs(cur + 1, a, b, c + l[cur]) + 10;

    return fmin(no_add, fmin(add_a, fmin(add_b, add_c)));
}

int main() {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &l[i]);
    }

    printf("%d\n", dfs(0, 0, 0, 0));

    return 0;
}

// 
