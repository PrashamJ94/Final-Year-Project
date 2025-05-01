#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    long A[N];
    for(int i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    qsort(A, N, sizeof(long), compare);
    for(int j = 1; j < N; j++) {
        if(A[j] == A[j - 1]) {
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");
    return 0;
}
// 
