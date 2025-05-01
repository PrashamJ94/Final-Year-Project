#include<bits/stdc++.h>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; i++)
        cin >> c[i];
    sort(c.rbegin(), c.rend());
    long long b = pow(2, 2*n-2);
    b %= mod;
    long long a = 2 * b % mod;
    long long ans = 0;
    for(int i=0; i<n; i++) {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
// End of Code


