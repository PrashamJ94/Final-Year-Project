
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define N 100010

typedef long long LL;
typedef struct {
    int to;
    int pre;
    int c;
} edge;

edge e[N << 1];
int u[N], l = 0;

void ins(int a, int b, int c) {
    e[++l] = (edge){b, u[a], c};
    u[a] = l;
}

#define v e[i].to
#define ec e[i].c

int n, m;
bool vis[N], ok;
LL cnt[3];
int d[N];
int T;

void dfs(int x, int l) {
    vis[x] = true;
    cnt[l]++;
    d[x] = l;
    for (int i = u[x]; i; i = e[i].pre) {
        T++;
        if (!vis[v]) dfs(v, (l + ec) % 3);
        else if ((l + ec) % 3 != d[v]) ok = false;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        ins(a, b, 1);
        ins(b, a, 2);
    }
    LL ans = 0;
    rep(i, 1, n) if (!vis[i]) {
        T = 0;
        rep(j, 0, 2) cnt[j] = 0;
        ok = true;
        dfs(i, 0);
        LL s = cnt[0] + cnt[1] + cnt[2];
        if (!ok) ans += s * s;
        else {
            if (cnt[0] && cnt[1] && cnt[2]) {
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
            } else {
                ans += T / 2;
            }
        }
    }
    printf("%lld\n", ans);
}


