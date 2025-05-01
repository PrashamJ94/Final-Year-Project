#include <stdio.h>
#include <string.h>

int main() {
    int n;
    long cnt[5] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        char str[20];
        scanf("%s", str);

        if (str[0] == 'M') {
            cnt[0]++;
        } else if (str[0] == 'A') {
            cnt[1]++;
        } else if (str[0] == 'R') {
            cnt[2]++;
        } else if (str[0] == 'C') {
            cnt[3]++;
        } else if (str[0] == 'H') {
            cnt[4]++;
        }
    }

    long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4];

    printf("%ld\n", res);

    return 0;
}

// //End of Code
