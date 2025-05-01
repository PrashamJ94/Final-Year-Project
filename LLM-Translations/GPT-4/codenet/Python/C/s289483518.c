#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int ope[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ope[i][0], &ope[i][1]);
    }
    qsort(ope, m, sizeof(ope[0]), cmp);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < ope[j][1]) {
            a[i] = ope[j][1];
            ope[j][0] -= 1;
            if (ope[j][0] == 0) {
                j += 1;
                if (j == m) {
                    break;
                }
            }
        } else {
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%d\n", sum);
    return 0;
} // 
