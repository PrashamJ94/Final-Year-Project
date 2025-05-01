#include <stdio.h>
#include <string.h>

int main() {
    int N, num_w = 0, num_r = 0, ans = 0;
    scanf("%d", &N);

    char c[N + 1];
    scanf("%s", c);

    for(int i = 0; i < N; i++) {
        if(c[i] == 'W') {
            num_w++;
        } else {
            num_r++;
        }
    }

    char comp[N + 1];
    for(int i = 0; i < num_r; i++) {
        comp[i] = 'R';
    }
    for(int i = num_r; i < N; i++) {
        comp[i] = 'W';
    }
    comp[N] = '\0';

    for(int i = 0; i < num_r; i++) {
        if(c[i] != comp[i]) {
            ans++;
        }
    }

    ans = ans < num_w ? ans : num_w;
    ans = ans < num_r ? ans : num_r;
    printf("%d\n", ans);

    return 0;
}
// 
