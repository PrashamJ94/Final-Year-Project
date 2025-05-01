#include <stdio.h>

int main() {
    int firstline, total = 0, A, G;
    scanf("%d", &firstline);

    char memory[firstline + 1];
    memory[firstline] = '\0';

    for (int x = 0; x < firstline; x++) {
        scanf("%d %d", &A, &G);
        if (total + A <= 500) {
            total += A;
            memory[x] = 'A';
        } else {
            total -= G;
            memory[x] = 'G';
        }
    }
    printf("%s\n", memory);

    return 0;
}

// End of Code
