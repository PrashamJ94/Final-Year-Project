#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    int default_val;
    int *seg;
} SegmentTree;

int segfunc(int x, int y) {
    return x > y ? x : y;
}

void update(SegmentTree *tree, int k, int x) {
    k += tree->size - 1;
    tree->seg[k] = x;
    while (k) {
        k = (k - 1) / 2;
        tree->seg[k] = segfunc(tree->seg[2 * k + 1], tree->seg[2 * k + 2]);
    }
}

int query(SegmentTree *tree, int p, int q) {
    if (q <= p) {
        return tree->default_val;
    }
    p += tree->size - 1;
    q += tree->size - 2;
    int ret = tree->default_val;
    while (q - p > 1) {
        if (p % 2 == 0) {
            ret = segfunc(ret, tree->seg[p]);
        }
        if (q % 2 == 1) {
            ret = segfunc(ret, tree->seg[q]);
            q -= 1;
        }
        p = p / 2;
        q = (q - 1) / 2;
    }
    ret = segfunc(segfunc(ret, tree->seg[p]), tree->seg[q]);
    return ret;
}

SegmentTree *init(int size, int default_val) {
    SegmentTree *tree = malloc(sizeof(SegmentTree));
    tree->size = 1 << (int)ceil(log2(size));
    tree->default_val = default_val;
    tree->seg = calloc(2 * tree->size - 1, sizeof(int));
    return tree;
}

void free_tree(SegmentTree *tree) {
    free(tree->seg);
    free(tree);
}

void main() {
    int N;
    scanf("%d", &N);
    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int *ans = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        ans[i] = i + 1;
    }
    SegmentTree *left_seg = init(N, 0);
    for (int i = 0; i < N; i++) {
        ans[a[i] - 1] *= i + 1 - query(left_seg, 0, a[i]);
        update(left_seg, a[i] - 1, i + 1);
    }
    SegmentTree *right_seg = init(N, 0);
    for (int i = 0; i < N; i++) {
        ans[a[N - i - 1] - 1] *= i + 1 - query(right_seg, 0, a[N - i - 1]);
        update(right_seg, a[N - i - 1] - 1, i + 1);
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += ans[i];
    }
    printf("%d\n", sum);

    free(a);
    free(ans);
    free_tree(left_seg);
    free_tree(right_seg);
}

// 
