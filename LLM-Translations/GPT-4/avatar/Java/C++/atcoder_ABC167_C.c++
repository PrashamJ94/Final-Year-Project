#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

int main() {
  int n, m, x;
  std::cin >> n >> m >> x;
  int min = INT_MAX;
  std::vector<std::vector<int>> a(n, std::vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < std::pow(2, n); i++) {
    std::vector<int> status(n, 0);
    for (int j = 0; j < n; j++) {
      if ((1 & i >> j) == 1) {
        status[j] = 1;
      }
    }
    std::vector<int> res(m + 1, 0);
    for (int j = 0; j < n; j++) {
      if (status[j] == 1) {
        for (int k = 0; k <= m; k++) {
          res[k] += a[j][k];
        }
      }
    }
    bool flag = true;
    for (int j = 1; j <= m; j++) {
      if (res[j] < x) {
        flag = false;
        break;
      }
    }
    if (flag) min = std::min(min, res[0]);
  }
  if (min == INT_MAX) std::cout << -1 << std::endl;
  else std::cout << min << std::endl;

  return 0;
}

// //End of Code.
