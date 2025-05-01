#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int h[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    int a, b;
    int *counter = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (h[a-1] < h[b-1]) {
            counter[a-1] = 1;
        } else if (h[a-1] > h[b-1]) {
            counter[b-1] = 1;
        } else if (h[a-1] == h[b-1]) {
            counter[a-1] = 1;
            counter[b-1] = 1;
        }
    }
    int num_good_points = 0;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            num_good_points++;
        }
    }
    printf("%d\n", num_good_points);

    free(counter);
    return 0;
}
// 
