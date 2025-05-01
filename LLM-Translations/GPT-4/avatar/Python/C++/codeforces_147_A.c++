#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<char> res;
    string punctuation = ",.!?";
    for (int i = 0; i < s.length(); i++) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (res.back() != ' ') {
                    res.push_back(s[i]);
                } else {
                    continue;
                }
            } else {
                if (punctuation.find(s[i]) != string::npos) {
                    if (res.back() == ' ') {
                        res.pop_back();
                    }
                    res.push_back(s[i]);
                    res.push_back(' ');
                } else {
                    res.push_back(s[i]);
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (punctuation.find(s[i]) != string::npos) {
                continue;
            } else {
                res.push_back(s[i]);
            }
        }
    }
    
    for (char c : res) {
        cout << c;
    }
    return 0;
} // End of Code.
