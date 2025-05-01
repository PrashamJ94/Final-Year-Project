#include <stdio.h>

int main() {
    int n, t = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        if((i + 1) & 1) {
            t += 1;
        }
    }
    printf("%f", (float) t / n);
    return 0;
} // End of Code
