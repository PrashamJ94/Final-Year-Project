#include <stdio.h>
#include <string.h>

int main() {
    char S[1000];
    scanf("%s", S);
    int len = strlen(S);

    for (int i = 2; i <= len; i += 2) {
        int half = (len - i) / 2;
        int isEqual = 1;

        for (int j = 0; j < half; j++) {
            if (S[j] != S[half + j]) {
                isEqual = 0;
                break;
            }
        }

        if (isEqual) {
            printf("%d\n", (len - i));
            break;
        }
    }

    return 0;
}

// 
