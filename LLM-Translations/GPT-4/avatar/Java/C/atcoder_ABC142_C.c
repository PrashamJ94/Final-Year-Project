
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, A, i;
    scanf("%d", &N);
    int idorder[N + 1];

    for (i = 1; i <= N; i++) {
        scanf("%d", &A);
        idorder[A] = i;
    }

    for (i = 1; i <= N; i++) {
        printf("%d ", idorder[i]);
    }

    return 0;
}

// //End of Code
