#include <stdio.h>

int main() {
    int t, i, n;
    scanf("%d", &t);
    int count[t + 1];
    
    for (i = 0; i <= t; i++) {
        count[i] = 0;
    }
    
    for (i = 2; i <= t; i++) {
        scanf("%d", &n);
        count[n]++;
    }
    
    for (i = 1; i <= t; i++) {
        printf("%d\n", count[i]);
    }
    
    return 0;
}
// 
