#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 1000_006
#define MOD 1000000007

long pow_mod(long base, long exp, long modulus) {
    base %= modulus;
    long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

void solve(int tc) {
    int N;
    long K;
    scanf("%d %ld", &N, &K);
    int A[N];
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);

    int straight[N], straight_size = 0;
    int cycle[N], cycle_size = 0;
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    int curr = 0;

    while (!vis[curr]) {
        vis[curr] = true;
        curr = A[curr] - 1;
    }

    int st = 0;
    while (st != curr) {
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    cycle[cycle_size++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straight_size) {
        printf("%d\n", straight[K] + 1);
    } else {
        K -= straight_size;
        printf("%d\n", cycle[K % cycle_size] + 1);
    }
}

int main() {
    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) solve(tce);
    return 0;
}

// 
