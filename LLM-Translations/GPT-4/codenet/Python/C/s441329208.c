#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int compare_reverse(const void *a, const void *b) {
    return -compare(a, b);
}

int main() {
    char s[1001], t[1001];
    scanf("%s", s);
    scanf("%s", t);

    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    qsort(s, len_s, sizeof(char), compare);
    qsort(t, len_t, sizeof(char), compare_reverse);

    printf("%s", strcmp(s, t) < 0 ? "Yes" : "No");
    return 0;
}
// 
