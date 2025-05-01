#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct {
    int first;
    int second;
} PII;
typedef struct {
    ll first;
    ll second;
} PLL;

#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int comp(const void* a, const void* b) {
    ll x = *(ll*)a;
    ll y = *(ll*)b;
    return x > y ? -1 : (x < y ? 1 : 0);
}

int main() {
    int X, Y, Z, K;
    scanf("%d %d %d %d", &X, &Y, &Z, &K);
    ll A[X], B[Y], C[Z];
    for (int i = 0; i < X; i++)
        scanf("%lld", &A[i]);
    for (int i = 0; i < Y; i++)
        scanf("%lld", &B[i]);
    for (int i = 0; i < Z; i++)
        scanf("%lld", &C[i]);

    qsort(A, X, sizeof(ll), comp);
    qsort(B, Y, sizeof(ll), comp);
    qsort(C, Z, sizeof(ll), comp);

    ll AB[X * Y];
    int idx = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            AB[idx++] = A[i] + B[j];
        }
    }

    qsort(AB, X * Y, sizeof(ll), comp);
    ll ABC[K * Z];
    idx = 0;
    for (int i = 0; i < K && i < X * Y; i++) {
        for (int j = 0; j < Z; j++) {
            ABC[idx++] = AB[i] + C[j];
        }
    }

    qsort(ABC, K * Z, sizeof(ll), comp);
    for (int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }

    return 0;
}

// 
