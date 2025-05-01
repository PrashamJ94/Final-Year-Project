#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

int lcm_list(int numbers[], int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result = lcm(result, numbers[i]);
    }
    return result;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] /= 2;
    }

    int count_div_2 = -1;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            cnt++;
        }
        if (count_div_2 == -1) {
            count_div_2 = cnt;
        } else if (cnt != count_div_2) {
            printf("0\n");
            exit(0);
        }
    }

    int my_lcm = lcm_list(A, N);
    if (my_lcm > M) {
        printf("0\n");
        exit(0);
    }

    int tmp = M / my_lcm;
    int ans = (tmp + 1) / 2;
    printf("%d\n", ans);

    return 0;
}

// 
