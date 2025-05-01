#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int keta(char *s) {
    int n, i, sum = 0;

    if (strlen(s) < 2) {
        return atoi(s);
    }

    for (i = 0; i < strlen(s); i++) {
        sum += s[i] - '0';
    }

    char str[32];
    sprintf(str, "%d", sum);
    return keta(str);
}

int main() {
    char N[10000];
    fgets(N, 10000, stdin);

    if (keta(N) % 9 == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// 
