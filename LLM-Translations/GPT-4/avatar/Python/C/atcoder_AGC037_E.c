#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool check_normal_dict(char *u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return true;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return false;
        }
    }
    return false;
}

char* get_last_dict(char *s_str, int N) {
    char *U = (char *)malloc((2 * N + 1) * sizeof(char));
    strcpy(U, s_str);
    strcat(U, s_str);
    strrev(U + N);

    char c = U[0];
    int p = 0;
    int minindex = p;

    for (int i = 1; i < 2 * N; i++) {
        if (U[i] < c) {
            c = U[i];
            p = i;
        }
    }

    minindex = p;
    p++;
    
    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p, N)) {
                minindex = p;
            }
        }
        p++;
    }
    
    U[minindex + N] = '\0';
    return U + minindex;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    char S[1001];
    scanf("%s", S);

    bool aaaa = false;
    if (K >= 15) {
        aaaa = true;
    } else if (1 << K >= N) {
        aaaa = true;
    }
    
    if (aaaa) {
        char min_char = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] < min_char) {
                min_char = S[i];
            }
        }
        for (int i = 0; i < N; i++) {
            printf("%c", min_char);
        }
        printf("\n");
        return 0;
    }

    strcpy(S, get_last_dict(S, N));

    if (K == 1) {
        printf("%s\n", S);
    } else {
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (S[i] == S[0]) {
                count++;
            } else {
                break;
            }
        }
        if (count * (1 << (K - 1)) >= N) {
            for (int i = 0; i < N; i++) {
                printf("%c", S[0]);
            }
            printf("\n");
        } else {
            for (int i = 0; i < count * ((1 << (K - 1)) - 1); i++) {
                printf("%c", S[0]);
            }
            printf("%s\n", S);
        }
    }
    return 0;
}
// End of Code
