#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int q;
    scanf("%d", &q);

    int operation[3];
    bool n = false;
    char left[100] = "";
    char right[100] = "";
    char c[2];

    for (int i = 0; i < q; i++) {
        scanf("%d", &operation[0]);

        if (operation[0] == 1) {
            n = !n;
        }

        if (operation[0] == 2) {
            scanf("%d", &operation[1]);
            scanf("%s", c);

            if (n) {
                operation[1] = operation[1] == 1 ? 2 : 1;
            }

            if (operation[1] == 1) {
                char temp[100] = "";
                strcpy(temp, c);
                strcat(temp, left);
                strcpy(left, temp);
            } else if (operation[1] == 2) {
                strcat(right, c);
            }
        }
    }

    strcat(left, s);
    strcat(left, right);

    if (n) {
        int len = strlen(left);
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", left[i]);
        }
    } else {
        printf("%s", left);
    }

    return 0;
}
// 
