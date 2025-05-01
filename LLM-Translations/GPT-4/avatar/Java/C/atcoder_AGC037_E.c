#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N + 1], T[N + 1], revU[2 * N + 1], sDash[N + 1];
    scanf("%s", S);

    bool firstTime = true;
    int step = 1;
    while (K > 0) {
        strncpy(T, S, N);
        T[N] = '\0';
        reverse(T, N);

        strncpy(revU, S, N);
        strncpy(revU + N, T, N);
        revU[2 * N] = '\0';
        reverse(revU, 2 * N);

        strncpy(sDash, S, N);
        sDash[N] = '\0';

        for (int i = N; i >= 0; i -= step) {
            if (i + N > 2 * N) {
                continue;
            }
            char tmp[N + 1];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';
            if (strcmp(sDash, tmp) > 0) {
                strncpy(sDash, tmp, N);
                sDash[N] = '\0';
            } else {
                if (!firstTime) {
                    break;
                }
            }
        }

        if (firstTime) {
            firstTime = false;
            if (pow(2, K) > N) {
                char c = sDash[0];
                for (int i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                return 0;
            }
        } else {
            step += step;
        }

        K--;
        strncpy(S, sDash, N);
        S[N] = '\0';
        reverse(S, N);
    }

    reverse(S, N);
    printf("%s\n", S);
    return 0;
}

// //End of Code.
