#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

vector<int> a;
int ans = 0;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < a.size(); j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    cin >> n;
    map<char, int> dic;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char c = s[0];
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[c]++;
        }
    }

    for (auto it : dic) {
        a.push_back(it.second);
    }

    dfs(3, 0, 1);
    cout << ans << endl;

    return 0;
}
// 
