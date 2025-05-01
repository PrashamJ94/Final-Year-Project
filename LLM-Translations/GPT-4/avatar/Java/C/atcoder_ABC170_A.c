#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    int result = 0;

    while (token != NULL) {
        result += 1;
        if (strcmp(token, "0") == 0) {
            break;
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", result);

    return 0;
}

// //End of Code.
