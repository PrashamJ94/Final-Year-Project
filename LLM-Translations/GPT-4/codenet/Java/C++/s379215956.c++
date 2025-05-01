#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  std::string s1 = s.substr(0, 1);
  std::string s2 = s.substr(1, 1);
  std::string s3 = s.substr(2, 1);
  std::string s4 = s.substr(3, 1);
  int a = 0;
  
  if (s1 == s2) a = 1;
  if (s2 == s3) a = 1;
  if (s3 == s4) a = 1;
  
  if (a == 1) {
    std::cout << "Bad" << std::endl;
  } else {
    std::cout << "Good" << std::endl;
  }
  
  return 0;
}

// 
