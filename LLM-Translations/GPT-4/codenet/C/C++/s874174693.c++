#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

void swap (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;

  return;
}

long int gcd(long int a, long int b){
  long int c;

  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

bool upll(const ll &a, const ll &b){
  return a < b;
}

bool downll(const ll &a, const ll &b){
  return a > b;
}

void sortup(vector<ll> &a){
  sort(a.begin(), a.end(), upll);
}

void sortdown(vector<ll> &a){
  sort(a.begin(), a.end(), downll);
}

long int modpow(long int a,long int n,long int mod){
  long int ans=1;
  while(n>0){
    if(n & 1){
      ans=ans*a%mod;
    }
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

long int modinv(long int a,long int mod){
  return modpow(a,mod-2,mod);
}

int max(int a,int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}

int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

void chmax(int *a,int b){
  if(*a < b){
    *a = b;
  }

  return;
}

void chmin(int *a,int b){
  if(*a > b){
    *a =b;
  }

  return;
}

int main(){
  int n;
  cin >> n;
  int sum=0;
  int m=n;
  for(int i=0;i<9;i++){
    sum+=n%10;
    n/=10;
  }
  if(m%sum==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
// 
