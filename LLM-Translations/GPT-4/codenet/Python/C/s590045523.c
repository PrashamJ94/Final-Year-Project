#include <stdio.h>

int main() {
    int N, ans = 0;
    scanf("%d", &N);
    int L[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            for(int k = j + 1; k < N; k++) {
                int a = L[i];
                int b = L[j];
                int c = L[k];

                if(a == b || b == c || c == a) {
                    continue;
                }

                if(a + b > c && b + c > a && c + a > b) {
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

// 
