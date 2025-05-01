#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n, i, unique = 1;
    scanf("%d", &n);
    
    int *A = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    for(i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] == A[j]) {
                unique = 0;
                break;
            }
        }
        if(!unique) {
            break;
        }
    }
    
    if(unique) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    
    free(A);
    return 0;
}
// 
