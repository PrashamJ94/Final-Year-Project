#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find(char *s, char ch, int *count) {
    int *indices = (int *)malloc(strlen(s) * sizeof(int));
    int index = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            indices[index++] = i;
        }
    }
    *count = index;
    return indices;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    if (!strchr(s, '0')) {
        printf("%d\n", n - 1);
    } else {
        int count;
        int *indices = find(s, '0', &count);
        if (count == 1) {
            printf("%d\n", n);
        } else {
            int maximum = 0;
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    int diff = abs(indices[i] - indices[j]) - 1;
                    maximum = max(maximum, 2 + 2 * diff - diff);
                }
            }
            int ones = 0;
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '1') {
                    ones++;
                }
            }
            printf("%d\n", ones + maximum);
        }
        free(indices);
    }
    return 0;
}
// End of Code
