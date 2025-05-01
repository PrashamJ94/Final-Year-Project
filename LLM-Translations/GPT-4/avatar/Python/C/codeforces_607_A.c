#include <stdio.h>

int main() {
    int n, a, b, i, mx = 0;
    scanf("%d", &n);
    
    int l[1000010] = {0};
    int dp[1000010] = {0};
    
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        l[a] = b;
    }
    
    if(l[0] > 0) {
        dp[0] = 1;
    }
    
    for(i = 1; i < 1000010; i++) {
        if(l[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            if(l[i] >= i) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - l[i] - 1] + 1;
            }
        }
        if(dp[i] > mx) {
            mx = dp[i];
        }
    }
    
    printf("%d", n - mx);
    
    return 0;
}

// End of Code.
