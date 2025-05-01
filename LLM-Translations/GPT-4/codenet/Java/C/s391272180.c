#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void rotate(char* str, int len) {
    char t = str[0];
    for (int i = 0; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = t;
}

int main() {
    char s[1000], t[1000];
    scanf("%s %s", s, t);
    int s_len = strlen(s);
    int t_len = strlen(t);

    bool flag = false;
    for (int i = 0; i < s_len; i++) {
        rotate(s, s_len);
        if (strcmp(t, s) == 0) {
            flag = true;
            break;
        }
    }

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
// 
