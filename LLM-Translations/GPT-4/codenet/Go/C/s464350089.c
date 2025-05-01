#include <stdio.h>
#include <stdlib.h>

const int mod = 1000000007;

int main() {
    int h, n, a = 0;
    scanf("%d %d", &h, &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }

    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
// 
