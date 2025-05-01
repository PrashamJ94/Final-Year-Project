#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, t = 0;
    cin >> k;
    for(int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if(t % k == 0) {
            cout << i << "\n";
            break;
        }
    }
    if(t % k != 0) {
        cout << -1 << "\n";
    }
    return 0;
} // End of Code
