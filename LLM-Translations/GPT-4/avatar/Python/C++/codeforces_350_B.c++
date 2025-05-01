
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n+1, 0), a(n+1, 0), cnt(n+1, 0), ans;
    for(int i=1; i<=n; ++i)
        cin >> t[i];
    for(int i=1; i<=n; ++i)
    {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for(int i=1; i<=n; ++i)
    {
        if(t[i] == 1)
        {
            vector<int> crt = {i};
            int x = a[i];
            while(cnt[x] == 1)
            {
                crt.push_back(x);
                x = a[x];
            }
            if(crt.size() > ans.size())
                ans = crt;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
// End of Code


