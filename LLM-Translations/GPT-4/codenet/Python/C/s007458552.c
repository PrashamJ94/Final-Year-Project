#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    char S[n + 1];
    scanf("%s", S);

    int count_R = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == 'R') {
            count_R++;
        }
    }

    if (count_R > n - count_R) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// 
