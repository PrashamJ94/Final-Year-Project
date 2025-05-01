#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    long k;
    int n;

    scanf("%s %ld", str, &k);
    n = strlen(str);

    for (int i = 0; i < k; i++) {
        if (str[i] == '1') {
            if (i == k - 1) {
                printf("1\n");
                return 0;
            }
        } else {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    return 0;
}

// //End of Code
