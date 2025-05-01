#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int *map = malloc(N * 2 * sizeof(int));
    for (int i = 0; i < N * 2; i++) {
        scanf("%d", &map[i]);
    }

    qsort(map, N * 2, sizeof(int), compare);

    int max = 0;
    for (int i = 0; i < N * 2; i += 2) {
        max += (map[i] < map[i + 1]) ? map[i] : map[i + 1];
    }

    printf("%d\n", max);
    free(map);

    return 0;
}
// 
