#include <stdio.h>

int main() {
    int N, ans = 0, maxH = 0, H;
    scanf("%d", &N);
    int Hs[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &Hs[i]);
    }

    for (int i = 0; i < N; i++) {
        H = Hs[i];
        if (maxH <= H) {
            ans++;
            maxH = H;
        }
    }

    printf("%d\n", ans);
    return 0;
}
// 


