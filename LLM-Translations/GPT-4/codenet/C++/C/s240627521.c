#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int compare(const void* a, const void* b) {
    return (*(ll*)b - *(ll*)a);
}

int main() {
  int N;
  scanf("%d", &N);
  ll A[N];
  for(int i=0;i<N;++i) scanf("%lld", &A[i]);
  qsort(A, N, sizeof(ll), compare);
  int index;
  ll max = inf;
  for(int i=1;i<N;++i) {
    if(max>abs(A[0]-2*A[i])) {
      max = abs(A[0]-2*A[i]);
      index = i;
    }
  }
  printf("%lld %lld\n", A[0], A[index]);
  return 0;
}

// 
