#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int ans[2];

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
        if (sum < N) {
            continue;
        } else {
            ans[0] = i - 1;
            ans[1] = sum - N;
            break;
        }
    }

    for (int i = 0; i <= ans[0]; i++) {
        if (i + 1 != ans[1]) {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}
// 
