#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class FastScanner {
public:
    FastScanner() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    bool hasNext() {
        return std::cin.peek() != EOF;
    }

    std::string next() {
        std::string s;
        std::cin >> s;
        return s;
    }

    long long nextLong() {
        long long n;
        std::cin >> n;
        return n;
    }

    int nextInt() {
        int n;
        std::cin >> n;
        return n;
    }

    double nextDouble() {
        double d;
        std::cin >> d;
        return d;
    }
};

int main() {
    FastScanner fs;
    int n = fs.nextInt();
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = fs.nextInt();
    }
    std::sort(a.begin(), a.end());
    long long sum = 0;
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += a[i];
        if(a[i + 1] <= 2 * sum) {
            count++;
        } else {
            count = 0;
        }
    }
    std::cout << count + 1 << std::endl;
    return 0;
}
// 
