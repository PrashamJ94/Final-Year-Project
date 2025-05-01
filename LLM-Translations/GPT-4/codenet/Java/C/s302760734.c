#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char s[51], t[51];
    scanf("%s %s", s, t);

    int s_length = strlen(s);
    int t_length = strlen(t);
    bool check = false;

    for (int i = s_length - t_length; i >= 0; i--) {
        bool check2 = true;
        for (int j = 0; j < t_length; j++) {
            if (s[i + j] != '?' && s[i + j] != t[j]) {
                check2 = false;
            }
        }
        if (check2) {
            check = true;
            for (int j = 0; j < t_length; j++) {
                s[i + j] = t[j];
            }
        }
        if (check) {
            break;
        }
    }

    if (check) {
        for (int i = 0; i < s_length; i++) {
            if (s[i] == '?') {
                printf("a");
            } else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    } else {
        printf("UNRESTORABLE\n");
    }

    return 0;
}

// 
