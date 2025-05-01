#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int part(vector<int> &a, vector<int> &b, int l, int r){
  int i, j, x, t;

  i = l - 1;
  j = r;

  x = b[r];

  while(1){
    while(b[++i] < x);
    while(i < --j && x < b[j]);

    if(i >= j) break;

    swap(a[i], a[j]);
    swap(b[i], b[j]);
  }

  swap(a[i], a[r]);
  swap(b[i], b[r]);
  return i;
}

void quicksort(vector<int> &a, vector<int> &b, int n){
  vector<int> low(200000), high(200000);
  int l, r, v, sp;

  low[0] = 0;
  high[0] = n - 1;
  sp = 1;

  while(sp > 0){
    sp--;
    l = low[sp];
    r = high[sp];

    if(l >= r);

    else {
      v = part(a, b, l, r);

      if(v - l < r - v){
        low[sp] = v + 1;
        high[sp++] = r;
        low[sp] = l;
        high[sp++] = v - 1;
      }

      else{
        low[sp] = l;
        high[sp++] = v - 1;
        low[sp] = v + 1;
        high[sp++] = r;
      }
    }
  }
}

int main(){
  int n, m;
  int i;
  vector<int> a(100006), b(100006);
  int cnt = 0;
  int t;

  cin >> n >> m;

  for(i = 0; i < m; i++) cin >> a[i] >> b[i];

  quicksort(a, b, m);

  t = 0;
  for(i = 0; i < m; i++){
    if(t <= a[i]){
      t = b[i];
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}

// 
