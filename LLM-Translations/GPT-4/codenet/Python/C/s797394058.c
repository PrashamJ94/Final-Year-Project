
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, x = 1;
    scanf("%d", &N);

    int N_list[N];
    for (int i = 0; i < N; i++) {
        N_list[i] = x + 1;
        x++;
    }

    int n = 1;
    for (int i = 0; i < 3; i++) {
        n *= N;
    }

    printf("%d\n", n);

    return 0;
}


