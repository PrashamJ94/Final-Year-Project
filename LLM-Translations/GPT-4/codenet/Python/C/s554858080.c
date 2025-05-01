#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    char num[100] = "";

    while (token != NULL) {
        strcat(num, token);
        token = strtok(NULL, " ");
    }

    int number = atoi(num);

    if (number % 4 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
// 
