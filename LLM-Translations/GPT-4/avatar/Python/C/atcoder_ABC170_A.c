#include <stdio.h>

int main() {
    int a[50], i, n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++) {
        if(a[i] == 0) {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
} // End of Code
