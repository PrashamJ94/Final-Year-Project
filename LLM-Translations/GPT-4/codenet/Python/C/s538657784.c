
#include <stdio.h>
#include <math.h>

int main() {
    int N, sqN;
    scanf("%d", &N);
    sqN = (int)sqrt(N);
    for (int i = 0; i < sqN; i++) {
        if (N % (sqN - i) == 0) {
            printf("%d\n", (int)(N / (sqN - i) + sqN - i) - 2);
            break;
        }
    }
    return 0;
}


