#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int x[200010];
    for (int i = 0; i < 200010; i++) {
        x[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        x[a[i] - 1]++;
    }
    qsort(x, 200010, sizeof(int), compare);
    int ans = 0;
    for (int i = 0; i <= 200010 - k - 1; i++) {
        ans += x[i];
    }
    printf("%d\n", ans);
    return 0;
}

// 
