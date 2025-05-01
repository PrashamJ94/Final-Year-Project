#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int curr = r;
    int s = 0;
    while (curr) {
        s += 1;
        curr /= 10;
    }
    int first = pow(10, s);
    int second = first / 2;
    int ans = -1;
    int i, k;
    char rev[10];
    for(i = l; i <= r; i++) {
        if (i >= l && i <= r) {
            curr = i;
            for (k = 0; k < strlen(str(curr)); k++) {
                rev[k] = '9' - (str(curr)[k] - '0');
            }
            ans = max(ans, atoi(rev) * curr);
        }
    }
    printf("%d\n", ans);
    return 0;
} // End of Code
