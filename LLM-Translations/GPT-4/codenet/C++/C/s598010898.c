#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main(void) {
    int n, sum = 0;
    scanf("%d", &n);
    int* a = (int*) malloc(n * sizeof(int));
    int* b = (int*) malloc(n * sizeof(int));
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) {
        scanf("%d", &b[i]);
        if (a[i] - b[i] > 0) {
            sum += a[i] - b[i];
        }
    }
    printf("%d\n", sum);
    free(a);
    free(b);
    return 0;
}
// 
