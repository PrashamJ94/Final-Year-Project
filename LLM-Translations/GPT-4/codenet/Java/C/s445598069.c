#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int s[100010] = {0};

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        s[num]++;
    }

    int dec = 0;

    for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
        if (s[i] != 0) {
            if (s[i] % 2 == 0) {
                s[i] = 2;
            } else {
                s[i] = 1;
            }
        }
    }

    int one = 0;
    int two = 0;

    for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
        if (s[i] == 2) {
            two++;
        } else if (s[i] == 1) {
            one++;
        }
    }

    if (two % 2 != 0) {
        one--;
    }

    printf("%d\n", two + one);

    return 0;
}
// 
