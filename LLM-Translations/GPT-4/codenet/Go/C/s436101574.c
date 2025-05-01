
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void replace_question_marks(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '?') {
            str[i] = 'a';
        }
    }
}

int main() {
    char s[51], t[51];
    scanf("%s%s", s, t);

    int s_len = strlen(s);
    int t_len = strlen(t);
    char ans[51][51] = {0};
    int ans_count = 0;

    for (int i = 0; i < s_len - t_len + 1; i++) {
        bool f = true;
        char ss[51];
        strcpy(ss, s);

        for (int j = 0; j < t_len; j++) {
            if (s[i+j] != t[j] && s[i+j] != '?') {
                f = false;
                break;
            } else {
                ss[i+j] = t[j];
            }
        }
        if (f) {
            replace_question_marks(ss);
            strcpy(ans[ans_count], ss);
            ans_count++;
        }
    }

    if (ans_count == 0) {
        printf("UNRESTORABLE\n");
    } else {
        qsort(ans, ans_count, sizeof(ans[0]), strcmp);
        printf("%s\n", ans[0]);
    }

    return 0;
}

// 
