#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

long ceildiv(long x, long y) { return (x + y - 1) / y; }
int mod(long x, int m) { return (int)((x % m + m) % m); }

long gcd(long x, long y) { return y == 0 ? x : gcd(y, x % y); }
int Int(bool x) { return x ? 1 : 0; }

void put(map<pii, int, greater<pii>>& m, pii p) {
    if (m.find(p) != m.end())
        m[p]++;
    else
        m[p] = 1;
}

void rem(map<pii, int, greater<pii>>& m, pii p) {
    if (m[p] == 1)
        m.erase(p);
    else
        m[p]--;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    long ans = 0;
    if (n >= 3) {
        map<pii, int, greater<pii>> m;
        ans = arr[0] + arr[1];
        m[make_pair(arr[0], arr[1])] = 1;
        pii p1 = make_pair(arr[2], arr[1]), p2 = make_pair(arr[2], arr[0]);
        put(m, p1); put(m, p2);
        for (int i = 3; i < n; ++i) {
            pii p = m.begin()->first;
            rem(m, p);
            ans += min(p.first, p.second);
            put(m, make_pair(p.first, arr[i])); put(m, make_pair(p.second, arr[i]));
        }
    }
    else {
        ans = arr[0];
    }
    cout << ans << endl;

    return 0;
}

// 
