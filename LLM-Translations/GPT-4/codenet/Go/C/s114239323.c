#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a[], int len);
int min(int a[], int len);
int sum(int a[], int len);
int abs(int a);
int min2(int a, int b);

int main() {
    
    int N;
    scanf("%d", &N);
    int h[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }
    
    int dp[N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    dp[1] = abs(h[0] - h[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = min2(dp[i - 1] + abs(h[i] - h[i - 1]),
                     dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    printf("%d\n", dp[N-1]);

    return 0;
}

int max(int a[], int len) {
    int r = a[0];
    for (int i = 0; i < len; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

int min(int a[], int len) {
    int r = a[0];
    for (int i = 0; i < len; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

int sum(int a[], int len) {
    int r = 0;
    for (int i = 0; i < len; i++) {
        r += a[i];
    }
    return r;
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int min2(int a, int b) {
    return (a < b) ? a : b;
}

// 
