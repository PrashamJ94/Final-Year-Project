#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        if(a[i] != ((a[i-1] < a[i]) ? ((a[i-1] < a[i+1]) ? a[i-1] : a[i+1]) : ((a[i] < a[i+1]) ? a[i] : a[i+1]))
            && a[i] != ((a[i-1] > a[i]) ? ((a[i-1] > a[i+1]) ? a[i-1] : a[i+1]) : ((a[i] > a[i+1]) ? a[i] : a[i+1]))) {
            ans++;
        }
    }
    printf("%d\n", ans);
    free(a);

    return 0;
}

// 
