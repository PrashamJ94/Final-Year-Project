#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, int **ans, int len) {
    int bad = -1, good = len;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][0] < key)
            good = mid;
        else
            bad = mid;
    }
    return good;
}

int main() {
    int N;
    scanf("%d", &N);
    int **ans = malloc(sizeof(int*));
    int len = 0;
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, len);
        if (idx == len) {
            ans = realloc(ans, (len+1) * sizeof(int*));
            ans[len] = malloc(sizeof(int));
            ans[len][0] = A;
            len++;
        } else {
            ans[idx] = realloc(ans[idx], (idx+2) * sizeof(int));
            ans[idx][idx+1] = A;
        }
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        free(ans[i]);
    free(ans);
    return 0;
}
// End of Code
