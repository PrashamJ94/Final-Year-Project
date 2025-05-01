#include <stdio.h>
#include <string.h>

static long count_AD(const char *s) {
    long cnt = 0;
    long tmp = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            tmp++;
        } else if (s[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }

    return cnt;
}

int main() {
    char s[100001];
    scanf("%s", s);

    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            s[i] = '-';
            s[i + 1] = 'D';
        }
    }

    printf("%ld\n", count_AD(s));

    return 0;
}

// //End of Code.
