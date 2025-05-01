#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *generateString() {
    char *str = (char *)malloc(5000);
    str[0] = '\0';
    for (int i = 1; i <= 1000; i++) {
        char temp[5];
        sprintf(temp, "%d", i);
        strcat(str, temp);
    }
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    char *str = generateString();
    printf("%c\n", str[n - 1]);
    free(str);
    return 0;
}

// //End of Code
