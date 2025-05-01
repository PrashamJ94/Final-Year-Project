#include <stdio.h>

int main() {
    int n, happiness = 0, chocCount = 0, nfat = 1;
    scanf("%d", &n);
    char cake[n][n];
    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    printf("%d\n", happiness);
    return 0;
}

// End of Code
