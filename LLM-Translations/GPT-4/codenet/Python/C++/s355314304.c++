#include <iostream>

int main() {
  int n;
  std::cin >> n;

  if (n % 1000 == 0) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << 1000 - n % 1000 << std::endl;
  }

  return 0;
} // 
