#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LLONG_MAX
#define LEN 1000001

void atcoder_ABC167_D(long N, long K, int A[]) {
    bool used[LEN] = {0};
    int idx[LEN] = {0};
    int pos[LEN] = {0};
    int next = 0, cur = 0;

    while (!used[next]) {
        used[next] = true;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next] - 1;
        cur++;
    }

    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);

    if (b > K) ans = (int)K;

    printf("%d\n", pos[ans] + 1);
}

int main() {
    int N;
    long K;
    scanf("%d %ld", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    atcoder_ABC167_D(N, K, A);
    return 0;
}

// //End of Code
