#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int swapCount = 0;
    
    for (i = 0; i < n; i++) {
        int mini = i;
        
        for (j = i; j < n; j++) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        
        if (mini != i) {
            int v = a[mini];
            a[mini] = a[i];
            a[i] = v;
            
            swapCount++;
        }
    }
    
    printf("%d", a[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n%d\n", swapCount);

    return 0;
}
// 
