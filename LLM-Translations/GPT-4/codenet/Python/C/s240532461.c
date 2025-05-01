#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    int aji[N];
    for (int i = 1; i <= N; i++) {
        aji[i - 1] = L + i - 1;
    }
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (aji[i] < aji[minIndex]) {
            minIndex = i;
        }
        if (aji[i] > aji[maxIndex]) {
            maxIndex = i;
        }
    }
    if (aji[minIndex] >= 0) {
        aji[minIndex] = 0;
    } else if (aji[maxIndex] <= 0) {
        aji[maxIndex] = 0;
    } else {
        int minAbsIndex = 0;
        for (int i = 1; i < N; i++) {
            if (abs(aji[i]) < abs(aji[minAbsIndex])) {
                minAbsIndex = i;
            }
        }
        aji[minAbsIndex] = 0;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += aji[i];
    }
    printf("%d\n", sum);
    return 0;
}
// 
