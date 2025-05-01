
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    vector<int> memo(26, 0);
    string str;

    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c : %d\n", char(i) + 'a', memo[i]);
    }

    return 0;
}


