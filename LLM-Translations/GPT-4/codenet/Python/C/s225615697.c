#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m1 = 0;
    for (int i = 0; i < n; i++) {
        m1 += a[i] * ((i % 2 == 0) ? 1 : -1);
    }
    m1 /= 2;

    int m[n];
    m[0] = m1;
    for (int i = 1; i < n; i++) {
        m[i] = a[i - 1] - m[i - 1];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", m[i] * 2);
    }

    return 0;
}
// 
