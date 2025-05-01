
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000_006;
const ll MOD = (ll)1e9 + 7;

ll pow(ll base, ll exp, ll MOD) {
    base %= MOD;
    ll ret = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) ret = ret * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

void solve() {
    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> straight, cycle;
    vector<bool> vis(N);
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = true;
        curr = A[curr] - 1;
    }

    int st = 0;
    while (st != curr) {
        straight.push_back(st);
        st = A[st] - 1;
    }

    cycle.push_back(curr);
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle.push_back(curr);
        curr = A[curr] - 1;
    }

    if (K < straight.size()) {
        cout << straight[(int)K] + 1 << endl;
    } else {
        K -= straight.size();
        cout << cycle[(int)(K % cycle.size())] + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) solve();

    return 0;
}

// 
