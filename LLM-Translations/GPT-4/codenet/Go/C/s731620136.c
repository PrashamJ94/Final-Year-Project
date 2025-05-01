#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    char S[10001];

    scanf("%d", &N);
    scanf("%s", S);

    if (N == 0) {
    }

    if (N < 4) {
        printf("0\n");
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        }

        if (S[i] == 'B') {
            nb++;
        }

        if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i += 1;
            j += 1;
            k += 1;
        }
    }

    int tot = nr * nb * ng;
    printf("%d\n", tot - same);

    return 0;
}
// 
