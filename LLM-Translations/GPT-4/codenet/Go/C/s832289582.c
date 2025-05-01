
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime

int checkSubNumbers(int N, int P, const char *S);
int checkTwoOrFive(int N, int P, const char *S);
int checkNotTwoNorFive(int N, int P, const char *S);

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    char S[N + 1];
    scanf("%s", S);
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    return 0;
}

int checkSubNumbers(int N, int P, const char *S) {
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S);
        default:
            return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, const char *S) {
    int answer = 0;
    int n;
    for (int i = N - 1; i >= 0; i--) {
        n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, const char *S) {
    int multiplier = 1; // 10^i % P
    int answer = 0;
    int remainderLookup[P];
    memset(remainderLookup, 0, sizeof(remainderLookup));
    int prevRemainder = -1;
    int digit, remainder, count;
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0';
        if (prevRemainder == -1) { // first digit
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemainder) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}



