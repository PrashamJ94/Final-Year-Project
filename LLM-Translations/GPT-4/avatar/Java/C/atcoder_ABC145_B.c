#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cout(char *str) {
    printf("%s\n", str);
}

int main() {
    char a[1000] = "", b[1000] = "", str[1000];
    int n, i;

    scanf("%d", &n);
    getchar();

    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = 0;

    for (i = 0; i < n / 2; i++) {
        a[i] = str[i];
    }

    strncpy(b, str + (n / 2), n / 2);
    a[n / 2] = '\0';
    b[n / 2] = '\0';

    if (strcmp(a, b) == 0)
        cout("Yes");
    else
        cout("No");

    return 0;
} // //End of Code
