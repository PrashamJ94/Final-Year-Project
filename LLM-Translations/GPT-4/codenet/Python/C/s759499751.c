
#include <stdio.h>

int main() {
    int n, k, i, w, l, r;
    scanf("%d %d", &n, &k);
    
    char a[n];
    int c[n];
    
    scanf("%s", a);
    
    for(i = 0; i < n; i++) {
        c[i] = 0;
    }
    
    for(i = 1; i < n; i++) {
        if(a[i] == 'C' && a[i - 1] == 'A') {
            c[i] = c[i - 1] + 1;
        } else {
            c[i] = c[i - 1];
        }
    }
    
    for(w = 0; w < k; w++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", c[r - 1] - c[l - 1]);
    }

    return 0;
}


