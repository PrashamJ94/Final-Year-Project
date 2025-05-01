#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    char** words = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        words[i] = (char*)malloc(101 * sizeof(char));
        scanf("%s", words[i]);
    }

    bool ans = true;
    char* past[100];
    int past_count = 0;
    char next[2] = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < past_count; j++) {
            if (strcmp(past[j], words[i]) == 0) {
                ans = false;
                break;
            }
        }
        if (!ans) break;

        past[past_count++] = words[i];

        if (i != 0) {
            if (next[0] != words[i][0]) {
                ans = false;
                break;
            }
        }
        next[0] = words[i][strlen(words[i]) - 1];
    }

    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (int i = 0; i < N; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

// //End of Code
