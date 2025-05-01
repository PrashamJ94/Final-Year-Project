
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
    int n, i;
    long long ans = 0, pre = 1<<30;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    for(i = 0; i < n; i++) {
        if(pre > a[i]) pre = a[i];
        if(pre < 1) break;
        ans += pre--;
    }
    printf("%lld\n", ans);
    return 0;
}
// End of Code

//This C code does the same operation as your Python code. It reads the number of elements, sorts them in non-increasing order and then calculates the sum of elements based on the conditions from your Python code.
