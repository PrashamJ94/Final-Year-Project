#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> ans(h);
    for (int i = 0; i < h; i++) {
        string temp;
        cin >> temp;
        ans[i] = "#" + temp + "#";
    }
    cout << string(w + 2, '#') << endl;
    for (const string &s : ans) {
        cout << s << endl;
    }
    cout << string(w + 2, '#') << endl;

    return 0;
}
// 
