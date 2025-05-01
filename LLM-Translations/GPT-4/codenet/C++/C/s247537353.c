#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef long long ll;

bool chmin(ll *a, ll b) {
  if (*a > b) {
    *a = b;
    return true;
  }
  return false;
}

bool chmax(ll *a, ll b) {
  if (*a < b) {
    *a = b;
    return true;
  }
  return false;
}

int main() {
  ll A, B, C, K;
  scanf("%lld %lld %lld %lld", &A, &B, &C, &K);
  if (A + B >= K) {
    printf("%lld\n", fminl(A, K));
  } else {
    printf("%lld\n", A - (K - (A + B)));
  }
  return 0;
}

// 
