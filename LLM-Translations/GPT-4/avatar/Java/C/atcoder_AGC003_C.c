
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, i, bin = 0, diff = 0;
    scanf("%d", &N);

    int nums[N], map[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        map[i] = i;
    }

    qsort(nums, N, sizeof(int), compare);

    for (i = 0; i < N; i++) {
        int num = nums[i];
        int idx = map[i];

        if ((bin % 2) != (idx % 2)) {
            diff++;
        }

        bin++;
        bin %= 2;
    }

    int ans = (diff / 2);
    printf("%d\n", ans);

    return 0;
}

// //End of Code
