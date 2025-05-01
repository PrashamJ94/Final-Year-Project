#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> w;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        w[s[i]]++;
    }
    reverse(s.begin(), s.end());
    string a;
    int c = -1;
    int maxCount = max_element(w.begin(), w.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second; })->second;
    for (const auto& i : w) {
        if (i.second == maxCount) {
            int index = find(s.begin(), s.end(), i.first) - s.begin();
            if (index > c) {
                a = i.first;
                c = index;
            }
        }
    }
    cout << a << endl;

    return 0;
} // End of Code
