#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char array[n][101];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", array[i]);
    }

    qsort(array, n, sizeof(array[0]), cmp);

    char a[101];
    strcpy(a, array[0]);
    cnt++;

    for (int i = 0; i < n; i++) {
        if (strcmp(a, array[i]) == 0) {
            // Do nothing
        } else {
            cnt++;
        }
        strcpy(a, array[i]);
    }
    
    printf("%d\n", cnt);
    return 0;
}
// 
