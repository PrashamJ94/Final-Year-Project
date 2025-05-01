#include <stdio.h>

int main() {
    int N, A, B, ans;
    scanf("%d%d%d", &N, &A, &B);
    
    ans = A * (N / (A + B)) + (A < (N % (A + B)) ? A : (N % (A + B)));
    printf("%d\n", ans);

    return 0;
}


