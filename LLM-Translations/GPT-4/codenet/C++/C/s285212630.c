#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#define int long long
typedef struct {
    int first;
    int second;
} Pair;
#define rep(i, n) for (int i=0; i<(n); i++)
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22
int N;
Pair G[100000][100000];
int G_size[100000];
int U[MAX_L][100000], R[100000];
long long L[100000];

void dfs(int x, int p, int r, long long l) {
    U[0][x] = p;
    R[x] = r;
    L[x] = l;
    for (int i = 0; i < G_size[x]; i++) {
        Pair pp = G[x][i];
        int t = pp.first;
        if (t == p) continue;
        dfs(t, x, r + 1, l + pp.second);
    }
}

int lca(int a, int b) {
    if (R[a] > R[b]) { int temp = a; a = b; b = temp; }
    for (int k=0; k<MAX_L; k++) {
        if ((R[a] - R[b]) >> k & 1) b = U[k][b];
    }
    if (a == b) return a;
    for (int k=MAX_L-1; k>=0; k--) {
        if (U[k][a] != U[k][b]) {
            a = U[k][a];
            b = U[k][b];
        }
    }
    return U[0][a];
}
long long dist(int x, int y) {
    int g = lca(x, y);
    return L[x] + L[y] - 2LL*L[g];
}

int main() {
    scanf("%lld", &N);
    rep(i, N-1) {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a--, b--;
        Pair p1 = {b, c};
        G[a][G_size[a]++] = p1;
        Pair p2 = {a, c};
        G[b][G_size[b]++] = p2;
    }
    rep(i, MAX_L) rep(j, N) U[i][j] = -1;
    dfs(0, -1, 0, 0);
    for (int i=0; i<MAX_L-1; i++) {
        for (int v=0; v<N; v++) {
            if (U[i][v] == -1) U[i+1][v] = -1;
            U[i+1][v] = U[i][U[i][v]];
        }
    }
    int Q, K;
    scanf("%lld %lld", &Q, &K);
    K--;
    rep(i, Q) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        x--, y--;
        printf("%lld\n", dist(x, K) + dist(K, y));
    }
    return 0;
}
// 
