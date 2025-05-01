#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, size;
    scanf("%d", &N);
    size = (1 << N);
    int S[size];
    bool spawned[size];
    spawned[size - 1] = true;

    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, size, sizeof(int), compare);

    int active[size], activeSize = 0;
    active[activeSize++] = S[size - 1];
    spawned[size - 1] = true;

    for (int i = 0; i < N; i++) {
        qsort(active, activeSize, sizeof(int), compare);
        int activated[size], activatedSize = 0;
        int next = size - 1;

        for (int j = 0; j < activeSize; j++) {
            int slime = active[j];
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }

            if (next < 0) {
                printf("No\n");
                return 0;
            }

            spawned[next] = true;
            activated[activatedSize++] = S[next];
        }

        for (int j = 0; j < activatedSize; j++) {
            active[activeSize++] = activated[j];
        }
    }

    printf("Yes\n");
    return 0;
}

// //End of Code
