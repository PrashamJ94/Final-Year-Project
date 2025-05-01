#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int different[num], temp = 0, diffCount = 0;
    qsort(arr, num, sizeof(int), compare);

    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int found = 0;

        for (int j = 0; j < diffCount; j++) {
            if (x % k == 0 && x / k == different[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            different[diffCount++] = x;
            temp = (temp > diffCount) ? temp : diffCount;
        }
    }

    printf("%d\n", temp);

    return 0;
}

// End of Code
