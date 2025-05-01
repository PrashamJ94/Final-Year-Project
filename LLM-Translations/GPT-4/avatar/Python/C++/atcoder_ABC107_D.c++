#include<bits/stdc++.h>
using namespace std;

class BIT {
    int size;
    vector<int> tree;
public:
    BIT(int N) {
        size = N;
        tree.resize(N+1);
    }
    int _bitsum(int i) {
        int ret = 0;
        while(i){
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }
    int bitsum(int l, int r = -1) {
        if (r == -1){
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }
    void bitadd(int i, int x) {
        i += 1;
        while(i <= size){
            tree[i] += x;
            i += i & -i;
        }
    }
};

int main() {
    int n, m;
    cin >> n;
    m = n * (n + 1) / 4;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    map<int, int> d;
    vector<int> _a = a;
    _a.push_back(0);
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());
    for(int i = 0; i < _a.size(); i++) {
        d[_a[i]] = i;
    }
    for(auto &x : a) x = d[x];
    auto check = [&](int X) {
        vector<int> b(n+1);
        for(int i = 0; i < n; i++) {
            b[i+1] = (a[i] >= X) * 2 - 1;
            b[i+1] += b[i];
        }
        int c = *min_element(b.begin(), b.end());
        for(auto &x : b) x -= c;
        BIT bit(*max_element(b.begin(), b.end())+2);
        int ans = 0;
        for(auto x : b) {
            ans += bit.bitsum(x+1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    };
    int l = 0, r = _a.size();
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << _a[l] << endl;
    return 0;
}
// End of Code.
