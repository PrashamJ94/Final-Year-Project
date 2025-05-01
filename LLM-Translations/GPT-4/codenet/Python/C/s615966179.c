
#include <stdio.h>

int main() {
    int n, a, b, ans, r;
    scanf("%d %d %d", &n, &a, &b);
    ans = n / (a + b) * a;
    r = (n % (a + b) < a) ? n % (a + b) : a;
    ans += r;
    printf("%d\n", ans);
    return 0;
}


