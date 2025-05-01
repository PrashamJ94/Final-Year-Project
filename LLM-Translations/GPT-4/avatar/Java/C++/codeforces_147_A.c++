#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    string s;
    getline(cin, s);
    stringstream ss;
    int n = s.length();
    ss << s[0];

    for (int i = 1; i < n; i++) {
        char c = s[i];

        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                ss << ' ';
            }
            ss << c;
        } else if (isPunctuation(c)) {
            ss << c;
        }
    }

    cout << ss.str() << endl;
    return 0;
}

// //End of Code
