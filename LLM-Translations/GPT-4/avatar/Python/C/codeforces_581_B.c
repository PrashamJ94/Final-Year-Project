#include <stdio.h>

int main() {
    int n, i, mx;
    scanf("%d", &n);
    int arr[n];
    int ans[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mx = arr[n - 1];
    for(i = n - 2; i >= 0; i--) {
        ans[i] = mx - arr[i] + 1 > 0 ? mx - arr[i] + 1 : 0;
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    
    for(i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}

// End of Code
