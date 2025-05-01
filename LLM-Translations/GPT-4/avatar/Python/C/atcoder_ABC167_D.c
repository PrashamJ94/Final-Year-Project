
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int *L = (int *)malloc((N + 2) * sizeof(int));
    L[0] = -1;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }

    int *path = (int *)malloc((N + 1) * sizeof(int));
    path[0] = 1;

    int ind = 0, x = 1, t = -1;
    bool flag = false;
    int *Hash = (int *)calloc(N + 1, sizeof(int));

    for (int i = 0; i <= N; i++) {
        int ne = L[x];
        if (Hash[ne]) {
            flag = true;
            t = Hash[ne];
            break;
        }
        path[ind + 1] = ne;
        ind++;
        Hash[ne] = ind;
        x = ne;
    }

    if (flag == true) {
        int loop_length = ind - t + 1;
        int *loop = (int *)malloc(loop_length * sizeof(int));
        for (int i = 0; i < loop_length; i++) {
            loop[i] = path[t + i];
        }

        if (K < (ind + 1)) {
            printf("%d\n", path[K]);
        } else {
            K = K - (ind + 1);
            K = K % loop_length;
            printf("%d\n", loop[K]);
        }
        free(loop);
    } else {
        printf("%d\n", path[K - 1]);
    }

    free(L);
    free(path);
    free(Hash);

    return 0;
}
// End of Code


