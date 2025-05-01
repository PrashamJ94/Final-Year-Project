
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX 100000

int64_t cum_remainders[MAX];
int64_t remainder_counts[MAX];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
  
    cum_remainders[0] = 0;
    memset(remainder_counts, 0, sizeof(remainder_counts));
    for(int i = 1; i <= N; i++) {
        int64_t a;
        scanf("%lld", &a);
        cum_remainders[i] = (cum_remainders[i-1] + a) % M;
        remainder_counts[cum_remainders[i]]++;
    }
  
    int64_t combinations = 0;
    for(int i = 0; i < M; i++) {
        combinations += remainder_counts[i] * (remainder_counts[i] - 1) / 2;
    }
    printf("%lld\n", combinations);
    return 0;
}

// End of Code
