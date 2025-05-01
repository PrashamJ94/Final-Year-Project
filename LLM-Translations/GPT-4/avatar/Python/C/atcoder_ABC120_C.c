#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define INF INT_MAX

int main() {
    char s[1000];
    scanf("%s", s);

    if (strlen(s) == 1) {
        printf("0\n");
        return 0;
    }

    int a[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        a[s[i] - 'a']++;
    }

    int ans = INF;
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0 && a[i] < ans) {
            ans = a[i];
        }
    }

    printf("%d\n", ans * 2);

    return 0;
}
/* End of Code */
