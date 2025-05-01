
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y) {
    if (x > y) {
        return y;
    } else {
        return x;
    }
}

int main() {
    char S[100001];
    scanf("%s", S);

    int l0 = 0, l1 = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++;
        } else {
            l1++;
        }
    }
    printf("%d\n", 2 * min(l0, l1));

    return 0;
}


