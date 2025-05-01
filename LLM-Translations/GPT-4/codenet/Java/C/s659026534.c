#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        count += i;
    }
    printf("%d\n", count);

    return 0;
}

// 
