#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if ((n / 10) % 111 == 0) {
        printf("Yes\n");
    } else if ((n % 1000) % 111 == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 
