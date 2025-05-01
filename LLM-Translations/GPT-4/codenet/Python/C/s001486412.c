#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    double below = 0;
    for (int i = 0; i < n; i++) {
        below += 1 / a[i];
    }
    printf("%.9lf\n", 1 / below);
    return 0;
}
// 
