#include <stdio.h>

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int round_complexity[n], george_complexity[m];
    for (i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    for (j = 0; j < m; j++) {
        scanf("%d", &george_complexity[j]);
    }
    i = j = 0;
    while (i < n && j < m) {
        if (round_complexity[i] <= george_complexity[j]) {
            i += 1;
        }
        j += 1;
    }
    printf("%d\n", n - i);
    return 0;
}
// End of Code
