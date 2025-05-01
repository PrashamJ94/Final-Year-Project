#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

typedef long long ll;
typedef struct pair {
  int first;
  int second;
} pair;

const int INF = 1001001001;

int main() {
  ll H, W;
  scanf("%lld %lld", &H, &W);

  ll ans;
  if (H == 1 || W == 1) {
    ans = 1;
  } else {
    ll m = H*W;
    if (m % 2 == 0) ans = m/2;
    else ans = m/2+1;
  }
  printf("%lld\n", ans);
  return 0;
}

// 
