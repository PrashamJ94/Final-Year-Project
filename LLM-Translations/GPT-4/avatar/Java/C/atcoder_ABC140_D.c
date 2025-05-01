#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s", S);
    char c1[N+1], c3[N+1];
    strcpy(c1, S);
    strcpy(c3, S);
    bool flag = false;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag = true;
            c1[i] = 'R';
        }
    }

    flag = false;
    count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag = true;
            c3[i] = 'L';
        }
    }

    count = 1;
    int sum1 = 0;
    char bef = c1[0];
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) {
            count++;
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = c1[i];
            sum1 += count - 1;
            count = 1;
        }
    }

    count = 1;
    int sum3 = 0;
    bef = c3[0];
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count++;
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count - 1;
            count = 1;
        }
    }

    printf("%d\n", (sum1 > sum3) ? sum1 : sum3);
    return 0;
}

// //End of Code
