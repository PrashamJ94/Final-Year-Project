#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 1000
#define MAXM 2000
#define INF (1LL << 62)

int N, M;
int a[MAXM], b[MAXM], c[MAXM];
long long dist[MAXN];
bool navigate[MAXN];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        c[i] = -c[i];
    }

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }

    dist[0] = 0;

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == INF) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    long long ans = dist[N - 1];

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == INF) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = true;
            }
            if (navigate[a[i] - 1] == true) {
                navigate[b[i] - 1] = true;
            }
        }
    }

    if (navigate[N - 1]) {
        printf("inf\n");
    } else {
        printf("%lld\n", -ans);
    }

    return 0;
}

// 
