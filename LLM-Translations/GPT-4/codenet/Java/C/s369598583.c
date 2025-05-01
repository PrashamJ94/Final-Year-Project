#include <stdio.h>

int main() {
    int N, count = 0, next = 10;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        count++;
        if(i == next - 1) {
            i = next * 10 - 1;
            next *= 100;
        }
    }

    printf("%d\n", count);
    return 0;
}

// 
