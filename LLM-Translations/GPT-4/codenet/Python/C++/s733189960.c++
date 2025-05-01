#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int n;
  std::cin >> n;
  std::map<std::string, int> sdic;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    if (sdic.find(s) != sdic.end()) {
      sdic[s]++;
    } else {
      sdic[s] = 1;
    }
  }
  long long ans = 0;
  for (const auto &kv : sdic) {
    ans += (long long)kv.second * (kv.second - 1) / 2;
  }
  std::cout << ans << std::endl;
  return 0;
}

// 
