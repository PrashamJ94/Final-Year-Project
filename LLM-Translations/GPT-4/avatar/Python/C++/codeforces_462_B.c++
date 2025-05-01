#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for(char c : s) {
        count[c - 'A']++;
    }
    sort(count.begin(), count.end(), greater<int>());
    long long res = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] >= k) {
            res += (long long)k * k;
            cout << res << endl;
            return 0;
        }
        k -= count[i];
        res += (long long)count[i] * count[i];
    }
    cout << res << endl;
    return 0;
} // End of Code.
