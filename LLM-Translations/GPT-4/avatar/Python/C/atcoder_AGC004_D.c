
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int dfs(Array *links, int n, int k, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;
    int i;
    for(i = 0; i < links[v].used; i++) {
        if(links[v].array[i] == 0)
            continue;
        int hgt, cut;
        hgt = dfs(links, n, k, links[v].array[i], v);
        cut = dfs(links, n, k, links[v].array[i], v);
        height_from_leaf = (height_from_leaf > hgt) ? height_from_leaf : hgt;
        cut_count += cut;
    }
    height_from_leaf += 1;
    if(p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    return height_from_leaf, cut_count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int aaa[n];
    Array links[n];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &aaa[i]);
        initArray(&links[i], 5);
        aaa[i] -= 1;
        insertArray(&links[aaa[i]], i);
    }
    int ans;
    _, ans = dfs(links, n, k, 0, 0);
    if(aaa[0] != 1) {
        ans += 1;
    }
    printf("%d\n", ans);
    for(i = 0; i < n; i++) {
        freeArray(&links[i]);
    }
    return 0;
}
// End of Code


//Note: The above C code assumes that the input is made through standard input (stdin, usually the keyboard) and output is made through standard output (stdout, usually the console).
