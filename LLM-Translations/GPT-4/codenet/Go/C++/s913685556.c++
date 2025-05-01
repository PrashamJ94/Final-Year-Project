#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int max(int a, int b) {
    return (a < b) ? b : a;
}

class Scanner {
public:
    Scanner() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    int NextInt() {
        int v;
        std::cin >> v;
        return v;
    }

    std::vector<int> NextIntArray() {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<int> result;
        int v;
        while (iss >> v) {
            result.push_back(v);
        }
        return result;
    }
};

int main() {
    Scanner sc;
    int A = sc.NextInt();
    int B = sc.NextInt();

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    std::cout << mx << std::endl;

    return 0;
}

// 
