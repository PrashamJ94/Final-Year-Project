
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAXN 100010
#define INF INT_MAX
#define MOD 1000000007

int n, ta, ao;
int g[MAXN][MAXN];
int ta_dist[MAXN];
int ao_dist[MAXN];

void ta_dfs(int node) {
    for (int i = 0; i < n; i++) {
        if (g[node][i] && ta_dist[i] == INF) {
            ta_dist[i] = ta_dist[node] + 1;
            ta_dfs(i);
        }
    }
}

void ao_dfs(int node) {
    for (int i = 0; i < n; i++) {
        if (g[node][i] && ao_dist[i] == INF) {
            ao_dist[i] = ao_dist[node] + 1;
            ao_dfs(i);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; ao--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        g[a][b] = g[b][a] = 1;
    }

    for (int i = 0; i < n; i++) {
        ta_dist[i] = ao_dist[i] = INF;
    }

    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    ta_dfs(ta);
    ao_dfs(ao);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue;
        res = (res < ao_dist[i]) ? ao_dist[i] : res;
    }

    printf("%d\n", res - 1);

    return 0;
}

//End of Code.
