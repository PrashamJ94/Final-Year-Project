#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 0; i < s.length() - t.length() + 1; i++) {
        bool f = true;
        string ss = s;

        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = false;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            replace(ss.begin(), ss.end(), '?', 'a');
            ans.push_back(ss);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans[0] << endl;
    }

    return 0;
}
// 
