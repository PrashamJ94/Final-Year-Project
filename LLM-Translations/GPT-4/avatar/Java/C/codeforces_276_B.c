#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[1000];
    scanf("%s", str);
    int charCount[256] = {0};
    int oddCount = 0;

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        charCount[ch]++;
    }

    for (int i = 0; i < 256; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}
// //End of Code
