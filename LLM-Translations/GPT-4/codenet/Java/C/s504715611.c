#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct UnionFind {
    int *Parent;
} UnionFind;

UnionFind initUnionFind(int n) {
    UnionFind uf;
    uf.Parent = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf.Parent[i] = -1;
    }
    return uf;
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0)
        return A;
    uf->Parent[A] = root(uf, uf->Parent[A]);
    return uf->Parent[A];
}

int size(UnionFind *uf, int A) {
    return -uf->Parent[root(uf, A)];
}

bool connect(UnionFind *uf, int A, int B) {
    A = root(uf, A);
    B = root(uf, B);
    if (A == B)
        return false;
    if (size(uf, A) < size(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return true;
}

int main() {
    char str[10];
    scanf("%s", str);
    printf("%s\n", (str[2] == str[3] && str[4] == str[5]) ? "Yes" : "No");
    return 0;
}
// 
