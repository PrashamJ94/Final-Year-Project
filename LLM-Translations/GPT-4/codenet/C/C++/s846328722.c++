#include<iostream>
using namespace std;

int linearSearch(int [], int, int);

int main(){
  int i, n, s[100000], q, t, count = 0;

  cin >> n;

  for(i = 0; i < n; i++){
    cin >> s[i];
  }

  cin >> q;

  for(i = 0; i < q; i++){
    cin >> t;
    if( linearSearch(s, n, t) ) count++;
  }
  cout << count << endl;

  return 0;
}

int linearSearch(int a[], int n, int key){
  int i = 0;

  a[n] = key;

  while(a[i] != key){
    i++;
  }
    return i != n;
}

// 
