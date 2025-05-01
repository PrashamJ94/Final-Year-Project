
#include <stdio.h>
#include <stdlib.h>

#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) printf("%lld\n", (ans))

int main()
{
    ll N, K;
    ll A[200100];
    ll B[200100];
    int now = 1;
    ll cnt = 0;
    scanf("%lld %lld", &N, &K);
    REP(i, N) {
        scanf("%lld", &A[i + 1]);
    }
    REP(i, 200100) {
        B[i] = -1;
    }
    ll j;
    B[1] = 0;
    for (j = 1; j <= K; j++) {
        now = A[now];
        if (B[now] == -1) {
            B[now] = j;
        } else {
            cnt = j;
            break;
        }
    }
    if (j < K) {
        ll tmp;
        tmp = (K - B[now]) % (cnt - B[now]);
        for (ll j = 0; j < tmp; j++) {
            now = A[now];
        }
    }
    fin(now);
    return 0;
}


