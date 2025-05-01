#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    char s[n + 1];
    scanf("%s", s);
    int count[26] = {0};
    for(i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }
    int tmp;
    for(i = 0; i < 26; i++) {
        for(int j = i + 1; j < 26; j++) {
            if(count[j] > count[i]) {
                tmp = count[i];
                count[i] = count[j];
                count[j] = tmp;
            }
        }
    }
    long long res = 0;
    for(i = 0; i < 26; i++) {
        if(count[i] >= k) {
            res += k * k;
            printf("%lld\n", res);
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }
    printf("%lld\n", res);
    return 0;
} /* End of Code */
