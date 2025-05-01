#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int *m = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (m[i] == m[j]) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = false;
            break;
        }
    }

    printf("%s\n", possible ? "YES" : "NO");
    free(m);

    return 0;
}
// End of Code
