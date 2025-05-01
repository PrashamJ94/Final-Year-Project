#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[1000];

    scanf("%d", &K);
    getchar(); // To clear the newline character from the input buffer
    fgets(S, sizeof(S), stdin);

    if (strlen(S) - 1 <= K) { // Subtracting 1 to account for the newline character in the input string
        printf("%s", S);
    } else {
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0;
}
// End of Code
