#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

const long mod = 1000000007;

void solve() {
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}

// 
