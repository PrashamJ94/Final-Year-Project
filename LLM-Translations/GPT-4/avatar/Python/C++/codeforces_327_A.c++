#include <bits/stdc++.h>
using namespace std;

vector<int> find(const string& s, char ch) {
    vector<int> indices;
    const int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.find('0') == string::npos) {
        cout << (n - 1);
    }
    else {
        vector<int> indices = find(s, '0');
        if(indices.size() == 1) {
            cout << n;
        }
        else {
            int maximum = 0;
            for(int i = 0; i < indices.size(); i++) {
                for(int j = i + 1; j < indices.size(); j++) {
                    maximum = max(maximum, 2 + 2 * (abs(i - j) - 1) - (abs(indices[i] - indices[j]) - 1));
                }
            }
            cout << count(s.begin(), s.end(), '1') + maximum;
        }
    }
    return 0;
}

// End of Code
