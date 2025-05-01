#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M, i, B, C, rest, sum;
    scanf("%d%d", &N, &M);
    
    int m[100001] = {0};
    for (i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        m[temp]++;
    }
    
    for (i = 0; i < M; i++) {
        scanf("%d%d", &B, &C);
        m[C] += B;
    }
    
    int ints[100001] = {0};
    int index = 0;
    for (i = 0; i <= 100000; i++) {
        if (m[i] > 0) {
            ints[index++] = i;
        }
    }
    
    qsort(ints, index, sizeof(int), compare);
    
    rest = N;
    sum = 0;
    for (i = 0; i < index; i++) {
        int num = m[ints[i]];
        if (num >= rest) {
            sum += rest * ints[i];
            break;
        }
        sum += num * ints[i];
        rest -= num;
    }
    
    printf("%d\n", sum);
    
    return 0;
}

// 
