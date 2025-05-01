
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *lst = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    int *l = (int*) calloc(100001, sizeof(int));
    long long res = 0;
    for(int i = 0; i < n; i++) {
        if(l[lst[i]] == 0) {
            l[lst[i]] = 1;
        } else {
            l[lst[i]]++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(l[lst[i]] > 1) {
            res += n - i - l[lst[i]];
            l[lst[i]]--;
        } else {
            res += n - i - 1;
        }
    }
    printf("%lld\n", res);
    free(lst);
    free(l);
    return 0;
} // End of Code

