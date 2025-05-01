#include <stdio.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    int alocuente[m];
    for (int i = 0; i < m; i++) alocuente[i] = 0;
    int ind = 1;
    for (int i = 0; i < t; i++) {
        char op[10];
        int val;
        scanf("%s", op);
        if (strcmp(op, "alloc") == 0) {
            scanf("%d", &val);
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == val) {
                        for (int k = j - val + 1; k <= j; k++)
                            alocuente[k] = ind;
                        printf("%d\n", ind++);
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (pos != val) printf("NULL\n");
        } else if (strcmp(op, "erase") == 0) {
            scanf("%d", &val);
            int flag = 0;
            if (val == 0) flag = 1;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == val) {
                    alocuente[j] = 0;
                    flag = 1;
                }
            }
            if (flag == 0) printf("ILLEGAL_ERASE_ARGUMENT\n");
        } else if (strcmp(op, "defragment") == 0) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) cnt++;
                else if (cnt > 0) {
                    alocuente[j - cnt] = alocuente[j];
                    alocuente[j] = 0;
                }
            }
        }
    }
    return 0;
}

// End of Code
