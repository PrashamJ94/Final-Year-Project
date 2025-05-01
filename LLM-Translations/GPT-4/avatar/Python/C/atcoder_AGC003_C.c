#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        A[i] = temp * N + i;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2 != i % 2) {
            cnt += 1;
        }
    }
    printf("%d\n", cnt / 2);
    return 0;
}
// End of Code
