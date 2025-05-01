#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    scanf("%s", str);
    int dotIndex = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    if (str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    } else if (str[dotIndex + 1] - '0' > 4) {
        char _str[100] = "";
        for (int i = 0; i < dotIndex; i++) {
            _str[i] = str[i];
        }
        _str[dotIndex] = '\0'; // Null-terminate the string
        long long num = atoll(_str) + 1;
        printf("%lld\n", num);
    } else {
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    return 0;
}

// //End of Code.
