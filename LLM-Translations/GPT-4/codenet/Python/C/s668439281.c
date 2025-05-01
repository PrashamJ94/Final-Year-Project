#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n, i, j, count = 0;
    scanf("%d", &n);
    
    char **ls = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        ls[i] = (char *)malloc(15 * sizeof(char));
        scanf("%s", ls[i]);
    }
    
    qsort(ls, n, sizeof(char *), compare);
    
    char **ans = (char **)malloc(n * sizeof(char *));
    int ans_size = 0;
    
    for (i = 0; i < n;) {
        int temp_count = 0;
        for (j = i + 1; j < n && strcmp(ls[i], ls[j]) == 0; j++) {
            temp_count++;
        }
        if (temp_count > count) {
            count = temp_count;
            ans_size = 0;
            ans[ans_size++] = ls[i];
        } else if (temp_count == count) {
            ans[ans_size++] = ls[i];
        }
        i = j;
    }
    
    for (i = 0; i < ans_size; i++) {
        printf("%s\n", ans[i]);
    }
    
    for (i = 0; i < n; i++) {
        free(ls[i]);
    }
    free(ls);
    free(ans);
    
    return 0;
}


