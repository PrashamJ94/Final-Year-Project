#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  if (s == "RRR") {
    std::cout << 3;
  } else if (s == "SSS") {
    std::cout << 0;
  } else if (s == "RRS" || s == "SRR") {
    std::cout << 2;
  } else {
    std::cout << 1;
  }

  return 0;
} // 
