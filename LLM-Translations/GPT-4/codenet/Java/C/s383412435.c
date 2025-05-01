#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    long a[N];
    int tmp;
    int ans = 0;
    for (int z = 0; z < N; z++) {
        scanf("%ld", &a[z]);
    }
    qsort(a, N, sizeof(long), compare);
    if (N == 1 && a[0] > 1) {
        ans = 1;
    } else {
        for (int j = 0; j < N; j++) {
            if (j == 0 || a[j] != a[j - 1]) {
                tmp = 1;
                for (int i = j + 1; i < N; i++) {
                    if (a[j] == a[i]) {
                        tmp++;
                    } else {
                        break;
                    }
                }

                if (tmp > a[j]) {
                    ans += tmp - a[j];
                } else if (tmp < a[j]) {
                    ans += tmp;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// 
