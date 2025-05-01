
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

void nextInts(int n, int* slice) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]);
    }
}

int main() {
    int n, k;
    n = nextInt();
    k = nextInt();
    int a[n];
    nextInts(n, a);
    // Variable unused error avoidance
    a[0] = 0;

    int sum = k;
    int ans = 1;
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

// 
