#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    int min = INT_MAX;
    int count = 0;
    long sum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if(A[i] < 0)
            count++;
        min = (abs(A[i]) < min) ? abs(A[i]) : min;
        sum += abs(A[i]);
    }

    if(count % 2 == 0)
        printf("%ld\n", sum);
    else {
        printf("%ld\n", sum - min * 2);
    }

    return 0;
}
