#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, count = 0;
    scanf("%d", &n);
    scanf("%d", &levels);

    int *arr = (int *)malloc(levels * sizeof(int));

    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }

    int level2;
    scanf("%d", &level2);
    int level3 = levels + level2;

    int *arr2 = (int *)malloc(level3 * sizeof(int));

    for (int i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }

    for (int i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }

    int *arr3 = (int *)malloc(n * sizeof(int));
    int j = 0;

    for (int i = 0; i < n; i++) {
        arr3[i] = ++j;
    }

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < level3; x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }

    if (count == n) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}

// //End of Code
