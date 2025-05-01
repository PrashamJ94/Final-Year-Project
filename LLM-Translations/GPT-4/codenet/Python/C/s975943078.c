#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int bisect_left(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N], sum_A[N + 1];
    sum_A[0] = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] = (A[i] % K) - 1;
    }

    int count = 0;
    int modK[K][N + 1], modK_lengths[K];
    for (int i = 0; i < K; i++) modK_lengths[i] = 0;
    modK[0][0] = 0;
    modK_lengths[0] = 1;

    for (int i = 0; i < N; i++) {
        sum_A[i + 1] = (sum_A[i] + A[i]) % K;
        int key = sum_A[i + 1];
        modK[key][modK_lengths[key]++] = i + 1;
    }

    for (int key = 0; key < K; key++) {
        qsort(modK[key], modK_lengths[key], sizeof(int), compare);
        for (int i = 0; i < modK_lengths[key]; i++) {
            int a = modK[key][i];
            count += bisect_left(modK[key], modK_lengths[key], a + K) - i - 1;
        }
    }

    printf("%d\n", count);
}

int main() {
    solve();
    return 0;
}
// 
