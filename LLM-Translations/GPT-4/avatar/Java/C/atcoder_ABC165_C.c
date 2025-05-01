
#include <stdio.h>
#include <stdlib.h>

int *a = NULL, *b = NULL, *c = NULL, *d = NULL;
int n = 0, m = 0, q = 0;
long long ans = -100;

void dfs(int *list, int size) {
    if (size == n) {
        long long score = 0;
        for (int i = 0; i < q; ++i) {
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0;
        }
        ans = ans > score ? ans : score;
        return;
    }

    if (size > 0) {
        for (int num = list[size - 1]; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    } else {
        for (int num = 1; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    a = (int *)malloc(q * sizeof(int));
    b = (int *)malloc(q * sizeof(int));
    c = (int *)malloc(q * sizeof(int));
    d = (int *)malloc(q * sizeof(int));

    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--;
        b[i]--;
    }

    int *list = (int *)malloc(n * sizeof(int));
    dfs(list, 0);
    printf("%lld\n", ans);

    free(a);
    free(b);
    free(c);
    free(d);
    free(list);

    return 0;
}

//End of Code
