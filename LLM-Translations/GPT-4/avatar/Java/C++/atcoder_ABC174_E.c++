#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stdexcept>

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n, k;
        in >> n >> k;
        std::vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            in >> logsLength[i];
        }
        int min = 1, max = static_cast<int>(1e9) + 1000;
        while (min < max) {
            int mid = (min + max) / 2;
            if (nei(mid, logsLength, k)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        out << min << std::endl;
    }

private:
    bool nei(int mid, const std::vector<int>& logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1;
        }
        return k >= 0;
    }
};

int main() {
    std::istream& inputStream = std::cin;
    std::ostream& outputStream = std::cout;
    Solution sol;
    sol.solve(inputStream, outputStream);
    return 0;
}
// //End of Code
