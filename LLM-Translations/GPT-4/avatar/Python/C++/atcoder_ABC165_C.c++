#include<bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<int> a, b, c, d;
int res = 0;

void rec(vector<int> A) {
    if (A.size() == N) {
        int ans = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                ans += d[i];
            }
        }
        res = max(res, ans);
        return;
    }
    int last_max = (A.empty()) ? 1 : A.back();
    for (int i = last_max; i <= M; i++) {
        A.push_back(i);
        rec(A);
        A.pop_back();
    }
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    rec(vector<int>());
    cout << res << endl;
    return 0;
}
// End of Code.
