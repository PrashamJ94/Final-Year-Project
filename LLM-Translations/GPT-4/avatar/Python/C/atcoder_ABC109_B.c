#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[51];
    int value;
} hashMap;

int main() {
    int n, i, j;
    scanf("%d", &n);

    char words[n][51];
    for (i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    hashMap map[n];
    int mapSize = 0;
    char flag[] = "Yes";

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < mapSize; j++) {
            if (strcmp(map[j].key, words[i]) == 0) {
                map[j].value++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(map[mapSize].key, words[i]);
            map[mapSize].value = 1;
            mapSize++;
        }

        if (map[j].value >= 2) {
            strcpy(flag, "No");
        }

        if (i > 0 && words[i - 1][strlen(words[i - 1]) - 1] != words[i][0]) {
            strcpy(flag, "No");
        }
    }

    printf("%s\n", flag);
    return 0;
}
// End of Code
