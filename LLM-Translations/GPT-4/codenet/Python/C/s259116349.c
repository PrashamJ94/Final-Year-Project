#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int divs[100][15];
    for(int i = 1; i <= 100; i++) {
        for(int j = 0; j < 15; j++) {
            int p = primes[j];
            divs[i - 1][j] = 0;
            while(i % p == 0) {
                i /= p;
                divs[i - 1][j]++;
            }
        }
    }

    int divsum[15] = {0};
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 15; j++) {
            divsum[j] += divs[i - 1][j];
        }
    }

    int num(int n) {
        int count = 0;
        for(int i = 0; i < 15; i++) {
            if(divsum[i] >= n - 1) {
                count++;
            }
        }
        return count;
    }

    int ans = 0;

    ans += num(75);
    ans += num(15) * (num(5) - 1);
    ans += num(25) * (num(3) - 1);
    ans += num(5) * (num(5) - 1) * (num(3) - 2) / 2;

    printf("%d\n", ans);
    return 0;
}

// 
