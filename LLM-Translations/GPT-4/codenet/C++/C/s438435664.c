#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef long long ll;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

ll lmax(ll s,ll t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

ll lmin(ll s,ll t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}
// ここから開始

int main(){
  int n,k;
  scanf("%d%d", &n, &k);
  ll sum = 0;
  for(int b = 1; b <= n; b++){
    int cnt = (n+1)/b;
    int md = (n+1)%b;
    sum+=cnt*lmax((b-k),0)+lmax((md-k),0);
    if(k==0) sum--;
  }
  printf("%lld\n", sum);
  return 0;
}

// 
