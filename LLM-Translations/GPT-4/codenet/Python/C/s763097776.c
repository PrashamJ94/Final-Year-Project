#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *p = (int *) malloc(n * sizeof(int));
    int *p_copy = (int *) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p_copy[i] = p[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != p_copy[i]) {
            count++;
        }
    }
    
    if (count == 0 || count == 2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    free(p);
    free(p_copy);
    
    return 0;
}
// 
