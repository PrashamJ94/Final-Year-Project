#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int hit = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == t[i]) hit++;
  }
  std::cout << hit << std::endl;
  return 0;
}
// 
