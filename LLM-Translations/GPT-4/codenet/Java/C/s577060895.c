#include <stdio.h>
#include <math.h>

int main() {
    long n;
    double sqrt_n, near_num;
    long ans;

    scanf("%ld", &n);

    sqrt_n = sqrt(n);
    near_num = floor(sqrt_n);

    ans = (long) pow(near_num, 2);

    printf("%ld\n", ans);

    return 0;
}
// 
