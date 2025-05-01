#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char s[n], t[m];
    scanf("%s", s);
    scanf("%s", t);

    int aa = gcd(n, m);
    int bb = lcm(n, m);
    int cc = aa / bb;
    for (int i = 0; i < aa; i++) {
        if (s[n / aa * i] != t[m / aa * i]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", bb);

    return 0;
}
// 
