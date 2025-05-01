
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Abs(int a);
int Min(int a, int b);
int *CumSum(int nums[], int n, int *length);
int main() {
    int n, i;
    scanf("%d", &n);

    int aa[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    int cumsum_length;
    int *cumsum = CumSum(aa, n, &cumsum_length);

    int ans = 2020202020;
    for(i = 1; i < cumsum_length-1; i++) {
        ans = Min(ans, Abs(cumsum[cumsum_length-1] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printf("%d\n", ans);
    free(cumsum);
    return 0;
}

int Abs(int a) {
    if(a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int *CumSum(int nums[], int n, int *length) {
    *length = n + 1;
    int *sums = (int *)calloc(*length, sizeof(int));

    int i;
    for(i = 0; i < n; i++) {
        sums[i+1] = sums[i] + nums[i];
    }
    return sums;
}


