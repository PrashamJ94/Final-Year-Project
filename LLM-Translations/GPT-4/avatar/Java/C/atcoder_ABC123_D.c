#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long int num1 = *(long long int *)a;
    long long int num2 = *(long long int *)b;
    if (num1 > num2) return -1;
    if (num1 < num2) return 1;
    return 0;
}

int main() {
    int x[3], max = 0, k;
    long long int *a[3], *ans;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = (max > x[i]) ? max : x[i];
    }
    scanf("%d", &k);

    for (int i = 0; i < 3; ++i) {
        a[i] = (long long int *)malloc(x[i] * sizeof(long long int));
        for (int j = 0; j < x[i]; ++j) {
            scanf("%lld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long long int), compare);
    }

    ans = (long long int *)malloc(max * max * max * sizeof(long long int));
    int ans_size = 0;

    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long long int tmp = a[0][i] + a[1][j] + a[2][m];
                    ans[ans_size++] = tmp;
                }
            }
        }
    }

    qsort(ans, ans_size, sizeof(long long int), compare);

    for (int i = 0; i < k; ++i) {
        printf("%lld\n", ans[i]);
    }

    for (int i = 0; i < 3; ++i) {
        free(a[i]);
    }
    free(ans);

    return 0;
}
// //End of Code
