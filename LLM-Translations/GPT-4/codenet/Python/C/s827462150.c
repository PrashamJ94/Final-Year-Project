#include <stdio.h>

int main() {
    int n, x, y, z, i;
    scanf("%d", &n);

    int A[n];
    for (i = 0; i < n; i++) {
        A[i] = 0;
    }

    x = y = z = 1;

    while (x * x + y * y + z * z + x * y + y * z + z * x <= n) {
        while (x * x + y * y + z * z + x * y + y * z + z * x <= n) {
            while (x * x + y * y + z * z + x * y + y * z + z * x <= n) {
                i = x * x + y * y + z * z + x * y + y * z + z * x;
                A[i - 1]++;
                z++;
            }
            z = 1;
            y++;
        }
        y = z = 1;
        x++;
    }

    for (i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
// 
