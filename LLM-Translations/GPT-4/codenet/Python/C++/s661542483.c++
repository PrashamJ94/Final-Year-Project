#include <iostream>

using namespace std;

int H;
int count = 0;

int dfs(int h) {
  if (h == 1) {
    return 1;
  }

  return dfs(h / 2) * 2 + 1;
}

int main() {
  cin >> H;
  cout << dfs(H) << endl;
  return 0;
}

// 
