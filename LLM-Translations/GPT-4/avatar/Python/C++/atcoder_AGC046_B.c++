#include<bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    long m = 998244353;
    vector<vector<long>> d(C + 1, vector<long>(D + 1, 0));
    d[A][B] = 1;
    for(int i = A; i <= C; i++) {
        for(int j = B; j <= D; j++) {
            d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
        }
    }
    cout << d[C][D];
    return 0;
} // End of Code
