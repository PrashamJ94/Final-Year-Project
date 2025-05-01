
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);
    int *w = malloc(n * sizeof(int));
    int *d = malloc(n * sizeof(int));
    int count = 0;
  
    for(i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
  
    for(i = 0; i < n; i++) {
        if(sum - w[i] == w[i] * (n - 1)) {
            d[count] = i + 1;
            count++;
        }
    }
  
    printf("%d\n", count);
    for(i = 0; i < count; i++) {
        printf("%d ", d[i]);
    }
  
    free(w);
    free(d);
    return 0;
} // End of Code


