#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    
    int ans = 1000000000;
    
    for (int i = 0; i <= 100; i++) {
        int tmp[n];
        for (int j = 0; j < n; j++) {
            tmp[j] = abs(i - x[j]) * abs(i - x[j]);
        }
        
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += tmp[j];
        }
        
        if (sum < ans) {
            ans = sum;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

// 
