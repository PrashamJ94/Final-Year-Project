#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

class Solution {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }
        out << ans << endl;
    }
};

int main() {
    istringstream input("5 3\n50 100 80 120 80\n");
    ostringstream output;
    Solution().solve(input, output);
    cout << output.str();
}

// //End of Code.
