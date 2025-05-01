#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); i++) {
        if (map.find(s[i]) == map.end()) {
            map[s[i]] = 1;
        } else {
            map[s[i]]++;
        }
    }

    bool ok = true;
    for (auto &c : map) {
        if (c.second != 2) {
            ok = false;
            break;
        }
    }

    if (ok && map.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// //End of Code
