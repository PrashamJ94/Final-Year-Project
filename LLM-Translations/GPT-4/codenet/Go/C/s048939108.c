
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool starts_with(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

int main() {
    char S[1001];
    scanf("%s", S);

    if (starts_with(S, "YAKI")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


