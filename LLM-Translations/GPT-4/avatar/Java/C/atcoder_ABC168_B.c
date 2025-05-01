#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[101];

    scanf("%d", &K);
    scanf("%s", S);

    if (strlen(S) <= K) {
        printf("%s\n", S);
    } else {
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0;
}
// //End of Code
