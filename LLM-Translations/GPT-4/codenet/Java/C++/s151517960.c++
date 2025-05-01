#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
  int n, a;
  cin >> n;
  unordered_map<int, int> map;
  for(int i = 0; i < n; i++) {
    cin >> a;
    if(map.find(a) != map.end()) {
      map[a]++;
    } else {
      map[a] = 1;
    }
  }
  int ans = 0;
  for(auto &key : map) {
    if((key.second % 2) == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
// 
