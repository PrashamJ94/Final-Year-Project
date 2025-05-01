#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int vis[100005], ci, cb, cc, n, m, u, v;
bool flag;
struct Node {
    int data;
    struct Node* next;
} *g[100005];

void addEdge(int u, int v) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = v;
    node->next = g[u];
    g[u] = node;
    
    node = (struct Node*) malloc(sizeof(struct Node));
    node->data = u;
    node->next = g[v];
    g[v] = node;
}

bool dfs(int x) {
    int stack[100005], top = -1, col[100005], i;
    stack[++top] = x;
    col[top] = 1;
    
    while (top != -1) {
        x = stack[top];
        i = col[top--];
        if (vis[x]) {
            flag &= (vis[x] == i);
            continue;
        }
        vis[x] = i;
        for (struct Node* node = g[x]; node; node = node->next)
            stack[++top] = node->data, col[top] = 3 - i;
    }
    return flag;
}

void solve() {
    ci = cb = cc = 0;
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            struct Node* node = g[i];
            if (node == NULL) {
                ci++;
            } else {
                flag = true;
                if (dfs(i)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }
    
    long long ans = (long long)ci * ci + 2LL * ci * (n - ci) + (long long)cc * cc + 2LL * cb * cc + 2LL * cb * cb;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}

//End of Code.
