#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(long *)a - *(long *)b);
}

int main(){
    int n, i;
    scanf("%d", &n);
    long ans[n];
    for(i = 0; i < n; i++){
        scanf("%ld", &ans[i]);
    }
    
    qsort(ans, n, sizeof(long), compare);
    
    long count = ans[n - 1];
    for(i = n - 2; i >= 0; i--){
        if(ans[i] < ans[i + 1]){
            count += ans[i];
        } else {
            while(ans[i] >= ans[i + 1]){
                ans[i]--;
            }
            if(ans[i] > 0){
                count += ans[i];
            }
        }
    }
    printf("%ld\n", count);
    return 0;
}

// //End of Code.
