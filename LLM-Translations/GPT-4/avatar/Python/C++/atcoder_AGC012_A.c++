#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
    cin >> A[i];
    sort(A.begin(), A.end());
    long long ans = 0;
    for(int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2)
    ans += A[i];
    cout << ans << "\n";
    return 0;
}
// End of Code.
