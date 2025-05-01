#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> left;
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        left.insert(i);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, win;
        cin >> l >> r >> win;
        l--;
        r--;
        win--;

        for(auto it = left.lower_bound(l); it != left.end() && *it <= r; ) {
            answer[*it] = win + 1;
            it = left.erase(it);
        }

        answer[win] = 0;
        left.insert(win);
    }
  
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
} // //End of Code

