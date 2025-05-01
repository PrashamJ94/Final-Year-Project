#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char s[5];
    scanf("%s", s);
    qsort(s, 4, sizeof(char), compare);
    if (s[0] == s[1] && s[0] != s[2] && s[2] == s[3]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// 
