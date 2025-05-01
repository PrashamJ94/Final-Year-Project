#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long MOD = 1000000007;

long f(int n) {
    long res = 1;
    for(int i = 2; i<=n; i++) res = (res*i)%MOD;
    return res;
}

int main() {
    int xx[2];
    scanf("%d %d", &xx[0], &xx[1]);

    int min = fmin(xx[0], xx[1]);
    int max = fmax(xx[0], xx[1]);
    long res;

    if(min == max) {
        long f_val = f(min);
        res = (2*f_val*f_val)%MOD;
    } else if(min + 1 == max){
        long f_val = f(min);
        res = (f_val*((f_val*max)%MOD))%MOD;
    } else {
        res = 0;
    }

    printf("%ld\n", res);
    return 0;
}

// 
