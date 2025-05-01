#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <iterator>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, S;
    cin >> K >> S;

    int ans = 0;
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
// 
