#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    char **lst = malloc(n * sizeof(char *));
    int pair = 0;
    for (int i = 0; i < n; i++) {
        lst[i] = malloc(21 * sizeof(char));
        scanf("%s", lst[i]);
        qsort(lst[i], strlen(lst[i]), sizeof(char), compare);
    }
    qsort(lst, n, sizeof(char *), compare);
    char *end = "end";
    lst = realloc(lst, (n + 1) * sizeof(char *));
    lst[n] = end;
    char *pre = "";
    int tmp_cnt = 0;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (strcmp(lst[i], pre) == 0) {
            tmp_cnt += 1;
        } else {
            cnt += (tmp_cnt * (tmp_cnt + 1)) / 2;
            tmp_cnt = 0;
        }
        pre = lst[i];
    }
    printf("%d", cnt);
    for (int i = 0; i < n; i++) {
        free(lst[i]);
    }
    free(lst);
    return 0;
}
// 
