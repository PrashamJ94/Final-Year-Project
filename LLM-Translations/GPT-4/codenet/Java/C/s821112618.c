#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char *s = ".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz";
    char *tok = strtok(s, ":");
    char *k[9];
    int i = 0;

    while (tok != NULL) {
        k[i++] = tok;
        tok = strtok(NULL, ":");
    }

    while (n-- > 0) {
        char c[1000];
        scanf("%s", c);
        int l = -1, a = 0;
        for (int i = 0; i < strlen(c); i++) {
            if (c[i] != '0') {
                a = c[i] - '1';
                l = (l + 1) % strlen(k[a]);
            } else if (l >= 0) {
                printf("%c", k[a][l]);
                l = -1;
            }
        }
        printf("\n");
    }
    return 0;
}

/*  */
