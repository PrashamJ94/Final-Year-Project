#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    getchar(); // To consume the newline character after reading n and k

    char v[1001];
    fgets(v, sizeof(v), stdin);

    const char* d[] = {"LEFT", "RIGHT"};
    bool f = k - 1 < n - k;
    int m = f ? n - k : k - 1;

    for (int i = 0; i < m; ++i) {
        printf("%s\n", d[!f]);
    }

    for (int i = (f ? k - 1 : n - k); i < n; i++) {
        printf("PRINT %c\n", v[i]);
        if (i < n - 1) {
            printf("%s\n", d[f]);
        }
    }

    // End of Code
    return 0;
}
