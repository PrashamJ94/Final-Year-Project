
#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    char s[n];
    scanf("%s", s);
    int problems[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }
    int cumsum[n];
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1] + (s[i - 1] == 'A' && s[i] == 'C');
    }
    for (int i = 0; i < q; i++) {
        int l = problems[i][0];
        int r = problems[i][1];
        printf("%d\n", cumsum[r - 1] - (l > 1 ? cumsum[l - 2] : 0));
    }
    return 0;
}
/* End of Code */


