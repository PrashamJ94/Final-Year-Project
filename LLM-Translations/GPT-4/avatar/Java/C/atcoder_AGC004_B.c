#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x;
    scanf("%d %ld", &N, &x);
    long srimeList[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    long costList[N][N];
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N]) ? costList[i][castNum - 1] : srimeList[(i - castNum + N) % N];
        }
    }
    long result[N];
    for (int i = 0; i < N; i++) {
        long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += costList[j][i];
        }
        result[i] = i * x + sum;
    }
    long min = LONG_MAX;
    for (int i = 0; i < N; i++) {
        if (result[i] < min) {
            min = result[i];
        }
    }
    printf("%ld\n", min);
    return 0;
} // //End of Code
