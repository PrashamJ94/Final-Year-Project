#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *ans = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n - 1; i++){
        int a;
        scanf("%d", &a);
        a--;
        ans[a]++;
    }
    for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
    free(ans);
    return 0;
}
// 
