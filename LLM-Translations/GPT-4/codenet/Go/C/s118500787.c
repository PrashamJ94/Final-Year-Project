#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[1001], T[1001];
    scanf("%s %s", S, T);

    int max = 0;
    int lenS = strlen(S);
    int lenT = strlen(T);

    for (int i = 0; i <= lenS - lenT; i++) {
        int c = 0;
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        if (max < c) {
            max = c;
        }
    }
    printf("%d\n", lenT - max);

    return 0;
}

// 
