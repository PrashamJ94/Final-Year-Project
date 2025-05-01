#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    
    while (n > 0) {
        int x = n % 2;
        n /= 2;
        if (x == 1) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

// //End of Code
