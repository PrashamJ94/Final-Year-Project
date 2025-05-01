#include<stdio.h>

#define N 368

int main() {
    int m[N] = {0};
    int f[N] = {0};
    int n, a, b, i, c = 0;
    char x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf(" %c %d %d", &x, &a, &b);
        b++;

        if(x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    int a_total = 0, b_total = 0;

    for(i = 0; i < N; i++) {
        a_total += m[i];
        b_total += f[i];

        if((a_total < b_total ? a_total : b_total) > c) {
            c = (a_total < b_total ? a_total : b_total);
        }
    }

    printf("%d\n", c);

    return 0;
}
