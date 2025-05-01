
#include <stdio.h>

int main() {
    int N, x, i;
    scanf("%d %d", &N, &x);
    
    int a[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    long long cnt = 0;
    for(i = 1; i < N; i++) {
        int tmp = a[i - 1] + a[i];
        if(tmp > x) {
            if(tmp - x > a[i]) {
                a[i - 1] = tmp - a[i] - x;
                a[i] = 0;
            } else {
                a[i] = a[i] - (tmp - x);
            }
            cnt += tmp - x;
        }
    }

    printf("%lld\n", cnt);
    return 0;
}
