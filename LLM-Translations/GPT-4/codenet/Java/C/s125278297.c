#include <stdio.h>
#include <string.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    char ans[h][w + 3];
    for (int i = 0; i < h; i++) {
        char input[w + 1];
        scanf("%s", input);
        sprintf(ans[i], "#%s#", input);
    }
    char border[w + 3];
    memset(border, '#', w + 2);
    border[w + 2] = '\0';

    printf("%s\n", border);
    for (int i = 0; i < h; i++) {
        printf("%s\n", ans[i]);
    }
    printf("%s\n", border);

    return 0;
}
// 
