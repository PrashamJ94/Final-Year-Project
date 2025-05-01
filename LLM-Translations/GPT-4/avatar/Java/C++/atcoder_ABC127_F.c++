
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    string s;
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    ll sumMin = 0 , sumMax = 0 , sumb = 0;
    int min = 0, x, y;
    while(t--) {
        cin >> x;
        if(x == 2) {
            ll ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            ll ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            cout << min << " " << ans + ans1 + sumb << "\n";
        } else {
            cin >> y >> sumb;
            if(y > min) {
                pqmax.push(y);
                sumMax += y;
            } else {
                pqmin.push(y);
                sumMin += y;
            }
            if(pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
            if(pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }
            min = pqmin.top();
        }
    }
    return 0;
} ////End of Code


