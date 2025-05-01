#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int i;
    if (scanf("%d", &i) != 1) {
        perror("Error reading integer");
        exit(EXIT_FAILURE);
    }
    return i;
}

int main() {
    int n, m;
    n = readInt();
    m = readInt();
    int a[m];
    int sum = 0;
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
        sum += a[i];
    }
    if (sum > n) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", n - sum);
    return 0;
}

// 
