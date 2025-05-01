#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  int n;
  std::vector<int> h;
  int max = -1;
  bool flag = false;

  std::cin >> n;
  h.resize(n);

  for(int i = 0; i < n; i++){
    std::cin >> h[i];
    if(max < h[i]) max = h[i];

    if(max - h[i] >= 2) flag = true;
  }

  if(flag) std::cout << "No" << std::endl;

  else std::cout << "Yes" << std::endl;

  return 0;
}

// 
