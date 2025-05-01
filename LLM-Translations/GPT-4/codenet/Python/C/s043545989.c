#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int N, i;
    scanf("%d", &N);
    int *a = (int*) malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int B[100000] = {0};
    for (i = 0; i < N; i++) {
        B[a[i]]++;
    }
    
    int k[100000], v[100000], lenB = 0;
    for (i = 0; i < 100000; i++) {
        if (B[i] != 0) {
            k[lenB] = i;
            v[lenB] = B[i];
            lenB++;
        }
    }

    if (lenB == 3 && (k[0] ^ k[1] ^ k[2]) == 0 && v[0] == v[1] && v[1] == v[2]) {
        printf("Yes\n");
    } else if (lenB == 2 && (k[0] == 0 || k[1] == 0) && (v[0] == 2 * v[1] || v[1] == 2 * v[0])) {
        printf("Yes\n");
    } else if (lenB == 1 && k[0] == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    free(a);
    return 0;
}
// 
