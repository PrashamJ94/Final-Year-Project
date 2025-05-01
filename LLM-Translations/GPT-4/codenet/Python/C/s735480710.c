#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char a[n][20];
    char b[n][20];

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    int j = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        strcpy(b[j], a[i]);
        j++;
    }
    for (int i = n % 2; i < n; i += 2) {
        strcpy(b[j], a[i]);
        j++;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            printf("%s ", b[i]);
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            printf("%s ", b[i]);
        }
    }

    return 0;
}
// 
