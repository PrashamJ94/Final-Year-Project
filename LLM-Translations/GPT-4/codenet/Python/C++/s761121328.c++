
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int s = A[0] ^ A[1];
    for (int i = 2; i < N; i++) {
        s = s ^ A[i];
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = s ^ A[i];
    }

    std::stringstream L;
    for (int i = 0; i < N; i++) {
        L << B[i] << " ";
    }

    std::cout << L.str() << std::endl;

    return 0;
}

// 
