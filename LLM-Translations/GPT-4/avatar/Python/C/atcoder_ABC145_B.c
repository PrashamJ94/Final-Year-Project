#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[1000];

    scanf("%d", &n);
    scanf("%s", s);

    if (n % 2 != 0) {
        printf("No\n");
    } else {
        int half_n = n / 2;
        if (strncmp(s, s + half_n, half_n) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
} // End of Code
