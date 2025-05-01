#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int pre = INT_MAX;
    long long ans = 0;
    sort(a.rbegin(), a.rend());
    for(int j = 0; j < n; j++){
        ans += max(0, min(pre - 1, a[j]));
        pre = max(0, min(pre - 1, a[j]));
    }
    cout << ans << endl;
    return 0;
}

// End of Code.
