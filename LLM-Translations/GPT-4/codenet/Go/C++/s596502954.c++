#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string next() {
    std::string s;
    std::cin >> s;
    return s;
}

int nextInt() {
    int i;
    std::cin >> i;
    return i;
}

double nextFloat64() {
    double f;
    std::cin >> f;
    return f;
}

std::vector<int> nextInts(int n) {
    std::vector<int> slice(n);
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

int main() {
    if (nextInt() + nextInt() >= nextInt()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// 
