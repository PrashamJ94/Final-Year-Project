#include <stdio.h>
#include <limits.h>

void solve() {
    int N, max, min, in;

    scanf("%d", &N);
    scanf("%d", &in);
    max = min = in;

    for (int i = 1; i < N; i++) {
        scanf("%d", &in);
        max = (max > in) ? max : in;
        min = (min < in) ? min : in;
    }

    printf("%d\n", max - min);
}

int main() {
    solve();
    return 0;
}
// 
