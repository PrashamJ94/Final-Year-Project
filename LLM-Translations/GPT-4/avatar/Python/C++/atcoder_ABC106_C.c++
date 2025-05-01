#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = 0;
    for (char c : s) {
        if (c != '1') {
            break;
        }
        l += 1;
    }
    if (l >= k) {
        cout << 1 << "\n";
        return 0;
    }
    cout << s[l] << "\n";
    return 0;
}

//End of Code.
