
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string str;
  std::getline(std::cin, str);
  std::istringstream ss(str);
  std::vector<int> abc(3);
  for (int i = 0; i < 3; ++i) {
    ss >> abc[i];
  }
  if (abc[0] < abc[1] && abc[1] < abc[2]) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
// 


