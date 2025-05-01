#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[5];
    scanf("%s", s);

    int map[128] = {0};
    for (int i = 0; i < strlen(s); i++) {
        map[(int)s[i]]++;
    }

    bool ok = true;
    int count = 0;
    for (int i = 0; i < 128; i++) {
        if (map[i] > 0) {
            if (map[i] != 2) {
                ok = false;
                break;
            }
            count++;
        }
    }

    if (ok && count == 2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// //End of Code
