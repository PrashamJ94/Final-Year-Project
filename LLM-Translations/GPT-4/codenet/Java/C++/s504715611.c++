#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>
#include <cstring>
#include <sstream>

class UnionFind {
public:
    UnionFind(int n) {
        Parent.resize(n, -1);
    }

    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }

    int size(int A) {
        return -Parent[root(A)];
    }

    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) std::swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }

private:
    std::vector<int> Parent;
};

int main() {
    std::string str;
    std::cin >> str;
    std::cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << std::endl;
    return 0;
}

// 
