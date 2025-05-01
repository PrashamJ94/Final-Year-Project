#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char soz[1000];
    scanf("%s", soz);
    int len = strlen(soz);
    int a[len + 1];
    a[0] = 0;
    
    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i] += 1;
        }
    }
    
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        int m, l;
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

// End of Code
