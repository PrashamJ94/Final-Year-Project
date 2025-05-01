#include <iostream>
#include <vector>

int main(){
  int key, len;
  std::cin >> len;
  std::vector<int> a(len);
  for(int i = 0; i < len; i++) std::cin >> a[i];

  for(int j = 1; j < len; j++){
    for(int i = 0; i < len; i++) std::cout << (i != 0 ? " " : "") << a[i];
    std::cout << std::endl;
    key = a[j];
    int i;
    for(i = j - 1; i >= 0 && a[i] > key; i--) a[i + 1] = a[i];
    a[i + 1] = key;
  }

  for(int i = 0; i < len; i++) std::cout << (i != 0 ? " " : "") << a[i];
  std::cout << std::endl;
  return 0;
}
// 
