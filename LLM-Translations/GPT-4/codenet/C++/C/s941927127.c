#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_chars(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int main(void) {
    char W[101];
    scanf("%s", W);

    int length = strlen(W);
    qsort(W, length, sizeof(char), compare_chars);

    for (int i = 0; i < length; i += 2) {
        if (W[i] != W[i + 1]) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
// 
