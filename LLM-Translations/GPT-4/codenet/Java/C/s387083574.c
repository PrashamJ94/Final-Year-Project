#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int *)a)[1] - ((int *)b)[1];
}

int main() {
    int N;
    scanf("%d", &N);
    int map[N][2];
    for (int i = 0; i < N; i++) {
        map[i][0] = i + 1;
        scanf("%d", &map[i][1]);
    }
    qsort(map, N, sizeof(map[0]), compare);
    for (int i = 0; i < N; i++) {
        printf("%d ", map[i][0]);
    }
    printf("\n");
    return 0;
}
// 
