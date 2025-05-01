#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void replaceSubstring(char *s, const char *old, const char *new) {
    char buffer[1000];
    char *p;

    if(!(p = strstr(s, old))) {
        return;
    }

    strncpy(buffer, s, p - s);
    buffer[p - s] = '\0';
    sprintf(buffer + (p - s), "%s%s", new, p + strlen(old));
    strcpy(s, buffer);
}

bool isClearedString(const char *s) {
    return !strstr(s, "D") && !strstr(s, "E");
}

int main() {
    char s[1000];
    scanf("%s", s);

    replaceSubstring(s, "dream", "D");
    replaceSubstring(s, "erase", "E");
    replaceSubstring(s, "Der", "");
    replaceSubstring(s, "Er", "");
    replaceSubstring(s, "D", "");
    replaceSubstring(s, "E", "");

    if (isClearedString(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
// 
