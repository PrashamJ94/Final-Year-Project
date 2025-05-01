
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> info(n);
    for (int i = 0; i < n; i++) {
        cin >> info[i].first >> info[i].second;
    }

    sort(info.begin(), info.end(), compare);

    vector<int> selected_only, selected_chohuku, unselected_only;
    map<int, int> memo;
    for (int i = 0; i < k; i++) {
        int t = info[i].first, d = info[i].second;
        if (memo.find(t) == memo.end()) {
            memo[t] = 1;
            selected_only.push_back(d);
        } else {
            selected_chohuku.push_back(d);
        }
    }

    int cnt_type = memo.size();
    for (int i = k; i < n; i++) {
        int t = info[i].first, d = info[i].second;
        if (memo.find(t) == memo.end()) {
            memo[t] = 1;
            unselected_only.push_back(d);
        }
    }

    long long sum_select = 0;
    for (int d : selected_chohuku) sum_select += d;
    for (int d : selected_only) sum_select += d;
    
    long long ans = cnt_type * cnt_type + sum_select;

    reverse(unselected_only.begin(), unselected_only.end());
    int len_selected_chohuku = selected_chohuku.size();
    int len_unselected_only = unselected_only.size();
    for (int i = 0; i < min(len_selected_chohuku, len_unselected_only); i++) {
        cnt_type += 1;
        sum_select += unselected_only.back();
        sum_select -= selected_chohuku.back();
        unselected_only.pop_back();
        selected_chohuku.pop_back();
        long long tmp = cnt_type * cnt_type + sum_select;
        ans = max(ans, tmp);
    }
    
    cout << ans << endl;

    return 0;
}

// 
