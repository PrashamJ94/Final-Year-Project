#include <stdio.h>
#include <limits.h>

void rememberTheNumber(int nums[], int i, char operations[], long long int *ans) {
    if (i >= 3) {
        return;
    }
    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j] != -1 && nums[k] != -1) {
                int s = nums[j];
                nums[j] = -1;
                int t = nums[k];
                if (operations[i] == '+') {
                    nums[k] = s + t;
                } else if (operations[i] == '*') {
                    nums[k] = s * t;
                }
                if (i == 2 && nums[k] < *ans) {
                    *ans = nums[k];
                }
                rememberTheNumber(nums, i + 1, operations, ans);
                nums[j] = s;
                nums[k] = t;
            }
        }
    }
}

int main() {
    int nums[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }
    char operations[3];
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &operations[i]);
    }
    long long int ans = LLONG_MAX;
    rememberTheNumber(nums, 0, operations, &ans);
    printf("%lld\n", ans);

    return 0;
}

// End of Code
