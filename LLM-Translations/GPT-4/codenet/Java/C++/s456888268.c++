
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits>
#include <ctime>
#include <cassert>

using namespace std;

const long long mod = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int inf = numeric_limits<int>::max() / 2;
const long long linf = numeric_limits<long long>::max() / 3;
const double dinf = numeric_limits<double>::max() / 3;
const double eps = 1e-10;
const double pi = acos(-1);
const int maxn = 1e5 + 5;

void solve() {
    string tmp;
    cin >> tmp;
    vector<char> s(tmp.begin(), tmp.end());
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'S') {
            cnt++;
        }
        else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2 * ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


