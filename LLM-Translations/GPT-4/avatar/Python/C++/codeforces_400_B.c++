#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> c;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        c.insert(s.find("S") - s.find("G"));
    }
    for (auto a : c) {
        if (a < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << c.size() << endl;
    return 0;
}

// End of Code.
