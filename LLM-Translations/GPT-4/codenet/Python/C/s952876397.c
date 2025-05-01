#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char s[n+1];
    fgets(s, n+1, stdin);

    int left = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            left++;
        } else {
            break;
        }
    }

    int left1 = 0;
    int right1 = 0;

    for (int i = left; i < n; i++) {
        if (s[i] == '(') {
            right1++;
        } else if (right1 > 0) {
            right1--;
        } else {
            left1++;
        }
    }

    left1 += left;
    for (int i = 0; i < right1; i++) {
        strncat(s, ")", 1);
    }

    for (int i = 0; i < left1; i++) {
        memmove(&s[1], &s[0], strlen(s) + 1);
        s[0] = '(';
    }

    printf("%s\n", s);

    return 0;
}
// 
