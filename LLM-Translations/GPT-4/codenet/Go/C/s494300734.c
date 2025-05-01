
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    char *c_position = strchr(s, 'C');
    char *f_position = strrchr(s, 'F');

    const char *ans = "No";
    if (c_position != NULL && f_position != NULL && c_position < f_position) {
        ans = "Yes";
    }

    printf("%s\n", ans);

    return 0;
}
// 


