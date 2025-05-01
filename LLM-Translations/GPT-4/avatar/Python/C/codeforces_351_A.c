#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, o;
    float arr_sum, res;
    scanf("%d", &n);
    float arr[n];

    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        arr[i] = arr[i] - (int)arr[i];
    }

    float temp;
    for(i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    o = 2 * n - n;
    arr_sum = 0;
    for(i = 0; i < n; i++) {
        arr_sum += arr[i];
    }

    res = 2000000000;
    for(i = 0; i < n + 1; i++) {
        if(i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    printf("%.3f\n", res);

    return 0;
}

// End of Code
