#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MOD 1000000007
int main( ) {
    string s;
    cin >> s;
    if(set<char>(s.begin(), s.end()).size() == 1){
        cout << 0 << endl;
        return 0;
    }
    map<char, int> a;
    for(char c : s)
        a[c]++;
    int ans = min_element(a.begin(), a.end(), [](const pair<char, int> &p1, const pair<char, int> &p2) {
        return p1.second < p2.second;
    })->second * 2;
    cout << ans << endl;
    return 0;
}
// End of Code.
