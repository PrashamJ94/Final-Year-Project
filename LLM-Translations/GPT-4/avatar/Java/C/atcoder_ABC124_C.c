#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int testNumber, char *x, int *result) {
    int len = strlen(x);
    char a[len + 1], b[len + 1];
    strcpy(a, x);
    strcpy(b, x);
    int a1 = 0, a2 = 0;

    for (int i = 1; i < len; i++) {
        if (a[i] == a[i - 1]) {
            if (a[i] == '1') a[i] = '0';
            else a[i] = '1';
            a1++;
        }
    }

    for (int i = len - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            if (b[i - 1] == '1') b[i - 1] = '0';
            else b[i - 1] = '1';
            a2++;
        }
    }

    *result = (a1 < a2) ? a1 : a2;
}

int main() {
    char x[100001];
    scanf("%s", x);
    int result;
    solve(1, x, &result);
    printf("%d\n", result);
    return 0;
}
// //End of Code
