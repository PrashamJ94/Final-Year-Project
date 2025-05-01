#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

class TaskB {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            in >> a[i];
        }

        long long P = 37, Q = 47;
        vector<long long> powP(n + 1), powQ(n + 1);
        powP[0] = powQ[0] = 1;
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n));
        vector<vector<long long>> hashCol(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                    hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; A++) {
            for (int B = 0; B < n; B++) {
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
                }
                ans += ok ? 1 : 0;
            }
        }
        out << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    TaskB solver;
    istream& in(cin);
    ostream& out(cout);
    solver.solve(1, in, out);
    return 0;
}

// 
