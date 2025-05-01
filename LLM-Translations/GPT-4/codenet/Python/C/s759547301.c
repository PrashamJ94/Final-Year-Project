#include <stdio.h>
#include <string.h>

int main() {
    char S[10];
    scanf("%s", S);

    if (strcmp(S, "Sunny") == 0) {
        printf("Cloudy");
    }

    if (strcmp(S, "Cloudy") == 0) {
        printf("Rainy");
    }

    if (strcmp(S, "Rainy") == 0) {
        printf("Sunny");
    }

    return 0;
} // 
