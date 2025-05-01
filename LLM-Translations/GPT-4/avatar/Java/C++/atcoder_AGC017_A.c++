#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <ctime>
#include <cassert>
#include <bitset>
#include <list>
#include <tuple>
#include <string>
#include <cstring>
#include <array>
#include <functional>
#include <memory>
#include <climits>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <complex>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define _GLIBCXX_DEBUG

ll C(int n, int m) {
    ll res = 1;
    for (int i = m - n + 1; i <= m; i++)
        res = res * i;
    for (int i = 1; i <= n; i++)
        res = res / i;
    return res;
}

int main() {
    int n, p;
    int k0 = 0;
    int k1 = 0;
    cin >> n >> p;
    rep(i, n) {
        int x;
        cin >> x;
        if (x % 2 == 1)
            k1++;
        else
            k0++;
    }
    ll ans = 1;
    rep(i, k0) ans = ans * 2;
    if (p == 0) {
        ll add = 0;
        for (int i = 0; i <= k1; i += 2) add = add + C(i, k1);
        ans = ans * add;
        cout << ans << endl;
    }
    else {
        ll add = 0;
        for (int i = 1; i <= k1; i += 2) add = add + C(i, k1);
        ans = ans * add;
        cout << ans << endl;
    }
}
// //End of Code
