#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    scanf("%s", s);
    bool x = true;
    int dt[128] = {0};
    for (int i = 0; i < strlen(s); i++) {
        dt[s[i]]++;
    }
    int cnt = 0;
    x = true;
    for (int i = 0; i < 128; i++) {
        if (dt[i] % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (dt[i] % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }
    if (x) {
        printf("First\n");
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");
    } else if (!x && strlen(s) % 2 != 0) {
        printf("First\n");
    }
    return 0;
}
// End of Code
