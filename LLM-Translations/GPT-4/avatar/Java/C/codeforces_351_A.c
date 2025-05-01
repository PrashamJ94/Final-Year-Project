#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, non_int = 0, i;
    double sum_before = 0, sum = 0, num, arr[2 * n], max_sum, min_sum, ans;
    
    scanf("%d", &n);
    
    for (i = 0; i < 2 * n; i++) {
        scanf("%lf", &num);
        sum_before += num;
        if (num != floor(num)) non_int++;
        sum += floor(num);
        arr[i] = num;
    }
    
    max_sum = fmin(n, non_int) + sum;
    min_sum = fmax(0, non_int - n) + sum;
    
    if (min_sum > sum_before) ans = (min_sum - sum_before);
    else if (max_sum < sum_before) ans = (sum_before - max_sum);
    else {
        double x = sum_before - floor(sum_before);
        ans = fmin(1 - x, x);
    }
    
    printf("%.3f", ans);
    return 0;
}
// //End of Code.
