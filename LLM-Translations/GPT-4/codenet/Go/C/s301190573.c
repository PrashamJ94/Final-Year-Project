#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

int par[size], rank[size];

char *NextLine() {
    static char buffer[size];
    fgets(buffer, size, stdin);
    return buffer;
}

void NextInts(int *x, int *y) {
    sscanf(NextLine(), "%d %d", x, y);
}

void NextIntArray(int n, int *a) {
    char *line = NextLine();
    char *token = strtok(line, " ");
    for (int i = 0; i < n; i++) {
        a[i] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
}

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int root(int i) {
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return par[i];
}

int same(int i, int j) {
    return root(i) == root(j);
}

void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
    }
}

int main() {
    int n, m, x, y, s = 0;
    NextInts(&n, &m);
    int p[n];
    NextIntArray(n, p);
    initialize(n);
    for (int i = 0; i < m; i++) {
        NextInts(&x, &y);
        unite(x - 1, y - 1);
    }
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) s++;
    }
    printf("%d\n", s);
    return 0;
}
// 
