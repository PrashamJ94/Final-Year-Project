#include <stdio.h>
#include <limits.h>

int main() {
    int n, sum = 0, max = INT_MIN, min = INT_MAX;
    scanf("%d", &n);
    int l[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
        sum += l[i];
        if (max < l[i]) {
            max = l[i];
        }
        if (min > l[i]) {
            min = l[i];
        }
    }

    printf("%d %d %d\n", min, max, sum);
    return 0;
}

// 
