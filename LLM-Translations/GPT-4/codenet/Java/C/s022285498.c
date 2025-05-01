#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int testNumber) {
    int n;
    scanf("%d", &n);
    int countArr[n + 1];
    memset(countArr, 0, sizeof(countArr));

    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            for (int z = 1; z <= 100; z++) {
                int value = x * x + y * y + z * z + x * y + x * z + y * z;
                if (value > n) {
                    break;
                }
                countArr[value]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", countArr[i]);
    }
}

int main() {
    solve(1);
    return 0;
}

// 
