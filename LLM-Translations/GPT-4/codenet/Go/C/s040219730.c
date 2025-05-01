#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000000 + 7
#define INF_INT64 9223372036854775807
#define INF_BIT60 1152921504606846976
#define INF_INT32 2147483647
#define INF_BIT30 1073741824
#define NIL -1

typedef struct {
    int idx, l, r;
} Query;

int compare(const void *a, const void *b) {
    Query query_a = *(Query *)a;
    Query query_b = *(Query *)b;

    return (query_a.r - query_b.r);
}

void fenwick_tree_add(int *tree, int idx, int x, int n) {
    while (idx <= n) {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}

int fenwick_tree_sum(int *tree, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *C = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    Query *Q = (Query *)malloc(q * sizeof(Query));
    for (int i = 0; i < q; i++) {
        Q[i].idx = i;
        scanf("%d %d", &Q[i].l, &Q[i].r);
    }

    qsort(Q, q, sizeof(Query), compare);

    int *P = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }

    int *fenwick_tree = (int *)calloc(n + 50, sizeof(int));
    int *Answers = (int *)malloc((q + 50) * sizeof(int));
    int k = 0;

    for (int i = 0; i < q; i++) {
        Query query = Q[i];
        while (k < query.r) {
            if (P[C[k]] != -1) {
                fenwick_tree_add(fenwick_tree, P[C[k]] + 1, -1, n + 50);
            }
            P[C[k]] = k;
            fenwick_tree_add(fenwick_tree, k + 1, 1, n + 50);
            k++;
        }

        Answers[query.idx] = fenwick_tree_sum(fenwick_tree, query.r) - fenwick_tree_sum(fenwick_tree, query.l - 1);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]);
    }

    free(C);
    free(Q);
    free(P);
    free(fenwick_tree);
    free(Answers);

    return 0;
}

// 
