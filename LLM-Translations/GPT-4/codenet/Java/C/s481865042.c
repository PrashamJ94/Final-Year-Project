#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    long k;
    scanf("%s %ld", s, &k);
    char sb[strlen(s) + 1];
    strcpy(sb, s);

    for (int i = 0; i < strlen(s); i++) {
        if ((26 - (s[i] - 'a')) <= k && s[i] != 'a') {
            k -= 26 - (s[i] - 'a');
            sb[i] = 'a';
        } else {
            sb[i] = s[i];
        }
    }

    if (k > 0) {
        char t = sb[strlen(s) - 1];
        sb[strlen(s) - 1] = 'a' + (t - 'a' + k) % 26;
    }

    printf("%s\n", sb);
    return 0;
}
// 
