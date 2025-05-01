#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    int *l = (int *)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    qsort(l, n, sizeof(int), compare);
    
    for(i = 0; i < n - 2; i++) {
        if(l[i] + 1 == l[i + 1] && l[i] + 2 == l[i + 2]) {
            printf("YES\n");
            break;
        }
    }
    
    if(i == n - 2) {
        printf("NO\n");
    }
    
    free(l);
    
    return 0;
}

// End of Code
