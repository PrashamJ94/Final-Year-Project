#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <list>
#include <complex>
#include <chrono>
#include <functional>
#include <initializer_list>
#include <tuple>
#include <numeric>
#include <fstream>
#include <sstream>
#include <ctime>
#include <ratio>
#include <cstdint>
#include <cassert>

using namespace std;

const int INF = 1e9;

vector<vector<vector<int>>> memo;
vector<vector<int>> a;
int n;

int dp(int flipped, int idx, int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (memo[flipped][idx][mask] != -1) return memo[flipped][idx][mask];
    int x = __builtin_popcount(mask);
    int ff = 0;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, mask | 1 << i));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[flipped][idx][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(2, vector<int>(n));
    for (int i = 0; i < n; ++i) cin >> a[0][i];
    for (int i = 0; i < n; ++i) cin >> a[1][i];
    memo.resize(2, vector<vector<int>>(n + 1, vector<int>(1 << n, -1)));
    int ans = dp(0, n, 0);
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}

// 
