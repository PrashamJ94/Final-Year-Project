
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
   return (*(int *)a - *(int *)b);
}

void func(int *a, int size) {
    int min = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            size--;
            for (int j = i; j < size; j++) {
                a[j] = a[j + 1];
            }
            i--;
        } else {
            if (min != 0) {
                a[i] = a[i] % min;
                if (a[i] == 1) {
                    printf("1\n");
                    exit(0);
                }
            } else {
                min = a[i];
            }
        }
    }
    qsort(a, size, sizeof(int), compare);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    if (n == 1) {
        scanf("%d", &a[0]);
        printf("%d\n", a[0]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    if (a[n - 1] == 0) {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    while (1) {
        if (n == 1) {
            ans = a[0];
            break;
        }
        func(a, n);
    }
    printf("%d\n", ans);
    return 0;
}

// //End of Code
