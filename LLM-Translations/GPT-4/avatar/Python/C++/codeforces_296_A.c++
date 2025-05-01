#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> m;
    string temp;
    bool possible = true;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        m[temp]++;
    }
    for(auto i : m) {
        if(i.second >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
} // End of Code.
