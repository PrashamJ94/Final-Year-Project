#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<int> lst_p, lst_m;
int p, m, x, y, lastx, lasty;

int check(int k) {
    int ans = INT_MAX;
    for (int j = 0; j <= k; j++) {
        if (j > lastx || k - j > lasty)
            continue;
        if (j == 0)
            p = 0;
        else
            p = lst_p[j - 1];
        if (k - j == 0)
            m = 0;
        else
            m = lst_m[lasty - (k - j)];
        ans = min(ans, min(2 * p + abs(m), p + 2 * abs(m)));
    }
    return ans;
}

int main() {
    cin >> N >> K;
    vector<int> lst(N);
    for (int i = 0; i < N; i++) {
        cin >> lst[i];
        if (lst[i] == 0)
            K--;
        else if (lst[i] > 0)
            lst_p.push_back(lst[i]);
        else if (lst[i] < 0)
            lst_m.push_back(lst[i]);
    }
    lastx = lst_p.size();
    lasty = lst_m.size();
    x = 0, y = lasty - 1;
    cout << check(K);
    return 0;
} // End of Code
