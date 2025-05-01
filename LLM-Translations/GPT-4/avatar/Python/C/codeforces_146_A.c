#include <stdio.h>

int main() {
    int n, h1 = 0, h2 = 0, x = 0;
    scanf("%d", &n);
    char number[n + 1];
    scanf("%s", number);

    for (int i = 0; i < n; i++) {
        if (number[i] != '4' && number[i] != '7') {
            printf("NO\n");
            x = 1;
            break;
        }
        if (i < n / 2) {
            h1 += number[i] - '0';
        } else {
            h2 += number[i] - '0';
        }
    }
    if (!x) {
        if (h1 == h2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
// End of Code
