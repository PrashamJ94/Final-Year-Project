#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

int N;
int adj[MAXN];
int par[MAXN];
int child_num[MAXN];
int seen[MAXN];
int que[MAXN];
int head = 0, tail = 0;

void push(int x) {
    que[tail++] = x;
}

int pop() {
    return que[head++];
}

int main() {
    scanf("%d", &N);
    for (int i = 0 ; i < N - 1 ; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    push(1);
    seen[1] = 1;
    while (head != tail) {
        int v = pop();
        for (int i = 0 ; i < adj[v].size() ; ++i) {
            int u = adj[v][i];
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                push(u);
            }
        }
    }
    int seq[MAXN];
    int seq_sz = 0;
    for (int i = 1 ; i <= N ; ++i) {
        if (child_num[i] == 0) {
            seq[seq_sz++] = i;
        }
    }
    while (seq_sz) {
        int c = seq[--seq_sz];
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            seq[seq_sz++] = par[par[c]];
        }
    }
    printf("Second\n");
    return 0;
}
// End of Code
