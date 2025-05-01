#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        map[val]++;
    }
    int max = INT_MIN;
    for(auto &entry : map) {
        max = std::max(max, entry.second);
    }
    cout << max << " " << map.size() << "\n";
    return 0;
}

// //End of Code
