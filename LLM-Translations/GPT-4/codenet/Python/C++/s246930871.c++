
#include <iostream>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;
    int ans = A * (N / (A + B)) + std::min(A, N % (A + B));
    std::cout << ans << std::endl;
    return 0;
}
// 


