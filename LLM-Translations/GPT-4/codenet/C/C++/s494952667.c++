#include <iostream>
#include <string>

int main()
{
  std::string str;
  int len;
  
  std::cin >> str;
  
  len = str.length();

  for(int i = len-1; i >= 0; i--){
    std::cout << str[i];
  }
  std::cout << std::endl;
  
  return 0;
}

// 
