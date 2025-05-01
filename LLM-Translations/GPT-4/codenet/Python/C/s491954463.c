#include <stdio.h>

int main() {
    int n, m, i, a1, b1;
    scanf("%d%d", &n, &m);
    
    int a[m], b[m];
    for (i = 0; i < m; i++) {
        scanf("%d%d", &a1, &b1);
        a[i] = a1;
        b[i] = b1;
    }

    for (i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (a[j] == i || b[j] == i) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    
    return 0;
}
// 


