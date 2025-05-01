#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    bool flag = false;
    
    for (int i = 1; i <= 100000; i++) {
        if (floor(1. * i * .08) == a && b == floor(.1 * i)) {
            printf("%d\n", i);
            flag = true;
            break;
        }
    }
    
    if (!flag) {
        printf("-1\n");
    }
    
    return 0;
}

// 
