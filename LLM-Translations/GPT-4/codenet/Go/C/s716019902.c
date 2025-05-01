#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const int mod = 998244353;

int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n = n >> 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    if (a < b) {
        return Gcd(b, a);
    }
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int N;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

// 
