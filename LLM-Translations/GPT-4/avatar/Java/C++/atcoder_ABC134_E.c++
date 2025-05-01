#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int num;
        cin >> num;
        auto it = mp.upper_bound(-num);
        if (it != mp.end()) {
            it->second--;
            if (it->second == 0) {
                mp.erase(it);
            }
        }
        mp[-num]++;
    }
    int ans = 0;
    for (auto& p : mp) {
        ans += p.second;
    }
    cout << ans << endl;

    return 0;
}

// //End of Code.
