#include <stdio.h>

int main() {
    int n;
    float res = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float x;
        char u[4];
        scanf("%f %s", &x, u);

        if (strcmp(u, "BTC") == 0) {
            res += x * 380000;
        } else {
            res += x;
        }
    }

    printf("%.2f\n", res);
    return 0;
}
// 
