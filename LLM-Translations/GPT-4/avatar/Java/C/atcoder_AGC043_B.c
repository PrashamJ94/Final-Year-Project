#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int cal(char *s, char c) {
    int n = strlen(s);
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c && (m & i) == i) {
            ans ^= 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    char sb[n];
    for (int i = 1; i < n; i++) {
        sb[i - 1] = abs(s[i] - s[i - 1]) + '0';
    }
    sb[n - 1] = '\0';

    if (n == 2) {
        printf("%c\n", sb[0]);
        return;
    }

    if (strchr(sb, '1') != NULL) {
        printf("%d\n", cal(sb, '1'));
    } else {
        printf("%d\n", cal(sb, '2') * 2);
    }
}

int main() {
    solve();
    return 0;
}

// //End of Code
