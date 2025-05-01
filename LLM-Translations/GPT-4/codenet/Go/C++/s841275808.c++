#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
        Y[i] = X[i];
    }

    std::sort(Y.begin(), Y.end());
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            std::cout << m2 << std::endl;
        } else {
            std::cout << m1 << std::endl;
        }
    }

    return 0;
}

// Utility functions

int Max(int a, int b) {
    return a < b ? b : a;
}

int Min(int a, int b) {
    return a > b ? b : a;
}

int Abs(int a) {
    return a < 0 ? -a : a;
}

// 
