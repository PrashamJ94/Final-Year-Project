#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        long long s = 0;
        int x = (int) (log(n) / log(2));
        x++;
        s = -1 * (long long) pow(2, x) + 2 + ((long long) n * (long long) (n + 1)) / 2 - (long long) pow(2, x);
        printf("%lld\n", s);
    }
    return 0;
} // //End of Code.
