#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int mod = 1000000007;
const int INF = 1000000007;

int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(int arr[], int size, int n, int ***result, int *count) {
    if (n == 1) {
        (*result)[*count] = (int *)malloc(size * sizeof(int));
        memcpy((*result)[*count], arr, size * sizeof(int));
        (*count)++;
    } else {
        for (int i = 0; i < n; i++) {
            permutations(arr, size, n - 1, result, count);
            if (n % 2 == 1) {
                swap(&arr[i], &arr[n - 1]);
            } else {
                swap(&arr[0], &arr[n - 1]);
            }
        }
    }
}

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int *rs = (int *)malloc(R * sizeof(int));
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    int **costs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // ワーシャルフロイド法で最短経路を算出
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // 順列で訪問先の順序をすべて試す
    int **perms = (int **)malloc(3628800 * sizeof(int *)); // 10! = 3628800
    int count = 0;
    permutations(rs, R, R, &perms, &count);

    int ans = INF;
    for (int i = 0; i < count; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    free(rs);
    for (int i = 0; i < count; i++) {
        free(perms[i]);
    }
    free(perms);

    return 0;
}
// 
