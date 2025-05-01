#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1000;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (n < a) {
            cout << "No" << endl;
            continue;
        }
        if (a == b) {
            if (n % a == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }
        ll x = b / (b - a);
        if (n > x * a) {
            cout << "Yes" << endl;
            continue;
        }
        ll low = 1;
        ll high = x + 1;
        ll ans = 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        if (n > (ans - 1) * b && n < ans * a) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}

// //End of Code
