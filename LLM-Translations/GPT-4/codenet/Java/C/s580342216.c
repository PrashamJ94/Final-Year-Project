#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_case();
int* strToIntArray(char *str, int sz);
int lcs(char *A, char *B, int sz_a, int sz_b, int** dp);
char* getLCS(char *X, char *Y, int m, int n, int** dp);

int main() {
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        if(line[0]=='\n') continue;
        run_case(line);
    }

    return 0;
}

void run_case(char *line) {
    int N, K;

    sscanf(line, "%d %d", &N, &K);

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
    return;
}

int* strToIntArray(char *str, int sz) {
    int *res = (int *) malloc(sz * sizeof(int));
    int i = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        res[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return res;
}

int lcs(char *A, char *B, int sz_a, int sz_b, int** dp) {
    for (int i = 0; i <= sz_a; i++) dp[i][0] = 0;
    for (int j = 0; j <= sz_b; j++) dp[0][j] = 0;

    for (int i = 1; i <= sz_a; i++) {
        for (int j = 1; j <= sz_b; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[sz_a][sz_b];
}

char* getLCS(char *X, char *Y, int m, int n, int** dp) {
    int index = dp[m][n];
    int temp = index;

    char *lcs = (char *) malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

// 
