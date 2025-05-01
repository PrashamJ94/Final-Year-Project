
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isSpace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int main() {
    int n, k;
    n = getInt();
    k = getInt();
    if (n % k == 0) {
        printf("%d\n", 0);
    } else {
        printf("%d\n", 1);
    }
    return 0;
}


