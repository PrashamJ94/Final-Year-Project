
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (k % 2 == 1) {
        printf("%d\n", (n / k) * (n / k) * (n / k));
    } else {
        printf("%d\n", (n / k) * (n / k) * (n / k) + ((n + k / 2) / k) * ((n + k / 2) / k) * ((n + k / 2) / k));
    }
    
    return 0;
}
// 


