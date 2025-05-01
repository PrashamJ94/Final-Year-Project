
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

class Solver {
public:
    Solver(int n, int m, int q, std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, std::vector<int>& d)
        : n(n), m(m), q(q), a(a), b(b), c(c), d(d), max(0) {}

    int solve() {
        dfs(std::vector<int>{1});
        return max;
    }

private:
    int n, m, q;
    std::vector<int> a, b, c, d;
    int max;

    void dfs(std::vector<int> array) {
        if (array.size() > static_cast<size_t>(n)) {
            int score = 0;
            for (int i = 0; i < q; i++) {
                if (array[b[i]] - array[a[i]] == c[i]) {
                    score += d[i];
                }
            }
            max = std::max(max, score);
            return;
        }

        std::vector<int> newArray(array);
        newArray.push_back(array.back());
        while (newArray.back() <= m) {
            dfs(newArray);
            newArray.back() += 1;
        }
    }
};

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    Solver solver(n, m, q, a, b, c, d);
    std::cout << solver.solve() << std::endl;

    return 0;
}


