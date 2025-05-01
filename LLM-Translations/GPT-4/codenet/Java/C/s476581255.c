#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int a[], int n, int *count) {
    bool flag = true;
    
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                (*count)++;
                flag = true;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    bubbleSort(a, n, &count);

    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d\n", a[i]);
        }
    }

    printf("%d\n", count);
    return 0;
}

// 
