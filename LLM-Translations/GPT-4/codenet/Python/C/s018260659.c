#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 1;
    while (cnt <= 9) {
        if (N % cnt == 0 && 1 <= N / cnt && N / cnt <= 9) {
            printf("Yes\n");
            break;
        } else {
            cnt += 1;
        }
    }
    if (cnt > 9) {
        printf("No\n");
    }
    return 0;
}
// 
