#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000007LL

typedef long long int lint;

void chmin(lint *a, const lint b) {
  if (*a > b) *a = b;
}

void chmax(lint *a, const lint b) {
  if (*a < b) *a = b;
}

int main() {
  int n;
  scanf("%d", &n);
  lint *a = (lint *)malloc(n * sizeof(lint));
  lint *acc = (lint *)malloc((n + 1) * sizeof(lint));
  acc[0] = 0;

  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    acc[i + 1] = acc[i] + a[i];
    acc[i + 1] %= MOD;
  }

  lint ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;
    ans %= MOD;
  }
  printf("%lld\n", ans);

  free(a);
  free(acc);

  return 0;
}

/*  */
