#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isSpace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}

// 
