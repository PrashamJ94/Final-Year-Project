#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int N, M;
int H[100005];
int G[100005][100005];
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &H[i]);
    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    long long ans = 0;
    for(int u = 0; u < N; u++) {
        bool flag = true;
        for (int v = 0; v < N; v++) {
            if (G[u][v] && H[u] <= H[v]) flag = false;
        }
        if (flag) ans++;
    }
    printf("%lld\n", ans);
}

// 
