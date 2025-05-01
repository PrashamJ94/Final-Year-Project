#include <stdio.h>
#include <string.h>

int main() {
    char s[200005];
    scanf("%s", s);
    int mods[200005] = {0};
    int countRemainder[2019] = {0};
    int cnt = 0;

    int m = 1;
    int mod = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        mod += (s[len - i - 1] - '0') * m;

        mod %= 2019;
        m *= 10;
        m %= 2019;

        countRemainder[mod]++;
    }

    countRemainder[0]++;

    for (int i = 0; i < 2019; i++) {
        cnt += countRemainder[i] * (countRemainder[i] - 1) / 2;
    }

    printf("%d\n", cnt);

    return 0;
}
// 
