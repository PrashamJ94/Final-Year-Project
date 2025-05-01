#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

long long check(long long x, int *A, int N) {
    long long tot = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            int l = -1, r = N;
            while(l + 1 < r) {
                int c = (l + r) / 2;
                if((long long)A[i] * A[c] < x) {
                    r = c;
                } else {
                    l = c;
                }
            }
            tot += N - r;
        } else {
            int l = -1, r = N;
            while(l + 1 < r) {
                int c = (l + r) / 2;
                if((long long)A[i] * A[c] < x) {
                    l = c;
                } else {
                    r = c;
                }
            }
            tot += r;
        }
        if((long long)A[i] * A[i] < x) {
            tot--;
        }
    }
    return tot / 2;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    long long ll = -1e18 - 1, rr = 1e18 + 1;
    while(ll + 1 < rr) {
        long long x = (ll + rr) / 2;
        if(check(x, A, N) < K) {
            ll = x;
        } else {
            rr = x;
        }
    }
    printf("%lld\n", ll);
    return 0;
}
//End of Code

//This C code does the same thing as the Python code: it reads the input parameters `N` and `K`, and then the `N` values of the array `A`. It sorts `A` and uses a binary search to find a value `x` such that there are `K` or more pairs of elements in `A` that multiply to less than `x`. It then prints `x`.
