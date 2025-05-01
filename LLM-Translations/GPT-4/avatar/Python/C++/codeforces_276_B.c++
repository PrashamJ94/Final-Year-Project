#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool x = true;
    map<char, int> dt;
    for (char i : s) {
        dt[i]++;
    }
    int cnt = 0;
    for (auto const &pair : dt) {
        if (pair.second % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (pair.second % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }
    if (x) {
        cout << "First" << endl;
    } else if (!x && s.length() % 2 == 0) {
        cout << "Second" << endl;
    } else if (!x && s.length() % 2 != 0) {
        cout << "First" << endl;
    }
    return 0;
} // End of Code
