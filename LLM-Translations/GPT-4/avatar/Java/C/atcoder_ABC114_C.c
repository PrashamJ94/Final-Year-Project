#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    long i = 357;
    int c = 0;
    while (i <= N) {
        char s[20];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7"))
            c++;

        char sb[20] = "";
        bool f = false;
        for (int j = 0; j < strlen(s); j++) {
            char a = s[strlen(s) - 1 - j];
            if (f) {
                strncat(sb, &a, 1);
            } else {
                if (a == '3') {
                    a = '5';
                    f = true;
                } else if (a == '5') {
                    a = '7';
                    f = true;
                } else {
                    a = '3';
                }
                strncat(sb, &a, 1);
            }
        }
        if (!f)
            strcat(sb, "3");

        char sb2[20] = "";
        for (int j = strlen(sb) - 1; j >= 0; j--) {
            sb2[strlen(sb) - 1 - j] = sb[j];
        }
        i = atol(sb2);
    }
    printf("%d\n", c);
    return 0;
}
// //End of Code
