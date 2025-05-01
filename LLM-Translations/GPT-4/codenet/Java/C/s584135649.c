#include <stdio.h>

int main() {
    int i = 0;

    for(i = 1; i <= 5; i++) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            break;
        }
    }

    printf("%d\n", i);
    return 0;
}

// 
