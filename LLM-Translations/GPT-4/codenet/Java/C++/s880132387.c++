#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cstdint>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <functional>
#include <chrono>
#include <tuple>
#include <utility>
#include <bitset>
#include <limits>
#include <iterator>
#include <initializer_list>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <complex>
#include <cassert>

using namespace std;

class Main {
public:
    void run() {
        while (true) {
            int W, H;
            cin >> W >> H;
            if (W == 0 && H == 0) return;
            vector<string> map(H);

            for (int h = 0; h < H; h++) {
                cin >> map[h];
            }

            vector<vector<int64_t>> dp(H, vector<int64_t>(W, 0));

            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    int64_t hprev = 0;
                    if (h >= 1) {
                        hprev = dp[h - 1][w];
                    }
                    int64_t wprev = 0;
                    if (w >= 1) {
                        wprev = dp[h][w - 1];
                    }
                    if (isdigit(map[h][w])) {
                        int64_t max_val = max(hprev, wprev);
                        dp[h][w] = max_val * 10 + (map[h][w] - '0');
                    } else {
                        dp[h][w] = 0;
                    }
                }
            }

            int64_t max_val = 0;
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    max_val = max(max_val, dp[h][w]);
                }
            }
            cout << max_val << endl;
        }
    }
};

int main() {
    Main().run();
    return 0;
}

// 
