#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    map<char, int> char_map;
    int oddCount = 0;

    for (int i = 0; i < str.length(); i++) {
        char ch = str.at(i);
        if (char_map.find(ch) != char_map.end()) {
            char_map[ch]++;
        } else {
            char_map[ch] = 1;
        }
    }

    for (map<char, int>::iterator it = char_map.begin(); it != char_map.end(); it++) {
        if (it->second % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2 != 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
// //End of Code
