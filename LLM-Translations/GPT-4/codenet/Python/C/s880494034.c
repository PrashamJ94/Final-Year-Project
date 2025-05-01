
#include <stdio.h>
#include <math.h>

int main() {
    int N, i, j;
    scanf("%d", &N);
    
    int XS[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &XS[i]);
    }

    int m = 999999999;
    for (i = 1; i <= 100; i++) {
        int c = 0;
        for (j = 0; j < N; j++) {
            c += pow(XS[j] - i, 2);
        }
        if (m > c) {
            m = c;
        }
    }

    printf("%d\n", m);

    return 0;
}
