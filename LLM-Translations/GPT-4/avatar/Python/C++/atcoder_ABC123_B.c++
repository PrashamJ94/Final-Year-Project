#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector< pair<int, int> > menu;
    for(int i=0; i<5; i++) {
        int m;
        cin >> m;
        int e = m % 10;
        if(e == 0)
            e = 10;
        menu.push_back(make_pair(m, e));
    }
    sort(menu.begin(), menu.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int ans = 0;
    for(int i=1; i<5; i++) {
        ans += ceil((double)menu[i].first / 10) * 10;
    }
    cout << ans + menu[0].first;
    return 0;
} // End of Code
