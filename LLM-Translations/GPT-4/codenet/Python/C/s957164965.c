
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int X, N;
    scanf("%d %d", &X, &N);
    
    int p[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }
    
    qsort(p, N, sizeof(int), compare);
    
    int candidates[104][2];
    for (int i = 0; i < 104; i++) {
        candidates[i][0] = 1000;
        candidates[i][1] = 0;
    }
    
    for (int i = -1; i < 102; i++) {
        int j;
        for (j = 0; j < N; j++) {
            if (p[j] == i) {
                break;
            }
        }
        
        if (j == N) {
            int diff = abs(X - i);
            if (candidates[diff][1] == 0) {
                candidates[diff][0] = i;
                candidates[diff][1] = 1;
            } else {
                candidates[diff][1]++;
            }
        }
    }
    
    int smallest = 1000;
    for (int i = 0; i < 104; i++) {
        if (candidates[i][1] != 0 && i < smallest) {
            smallest = i;
        }
    }
    
    int minNum = candidates[smallest][0];
    printf("%d\n", minNum);
    
    return 0;
}
