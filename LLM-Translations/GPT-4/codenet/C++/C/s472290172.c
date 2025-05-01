#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int max = 0, cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        char sc = str[i];
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
            cnt++;
        } else {
            cnt = 0;
        }
        max = max < cnt ? cnt : max;
    }

    printf("%d\n", max);
    return 0;
}
// 
