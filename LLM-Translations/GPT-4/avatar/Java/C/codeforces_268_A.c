#include <stdio.h>

int main() {
    int n, result = 0, i, j;
    scanf("%d", &n);
    
    int h[n];
    int g[n];
    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &h[i], &g[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (h[i] == g[j]) {
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
// //End of Code
