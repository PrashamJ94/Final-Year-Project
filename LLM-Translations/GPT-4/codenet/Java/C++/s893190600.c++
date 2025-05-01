
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H) {
        cin >> C[i];
    }
    if (H == 1 && W == 1) {
        cout << "No" << endl;
        return;
    }
    rep2(i, 1, H + 1) {
        rep2(j, 1, W + 1) {
            if (C[i - 1][j - 1] == '#' && C[i - 2][j - 1] != '#' && C[i][j - 1] != '#' && C[i - 1][j - 2] != '#' && C[i - 1][j] != '#') {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "
