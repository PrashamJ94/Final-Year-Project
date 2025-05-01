#include <iostream>
#include <cctype>

int main() {
  char x;
  std::cin >> x;
  if (islower(x)) {
    std::cout << "a" << std::endl;
  } else {
    std::cout << "A" << std::endl;
  }
  return 0;
} // 
