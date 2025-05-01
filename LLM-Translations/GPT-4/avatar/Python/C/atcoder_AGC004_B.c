#include <stdio.h>
#include <limits.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int b[n][n];
    for(int i = 0; i < n; i++) {
        int m = a[i];
        for(int j = 0; j < n; j++) {
            int k = i - j;
            if(k < 0) {
                k += n;
            }
            m = (m < a[k]) ? m : a[k];
            b[j][i] = m;
        }
    }
    long long m = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            sum += b[i][j];
        }
        m = (m < (sum + x * i)) ? m : (sum + x * i);
    }
    printf("%lld\n", m);
    return 0;
} // End of Code
