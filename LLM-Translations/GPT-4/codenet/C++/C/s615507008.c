#include <stdio.h>

void solve(long long N, long long T[], long long M, long long P[], long long X[]){
    for(int i = 0; i < M; i++) {
        long long ans = 0;
        for(int j = 0; j < N; j++) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main(){
    long long N;
    scanf("%lld", &N);
    long long T[N];
    for(int i = 0; i < N; i++) scanf("%lld", &T[i]);
    long long M;
    scanf("%lld", &M);
    long long P[M], X[M];
    for(int i = 0; i < M; i++) scanf("%lld %lld", &P[i], &X[i]);
    solve(N, T, M, P, X);
    return 0;
}

// 
