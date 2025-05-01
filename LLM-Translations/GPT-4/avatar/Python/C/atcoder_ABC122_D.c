#include <stdio.h>
#include <string.h>

#define mod 1000000007

int n;
int memo[101][65];

int ok(char* last4) {
    char t[5];
    for (int i = 0; i < 4; i++) {
        strcpy(t, last4);
        if (i >= 1) {
            char temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        }
        if (strstr(t, "AGC") != NULL) {
            return 0;
        }
    }
    return 1;
}

int dfs(int cur, char* last3) {
    if (memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16] != -1) {
        return memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    char c[2] = "\0";
    for (char ch = 'A'; ch <= 'T'; ch += 6) {
        c[0] = ch;
        if (ok(strcat(last3, c))) {
            ret = (ret + dfs(cur + 1, strcat(&last3[1], c))) % mod;
        }
    }
    memo[cur][last3[0] - 'A' + (last3[1] - 'A') * 4 + (last3[2] - 'A') * 16] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dfs(0, "TTT"));
    return 0;
}

//End of Code.
