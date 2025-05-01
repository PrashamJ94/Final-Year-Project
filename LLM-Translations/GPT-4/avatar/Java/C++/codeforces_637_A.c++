#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ara(n);
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ara[i] = v;
        if (m.find(v) == m.end()) {
            m[v] = 1;
        } else {
            m[v]++;
        }
    }

    int max = 0;
    for (auto i : m) {
        max = std::max(max, i.second);
    }

    map<int, int> mm;
    for (int i = 0; i < n; i++) {
        if (mm.find(ara[i]) == mm.end()) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl;
                break;
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl;
                break;
            }
        }
    }

    return 0;
}
// //End of Code
