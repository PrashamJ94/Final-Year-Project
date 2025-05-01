#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& A, int key) {
  int left = 0;
  int right = A.size();
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == A[mid]) return 1; /* keyを発見 */
    if(key > A[mid]) left = mid + 1; /* 後半を探索 */
    else if(key < A[mid]) right = mid; /* 前半を探索 */
  }
  return 0;
}

int main() {
  int n, q, k, sum = 0;
  std::cin >> n;
  std::vector<int> A(n);
  for(int i=0; i<n; i++) {
    std::cin >> A[i];
  }
  std::cin >> q;
  for(int i=0; i<q; i++) {
    std::cin >> k;
    if(binarySearch(A, k))
      sum++;
  }
  std::cout << sum << std::endl;
  return 0;
}

// 
