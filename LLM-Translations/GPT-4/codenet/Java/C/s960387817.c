#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp, uniqueCount = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (i == j) {
            uniqueCount++;
        }
    }

    printf("%d\n", uniqueCount);
    free(arr);

    return 0;
}
// 
