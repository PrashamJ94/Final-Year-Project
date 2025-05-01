#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define MOD 1000000007

typedef struct {
    int to;
    struct edge *next;
} edge;

edge *graph[MAX];
int color[MAX];

void add_edge(int from, int to) {
    edge *e = malloc(sizeof(edge));
    e->to = to;
    e->next = graph[from];
    graph[from] = e;
}

int dfs(int v, int p, int k) {
    int c = k, res = 1;
    for (edge *e = graph[v]; e; e = e->next) {
        if (e->to == p) continue;
        res = (long long) res * c-- % MOD;
        if (res == 0) return 0;
        res = (long long) res * dfs(e->to, v, k-2) % MOD;
    }
    return res;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a-1, b-1);
        add_edge(b-1, a-1);
    }
    printf("%d\n", dfs(0, -1, K));
    return 0;
}
/* End of Code */
