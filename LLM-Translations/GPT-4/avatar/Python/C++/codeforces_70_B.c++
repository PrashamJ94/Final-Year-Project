#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 1, sumL = 0;
    cin >> n;
    string str;
    cin.ignore();
    getline(cin, str);
    stringstream ss(str);
    vector<string> result;
    while(getline(ss, str, '.'))
        result.push_back(str);
    for(int i=0; i<result.size(); i++) {
        result[i] += '.';
        int L = result[i].size();
        if(L > 1) {
            if(L > n) {
                cout << "Impossible" << endl;
                return 0;
            }
            if(sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    cout << ans << endl;
    return 0;
} 
// End of Code.
