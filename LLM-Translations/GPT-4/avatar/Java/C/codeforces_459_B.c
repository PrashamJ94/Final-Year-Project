#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int N, i;
    long mins = 0, maxs = 0;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmpfunc);
    int min = A[0];
    int max = A[N - 1];
    
    for (i = 0; i < N; i++) {
        if (A[i] == min) mins++;
        if (A[i] == max) maxs++;
    }
    
    if (min == max) {
        printf("%d %ld\n", (max - min), mins * (mins - 1) / 2);
    } else {
        printf("%d %ld\n", (max - min), mins * maxs);
    }
    
    return 0;
}

// //End of Code.
