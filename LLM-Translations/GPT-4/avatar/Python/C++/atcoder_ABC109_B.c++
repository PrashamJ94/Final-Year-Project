#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> s;
    vector<string> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        s[l[i]]++;
    }
    string f = "Yes";
    for(int i = 1; i < n; i++) {
        if(s[l[i]] >= 2 || l[i - 1].back() != l[i][0]) {
            f = "No";
            break;
        }
    }
    cout << f << endl;
    return 0;
} // End of Code
