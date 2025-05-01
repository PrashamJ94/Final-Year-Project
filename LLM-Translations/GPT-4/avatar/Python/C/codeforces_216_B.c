#include <stdio.h>
#include <stdlib.h>

int n, m, ans;
int *g[5005];
int nodes, edges;
int seen[5005];

void dfs(int i) {
    if(seen[i]) return;
    seen[i] = 1;
    int j;
    nodes++;
    edges += g[i][0];
    for(j = 1; j <= g[i][0]; j++) {
        dfs(g[i][j]);
    }
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        int i, a, b;
        for(i = 1; i <= n; i++) {
            g[i] = malloc(sizeof(int));
            g[i][0] = 0;
            seen[i] = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            g[a][++g[a][0]] = b;
            g[a] = realloc(g[a], (g[a][0]+1)*sizeof(int));
            g[b][++g[b][0]] = a;
            g[b] = realloc(g[b], (g[b][0]+1)*sizeof(int));
        }
        ans = 0;
        for(i = 1; i <= n; i++) {
            if(!seen[i]) {
                nodes = edges = 0;
                dfs(i);
                if(nodes > 1 && nodes%2 == 1 && 2*nodes == edges) {
                    ans++;
                }
            }
        }
        if((n-ans)%2 == 1) {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/* End of Code */
