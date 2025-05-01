#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char c[100];
    scanf("%s", c);

    for (int i = 0; i < strlen(c); i++) {
        c[i] = (char)((c[i] - 'A' + N) % 26 + 'A');
    }

    printf("%s\n", c);
    return 0;
}
// 
