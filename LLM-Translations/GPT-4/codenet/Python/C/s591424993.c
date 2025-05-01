
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int d, g;
    scanf("%d %d", &d, &g);

    int pc[d][2];
    for (int i = 0; i < d; i++) {
        scanf("%d %d", &pc[i][0], &pc[i][1]);
    }

    int ans = INT_MAX;

    for (int bit = 0; bit < (1 << d); bit++) {
        int count = 0;
        int sum = 0;
        bool nokori[d];
        for (int i = 0; i < d; i++) {
            nokori[i] = true;
        }

        for (int i = 0; i < d; i++) {
            if (bit & (1 << i)) {
                sum += pc[i][0] * (i + 1) * 100 + pc[i][1];
                count += pc[i][0];
                nokori[i] = false;
            }
        }

        if (sum < g) {
            int use = -1;
            for (int i = d - 1; i >= 0; i--) {
                if (nokori[i]) {
                    use = i;
                    break;
                }
            }

            int n = (g - sum + (use + 1) * 100 - 1) / ((use + 1) * 100);
            if (n > pc[use][0]) {
                n = pc[use][0];
            }
            count += n;
            sum += n * (use + 1) * 100;
        }

        if (sum >= g) {
            if (ans > count) {
                ans = count;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
