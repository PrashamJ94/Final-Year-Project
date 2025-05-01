#include <stdio.h>
#include <string.h>

int main() {
    int n, cnt = 1;
    char s[1000];

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            continue;
        } else {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
// 
