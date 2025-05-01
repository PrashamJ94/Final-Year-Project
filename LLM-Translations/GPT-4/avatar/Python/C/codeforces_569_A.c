#include<stdio.h>

int main() {
    int t, s, q;
    int ans = 0;
    scanf("%d %d %d", &t, &s, &q);

    while (s < t) {
        s *= q;
        ans += 1;
    }

    printf("%d", ans);

    return 0;
}

// End of Code
