#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int min = INT_MAX;
    int countNegatives = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int abs = abs(num);
        sum += abs;
        min = (min < abs) ? min : abs;
        if (num < 0) {
            countNegatives++;
        }
    }

    printf("%ld\n", countNegatives % 2 == 0 ? sum : sum - (min*2));

    return 0;
}
/*  */
