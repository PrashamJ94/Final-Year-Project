#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

long gcd(long a, long b) { 
    if (b == 0) 
        return a; 
    return a > b ? gcd(b, a % b) : gcd(a, b % a);  
} 

long fast_pow(long base, long n, long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

long modInverse(long n, long M) {
    return fast_pow(n, M - 2, M);
}

void solve(long n, long m) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    if (n == m) {
        printf("0\n");
        return;
    }
    if (n > m) {
        n = m + n % m;
        n -= m;
        printf("%ld\n", (m - n < n) ? m - n : n);
        return;
    }
    printf("%ld\n", (m - n < n) ? m - n : n);
}

int main() {
    int t = 1;
    long n, m;
    while (t-- > 0) {
        scanf("%ld %ld", &n, &m);
        solve(n, m);
    }
    return 0;
}

// 
