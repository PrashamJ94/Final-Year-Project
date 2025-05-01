#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
    int n, i, od = 0, sum = 0, ok = 0;
    scanf("%d", &n);
    int *lst = malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    qsort(lst, n, sizeof(int), compare);
    for(i = 0; i < n; i++) {
        if(lst[i] & 1) {
            od += 1;
        }
    }
    for(i = 0; i < n; i++) {
        if(lst[i] % 2 == 0) {
            sum += lst[i];
        } else {
            if(ok || od > 1) {
                sum += lst[i];
                od -= 1;
                ok = !ok;
            }
        }
    }
    printf("%d", sum);
    free(lst);
    return 0;
} // End of Code
