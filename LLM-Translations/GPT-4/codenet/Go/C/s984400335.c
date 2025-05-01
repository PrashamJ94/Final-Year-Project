#include <stdio.h>

int min(int count, int nums[]) {
    int min = nums[0];
    for (int i = 0; i < count; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    int nums[] = {n * a, b};
    printf("%d\n", min(2, nums));

    return 0;
}
// 
