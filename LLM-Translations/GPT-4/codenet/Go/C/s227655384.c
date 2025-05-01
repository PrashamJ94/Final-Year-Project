#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void print_list(int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int m[A + B];
    bool exists[A + B];
    memset(exists, false, sizeof(exists));

    for (int i = 0; i < A; i++) {
        scanf("%d", &m[i]);
        exists[m[i]] = true;
    }

    int result[A + B];
    int result_size = 0;

    for (int i = 0; i < B; i++) {
        int n;
        scanf("%d", &n);
        if (exists[n]) {
            exists[n] = false;
        } else {
            exists[n] = true;
        }
    }

    for (int i = 0; i < A + B; i++) {
        if (exists[i]) {
            result[result_size++] = i;
        }
    }

    qsort(result, result_size, sizeof(int), compare);
    print_list(result, result_size);

    return 0;
}

// 
