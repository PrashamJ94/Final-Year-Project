#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sol(char *s, int q, int *queries) {
    int cum[strlen(s) + 1];
    cum[0] = cum[strlen(s)] = 0;
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) cum[i] = cum[i - 1] + 1;
        else cum[i] = cum[i - 1];
    }
    for (int i = 0; i < q * 2; i += 2) {
        int l = queries[i], r = queries[i + 1] - 1;
        printf("%d\n", cum[r] - cum[l - 1]);
    }
}

int main() {
    char s[100001];
    int q;
    scanf("%s", s);
    scanf("%d", &q);
    int queries[q * 2];
    for (int i = 0; i < q * 2; i++) {
        scanf("%d", &queries[i]);
    }
    sol(s, q, queries);
    return 0;
}

// //End of Code
