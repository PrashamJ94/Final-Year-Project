#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = true;
    for(int i=1; i<n; i++) {
        if(a[i] % a[0] != 0) {
            flag = false;
            break;
        }
    }
    if(flag) cout << a[0] << endl;
    else cout << -1 << endl;
    return 0;
} // End of Code
