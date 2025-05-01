#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int nums[3];

    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);

    qsort(nums, 3, sizeof(int), compare);

    printf("%d\n", nums[0] * 10 + nums[1] + nums[2]);

    return 0;
}
// 
