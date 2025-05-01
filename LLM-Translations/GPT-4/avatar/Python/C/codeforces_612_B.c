#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, res = 0;
    scanf("%d", &n);
    int a[n], b[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }

    for(int i = 1; i < n; i++){
        res += abs(b[i] - b[i - 1]);
    }

    printf("%d", res);

    return 0;
}

//End of Code
