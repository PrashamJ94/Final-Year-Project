
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **li = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        li[i] = (int *) malloc((k + 1) * sizeof(int));
        li[i][0] = k;
        for (int j = 1; j <= k; j++) {
            scanf("%d", &li[i][j]);
        }
    }

    int *p = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int q[100], q_size = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= li[i][0]; j++) {
            bool found = false;
            for (int k = 0; k < q_size; k++) {
                if (q[k] == li[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                q[q_size++] = li[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= q_size; i++) {
        int comb[100];
        for (int j = 0; j < i; j++) {
            comb[j] = q[j];
        }

        while (1) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int k = 1; k <= li[j][0]; k++) {
                    for (int l = 0; l < i; l++) {
                        if (comb[l] == li[j][k]) {
                            cnt++;
                            break;
                        }
                    }
                }
                if (cnt % 2 != p[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans += 1 << (n - q_size);
            }

            int idx = i - 1;
            while (idx >= 0 && comb[idx] == q[q_size - i + idx]) {
                idx--;
            }

            if (idx < 0) {
                break;
            }

            int pos = 0;
            for (int j = 0; j < q_size; j++) {
                if (q[j] == comb[idx]) {
                    pos = j;
                    break;
                }
            }

            comb[idx] = q[pos + 1];

            for (int j = idx + 1; j < i; j++) {
                for (int k = 0; k < q_size; k++) {
                    if (q[k] == comb[j - 1]) {
                        comb[j] = q[k + 1];
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);
    free(p);

    return 0;
}

//End of Code
