
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long fenwick_tree_update(long *bit, int n, int x, int val) {
    for (; x <= n; x += x & -x)
        bit[x] += val;
}

long fenwick_tree_query(long *bit, int x) {
    long sum = 0;
    for (; x > 0; x -= x & -x)
        sum += bit[x];
    return sum;
}

int solve(int *arr, int n) {
    int sorted[n];
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];

    qsort(sorted, n, sizeof(int), cmpfunc);

    long total = (long)n * (n + 1) / 2;
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        int cur = 0;
        long cnt = 0;
        long bit[2 * n + 2] = {0};

        fenwick_tree_update(bit, 2 * n + 1, n + 1, 1);

        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target ? 1 : -1;
            fenwick_tree_update(bit, 2 * n + 1, cur + n + 1, 1);
            cnt += fenwick_tree_query(bit, cur + n);
        }

        if (cnt >= total / 2 + 1)
            r = mid;
        else
            l = mid + 1;
    }

    return sorted[l];
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", solve(arr, N));

    return 0;
}

//End of Code
