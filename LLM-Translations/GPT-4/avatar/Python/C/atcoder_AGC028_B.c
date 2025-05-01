#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define M 1000000
#define Nsq 1000

long long int fact[M];
long long int inv[Nsq];
long long int A[Nsq];
long long int temp[Nsq];

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < M; i++) {
        fact[i] = 1;
    }

    for(int n = 1; n < Nsq; n++) {
        for(int i = 0; i < Nsq; i++) {
            fact[i + Nsq*n] = (fact[i + Nsq*(n - 1)]*n)%MOD;
        }
    }

    for(int n = 1; n < Nsq; n++) {
        for(int i = 0; i < Nsq; i++) {
            fact[i + Nsq*n] *= fact[(n - 1)*Nsq + Nsq - 1];
            fact[i + Nsq*n] %= MOD;
        }
    }

    for(int i = 0; i < N; i++) {
        inv[i] = (MOD - MOD/(i + 1))*(inv[MOD%(i + 1)])%MOD;
    }

    for(int i = 1; i < N; i++) {
        inv[i] = (inv[i] + inv[i - 1])%MOD;
    }

    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        temp[i] = (inv[i] + inv[N - 1 - i] - 1)%MOD;
    }

    long long int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = (ans + (A[i]*temp[i])%MOD)%MOD;
    }

    ans = (ans*fact[N])%MOD;

    printf("%lld\n", ans);
    return 0;
}

