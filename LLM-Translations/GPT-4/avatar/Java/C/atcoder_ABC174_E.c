
#include <stdio.h>
#include <stdbool.h>

bool nei(int mid, int logsLength[], int n, int k) {
    for (int i = 0; i < n; i++) {
        k -= (logsLength[i] + mid - 1) / mid - 1;
    }
    return k >= 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int logsLength[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]);
    }

    int min = 1, max = 1000001000;
    while (min < max) {
        int mid = (min + max) / 2;
        if (nei(mid, logsLength, n, k)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    printf("%d\n", min);
    return 0;
}

// //End of Code
