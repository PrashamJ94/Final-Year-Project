#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s;
  std::cin >> t;

  if (t.substr(0, t.length() - 1) == s) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
} // 
