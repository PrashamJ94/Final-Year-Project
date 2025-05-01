#include <stdio.h>
#include <string.h>

int check(char a[], char b[]) {
    int s = 0;
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        s += a[i] != b[i];
    }
    return s;
}

int main() {
    char s[1000], t[1000];
    scanf("%s", s);
    scanf("%s", t);

    int ans = 1000000;
    for (int i = 0; s[i] != '\0'; i++) {
        char a[1000];
        strncpy(a, &s[i], sizeof(a) - 1);
        a[sizeof(a) - 1] = '\0';

        if (strlen(a) >= strlen(t)) {
            char a_sub[1000];
            strncpy(a_sub, a, strlen(t));
            a_sub[strlen(t)] = '\0';
            ans = (ans < check(t, a_sub)) ? ans : check(t, a_sub);
        }
    }
    printf("%d\n", ans);

    return 0;
}
// 
