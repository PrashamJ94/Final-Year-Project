#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int min(const std::vector<int>& n) {
  if (n.empty()) {
    throw std::runtime_error("len == 0");
  }
  int r = n[0];
  for (size_t i = 1; i < n.size(); i++) {
    if (n[i] <= r) {
      r = n[i];
    }
  }
  return r;
}

int main() {
  int H, N, A, B;
  std::cin >> H >> N;
  std::vector<int> dp(H + 10001, std::numeric_limits<int>::max());
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000;
  }
  int amax = 0;
  for (int i = 0; i < N; i++) {
    std::cin >> A >> B;
    if (A >= amax) {
      amax = A;
    }
    dp[A] = std::min(dp[A], B);
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = std::min(dp[j], dp[j - A] + B);
    }
  }
  std::cout << min(std::vector<int>(dp.begin() + H, dp.begin() + H + amax + 1)) << std::endl;
  return 0;
}

// 
