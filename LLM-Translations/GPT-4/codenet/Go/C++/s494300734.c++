#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s;
  std::cin >> s;
  
  std::string ans = "No";
  if (s.find("C") < s.rfind("F")) {
    ans = "Yes";
  }
  if (s.find("C") == std::string::npos) {
    ans = "No";
  }
  
  std::cout << ans << std::endl;

  return 0;
}
// 
