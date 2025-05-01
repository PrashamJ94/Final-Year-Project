#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char **res = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        res[i] = (char *) malloc(100 * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", res[i]);
    }

    int unique_count = 0;
    for (int i = 0; i < n; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(res[i], res[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_count++;
        }
    }

    printf("%d\n", unique_count);

    for (int i = 0; i < n; i++) {
        free(res[i]);
    }
    free(res);

    return 0;
}
// 
