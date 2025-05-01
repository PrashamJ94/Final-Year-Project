
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    scanf("%d", &N);
    int P[N];
    for (i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        P[i] -= 1;
    }
    int map[N];
    for (i = 0; i < N; ++i) {
        map[P[i]] = i;
    }
    int nglist[N], nglist_size = 0;
    for (i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i;
        }
    }
    if (nglist_size == 0) {
        printf("%d\n", 0);
        return 0;
    }
    int ans = (N - nglist[0] - 1 < nglist[nglist_size - 1] + 1) ? N - nglist[0] - 1 : nglist[nglist_size - 1] + 1;
    for (i = 0; i < nglist_size - 1; ++i) {
        int temp = nglist[i] + 1 + N - nglist[i + 1] - 1;
        ans = (temp < ans) ? temp : ans;
    }
    printf("%d\n", ans);
    return 0;
}
// //End of Code


