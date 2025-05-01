
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

long int gcd(long int a, long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

long int lcm(long int a, long int b){
  return a * b / gcd(a, b);
}

int main(){
  long int n;
  long long int k;
  long int q;
  vector<long int> a(100001);
  vector<long long int> point(100001, 0);

  cin >> n >> k >> q;

  for(long int i = 0; i < q; i++){
    cin >> a[i];
    point[a[i] - 1]++;
  }

  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
}

// 
