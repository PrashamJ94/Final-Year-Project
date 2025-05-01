#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    scanf("%d", &n);
    scanf("%d", &k);

    int** map = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        map[i] = NULL;
    }

    for (int i = 0; i < k; i++) {
        int d;
        scanf("%d", &d);
        for (int j = 0; j < d; j++) {
            int person;
            scanf("%d", &person);

            int* new_entry = (int*)malloc((map[person] ? map[person][0] + 2 : 2) * sizeof(int));
            if (map[person]) {
                for (int k = 1; k <= map[person][0]; k++) {
                    new_entry[k] = map[person][k];
                }
                free(map[person]);
            }
            new_entry[0] = (map[person] ? map[person][0] + 1 : 1);
            new_entry[new_entry[0]] = d;
            map[person] = new_entry;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!map[i]) {
            count++;
        }
    }

    printf("%d\n", count);

    for (int i = 0; i <= n; i++) {
        if (map[i]) {
            free(map[i]);
        }
    }
    free(map);

    return 0;
}
// 
