
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max(long long x, long long y) {
    return x > y ? x : y;
}

long long min(long long x, long long y) {
    return x < y ? x : y;
}

long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

void solve() {
    int N;
    scanf("%d", &N);
    long long T[N], A[N];
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &T[i], &A[i]);
    }
    long long t = T[0], a = A[0];
    for(int i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    printf("%lld\n", t + a);
}

int main() {
    solve();
    return 0;
}


