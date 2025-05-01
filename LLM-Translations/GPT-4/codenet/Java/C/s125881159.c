#include <stdio.h>

int main() {
    int n, d = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        d += temp % 2;
    }

    printf("%s\n", d % 2 == 0 ? "YES" : "NO");

    return 0;
}
