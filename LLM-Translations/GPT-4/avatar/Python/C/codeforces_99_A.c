
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char l[100];
    fgets(l, 100, stdin);
    char *s = strtok(l, ".");
    char *p = strtok(NULL, ".");
    int i = p[0] - '0';

    int last_digit = s[strlen(s) - 1] - '0';

    if (last_digit == 9) {
        printf("GOTO Vasilisa.\n");
    } else if (last_digit != 9 && i < 5) {
        printf("%s\n", s);
    } else {
        int incremented = atoi(s) + 1;
        printf("%d\n", incremented);
    }

    return 0;
}
// End of Code


