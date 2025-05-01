#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

long MOD = 1000000007L;
char *TOKENS[] = {"A", "C", "G", "T"};
int N;
long **memo;

bool isOK(char *last4) {
    if (strstr(last4, "AGC")) {
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        char vals[5];
        strcpy(vals, last4);
        vals[i] = last4[i + 1];
        vals[i + 1] = last4[i];
        vals[4] = '\0';
        if (strstr(vals, "AGC")) {
            return false;
        }
    }
    return true;
}

long dfs(int current, char *last3) {
    if (memo[current] != NULL && memo[current][(int)(last3[0] - 'A')] != -1) {
        return memo[current][(int)(last3[0] - 'A')];
    }
    if (current == N) {
        return 1;
    }
    long result = 0;
    for (int i = 0; i < 4; ++i) {
        char c = TOKENS[i][0];
        char next_last3[4] = {last3[1], last3[2], c, '\0'};
        if (isOK(strcat(last3, &c))) {
            result = (result + dfs(current + 1, next_last3)) % MOD;
        }
    }
    if (memo[current] == NULL) {
        memo[current] = (long *)malloc(4 * sizeof(long));
        for (int i = 0; i < 4; ++i) {
            memo[current][i] = -1;
        }
    }
    memo[current][(int)(last3[0] - 'A')] = result;
    return result;
}

int main() {
    scanf("%d", &N);
    memo = (long **)calloc(N + 1, sizeof(long *));
    printf("%ld\n", dfs(0, "TTT"));
    for (int i = 0; i < N + 1; ++i) {
        if (memo[i] != NULL) {
            free(memo[i]);
        }
    }
    free(memo);
    return 0;
}
// //End of Code
