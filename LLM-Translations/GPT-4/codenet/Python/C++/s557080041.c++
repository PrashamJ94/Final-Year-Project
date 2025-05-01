#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  if (N == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::string str_N = std::to_string(N);
    std::vector<int> L;

    for (char s : str_N) {
      L.push_back(s - '0');
    }

    int X = 0;
    for (int num : L) {
      X += num;
    }

    if (X % 9 == 0) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
// 
