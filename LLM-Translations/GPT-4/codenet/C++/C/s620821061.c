#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define V 520

typedef long long ll;

// BitMatching structure
typedef struct {
    int G[2 * V][V];
    int G_size[2 * V];
    int match[2 * V];
    bool used[2 * V];
} BitMatching;

// Initialize BitMatching
void init(BitMatching *bm) {
    for (int i = 0; i < 2 * V; i++) {
        bm->G_size[i] = 0;
    }
}

// Add connection between a and b
void add(BitMatching *bm, int a, int b) {
    bm->G[a][bm->G_size[a]++] = b + V;
    bm->G[b + V][bm->G_size[b + V]++] = a;
}

bool dfs(BitMatching *bm, int v) {
    bm->used[v] = true;
    for (int i = 0; i < bm->G_size[v]; i++) {
        int u = bm->G[v][i], w = bm->match[u];
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) {
            bm->match[v] = u;
            bm->match[u] = v;
            return true;
        }
    }
    return false;
}

// Execute the bitmatching algorithm
int exec(BitMatching *bm) {
    int res = 0;
    memset(bm->match, -1, sizeof(bm->match));
    for (int v = 0; v < V; v++) {
        if (bm->match[v] < 0) {
            memset(bm->used, 0, sizeof(bm->used));
            if (dfs(bm, v)) {
                res++;
            }
        }
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    BitMatching bm;
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (!n) break;
        init(&bm);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) {
                    add(&bm, i, j);
                }
            }
        }
        printf("%d\n", exec(&bm));
    }
    return 0;
}
// 
