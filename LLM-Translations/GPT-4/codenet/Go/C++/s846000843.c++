#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Min(const vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums{0};

    for (int i = 0; i < nums.size(); i++) {
        sums.push_back(sums[i] + nums[i]);
    }
    return sums;
}

int main() {
    int n;
    cin >> n;

    vector<int> aa(n);

    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    vector<int> cumsum = CumSum(aa);

    int ans = 2020202020;
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = Min({ans, Abs(cumsum[cumsum.size() - 1] - cumsum[i] - (cumsum[i] - cumsum[0]))});
    }

    cout << ans << endl;

    return 0;
}

// 
