
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> a_li(N);
    for (int i = 0; i < N; ++i) {
        cin >> a_li[i];
    }

    sort(a_li.begin(), a_li.end());

    int n = a_li.back();

    int dif = INF;
    int prev_dif = dif;
    int r;
    for (int a : a_li) {
        if (a == n) continue;
        dif = min(abs(n / 2 - a), dif);
        if (dif != prev_dif) {
            r = a;
            prev_dif = dif;
        }
    }

    cout << n << " " << r << endl;

    return 0;
}

// 
