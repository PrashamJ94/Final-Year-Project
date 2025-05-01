#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int n, int arr[]) {
  int r = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] <= r) {
      r = arr[i];
    }
  }
  return r;
}

int main() {
  int H, N, A, B;
  scanf("%d %d", &H, &N);
  int dp[H + 10001];
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000;
  }
  int amax = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B);
    if (A >= amax) {
      amax = A;
    }
    dp[A] = min(dp[A], B);
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = min(dp[j], dp[j - A] + B);
    }
  }
  printf("%d\n", min(H + amax + 1, &dp[H]));

  return 0;
}

// 
