#include <stdio.h>
#include <stdbool.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    int memory[m];
    int allocIdx = 0;

    for (int j = 0; j < t; j++) {
        char cmd[15];
        scanf("%s", cmd);

        if (strcmp(cmd, "alloc") == 0) {
            int n;
            scanf("%d", &n);
            int len = 0;
            bool canAlloc = false;

            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    len++;
                } else {
                    len = 0;
                }

                if (len == n) {
                    canAlloc = true;
                    len = i - n + 1;
                    break;
                }
            }

            if (canAlloc) {
                allocIdx++;
                for (int i = len; i < len + n; i++) {
                    memory[i] = allocIdx;
                }
                printf("%d\n", allocIdx);
            } else {
                printf("NULL\n");
            }
        } else if (strcmp(cmd, "erase") == 0) {
            int x;
            scanf("%d", &x);

            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                bool hasErased = false;
                for (int i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0;
                        hasErased = true;
                    }
                }

                if (!hasErased) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        } else if (strcmp(cmd, "defragment") == 0) {
            int d = 0;
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    d++;
                } else {
                    memory[i - d] = memory[i];
                }
            }

            for (int i = m - d; i < m; i++) {
                memory[i] = 0;
            }
        } else {
            printf("h\n");
        }
    }

    return 0;
}
// //End of Code.
