#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> cut(vector<pair<int, int>>& array, int index) {
    if (index < 1) {
        return {};
    }
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    for (int i = array.size() - 1; i > 0; --i) {
        if (array[i - 1].first < index) {
            vector<pair<int, int>> res(array.begin(), array.begin() + i);
            res.push_back({index, array[i].second});
            return res;
        }
    }
    return array;
}

bool is_possible(int K, vector<int>& A) {
    vector<pair<int, int>> dp = {{A[0], 0}};
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] <= dp.back().first) {
            dp = cut(dp, A[i]);
        } else {
            dp.push_back({A[i], 0});
        }
        bool is_added = false;
        for (int j = dp.size() - 1; j >= 0; --j) {
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1);
                dp.push_back({dp[j].first, dp[j].second + 1});
                if (dp.back().first < A[i]) {
                    dp.push_back({A[i], 0});
                }
                is_added = true;
                break;
            }
        }
        if (!is_added) {
            return false;
        }
    }
    return true;
}

int bis(int x, int y, vector<int>& A) {
    if (y == x + 1) {
        return y;
    } else if (is_possible((x + y) / 2, A)) {
        return bis(x, (x + y) / 2, A);
    } else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    A.insert(A.begin(), *A.begin());
    A.erase(unique(A.begin(), A.end(), greater<int>()), A.end());
    n = A.size();
    cout << bis(0, n, A) << endl;
    return 0;
}

// End of Code

